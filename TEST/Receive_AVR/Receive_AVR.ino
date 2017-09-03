/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/


//#include "tardis.h"
#include <Wire.h>
#include <Adafruit_FONA.h>
#include <SPI.h>
#include <MCP23S17.h>



#define DBG_MSG 1

#define READ 1
#define WRITE 0

volatile unsigned long g_last_irq, g_current_irq = 0;

unsigned long five_minutes = 5 * 1000;

//Timeout_t dtmf_timer = Timeout_t(five_minutes);

volatile unsigned long irq_time = 0;

const unsigned long timeout_10s = 10000; 



/* dtmf */
const uint8_t not_irq = 2;
const uint8_t d0 = 3;
const uint8_t d1 = 4;
const uint8_t d2 = 5;
const uint8_t d3 = 6;
const uint8_t rs0 = 7;
const uint8_t rw = 8;
const uint8_t not_cs = 9;

volatile uint64_t tx_cmd = 0;
volatile uint8_t irq_event = 0;

/* fona */
#include <SoftwareSerial.h>


const uint8_t FONA_RST = 11;
const uint8_t FONA_RX = 12;
const uint8_t FONA_TX = 13;

char Cell_Keegan[] = "4032002497";
char Cell_Bruce[] = "4038162797";

uint8_t type;

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;
Adafruit_FONA_3G fona = Adafruit_FONA_3G(FONA_RST);

/* general */
uint8_t enable_5s = 0;
uint8_t enable_3m = 0;
volatile unsigned long global_time = 0;
volatile unsigned long cell_time = 0;
uint8_t i = 1;

void IRQ_ToneReceived(void)
{	
	unsigned long time_now = millis();

	if (time_now - irq_time > 100) {
    enable_5s = 1;
    global_time = millis();
		irq_time = time_now;
#if DBG_MSG  
    Serial.println(F(".IRQ EVENT -> TRIGGERED"));
#endif		
    irq_event = 1;
	}
}

void setup() {
#if DBG_MSG
	while(!Serial);
	Serial.begin(9600); /* Serial communication */
	Serial.println(F("TARDIS.LOADING SYSTEM"));
#endif	 

	BusMode(WRITE);
	pinMode(not_irq, INPUT);
	pinMode(rs0, OUTPUT);
	pinMode(not_cs, OUTPUT);
	pinMode(rw, OUTPUT);
	Reset();
#if DBG_MSG
	Serial.println(F("\t.MT8880C -> INITIALIZED"));
#endif

	fonaSerial->begin(115200);
  uint8_t flg = 1;
  while(flg){
  	if(fona.begin(*fonaSerial)){
        flg = 0;
  	} else{
#if DBG_MSG
      Serial.println(F("\t.FONA -> NOT FOUND. RESET SYSTEM"));
#endif
  	}
  }
	type = fona.type();
#if DBG_MSG
	Serial.println(F("\t.FONA -> FOUND FONA 3G (American)"));
#endif
	fona.sendCheckReply(F("ATZ"), F("OK"));
	fona.setVolume(100);
	fona.sendCheckReply(F("AT+CSDVC=3,1"), F("OK"));
	fona.sendCheckReply(F("ATS0=003"), F("OK"));
	char imei[15] = {0};
	uint8_t imeiLen = fona.getIMEI(imei);
	if(imeiLen > 0){
#if DBG_MSG
		Serial.print(F("Module IMEI: ")); 
		Serial.println(imei);
#endif
	}

	ReadStatusRegister();
	delay(250);
#if DBG_MSG
	Serial.println(F("\t.SYSTEM LOADING COMPLETE"));
#endif
  pinMode(10, OUTPUT);    
  digitalWrite(10, HIGH);
	attachInterrupt(digitalPinToInterrupt(not_irq), IRQ_ToneReceived, CHANGE);
}

void loop() {
	uint8_t tone_in = 0;
  Timeout_5s(global_time);
  Timeout_30m(cell_time);
	if (irq_event) {
    noInterrupts();
    irq_event = 0;
    tone_in = ReadReceiveRegister();
#if DBG_MSG
		Serial.print(F("TARDIS.TONE RECEIVED -> "));
		Serial.println(tone_in);
#endif
		ProcessTone(tone_in);
		ReadStatusRegister();
		interrupts();
	}
}


void ProcessTone(uint8_t data)
{
	uint8_t rx_tone = data;
	if(rx_tone == 10){
		rx_tone = 0;
	} else if(rx_tone == 11){
		tx_cmd = rx_tone;
		return;
	} else if(rx_tone == 12){
		if(tx_cmd == 11){
			return;
		} else{
			ExecuteCommand(tx_cmd);
      enable_5s = 0;
      tx_cmd = 0;
		}
	}
  tx_cmd = Concatenate(tx_cmd, rx_tone); 
	return;
}

void ExecuteCommand(uint64_t cmd)
{
	switch (cmd) {
	case 11123:
		Serial.println(F("\t.TRANSMITTING *123# -> Calling Keegan"));
		fona.callPhone(Cell_Keegan);
    cell_time = millis();
    enable_3m = 1;
		delay(100);
		break;
	case 11456:
		Serial.println(F("\t.TRANSMITTING *456# -> Calling Bruce"));
		fona.callPhone(Cell_Bruce);
    cell_time = millis();
    enable_3m = 1;
		delay(100);
		break;
	case 1122:
		Serial.println(F("\t.TRANSMITTING *22# -> Answering"));
        if (!fona.pickUp()) {
			    Serial.println(F("\t.CALL -> FAILED"));
		  } else {
          cell_time = millis();
          enable_3m = 1;
			    Serial.println(F("\t.CALL -> SUCCESS"));
		  }
		delay(100);
		break;
	case 1111:
		Serial.println(F("\t.TRANSMITTING *11# -> Hanging Up"));
    fona.sendCheckReply(F("AT+CVHU=0"), F("OK"));  
    fona.sendCheckReply(F("ATH"), F("OK")); 
    enable_3m = 0; 
		delay(100);
		break;
	default:
		Serial.println(F("\t.ERROR -> NOT A COMMAND"));
		delay(100);
		break;
	}
}


/*
 *	DTMF Functions
 */
 void Reset(void)
 {
	 delay(100);
	 WriteControlRegister(B0000);
	 WriteControlRegister(B0000);
	 WriteControlRegister(B1100);
	 WriteControlRegister(B0000);
	 ReadStatusRegister();
 }
 
 uint8_t ReadStatusRegister(void)
 {
	 byte value = 0;
	 BusMode(READ);
	 digitalWrite(rw, HIGH);
	 digitalWrite(rs0, HIGH);
	 digitalWrite(not_cs, LOW);
	 value = BusRead();
	 digitalWrite(not_cs, HIGH);
 
  return value;
 }
 
 void WriteTransmitRegister(uint8_t value)
 {
	 BusWrite(value);
	 digitalWrite(rs0, LOW);
	 digitalWrite(rw, LOW);
	 digitalWrite(not_cs, LOW);
	 digitalWrite(not_cs, HIGH);
 }
 
 void WriteControlRegister(uint8_t value)
 {
	 BusWrite(value);
	 digitalWrite(not_cs, LOW);
   delay(500);
	 digitalWrite(rs0, HIGH);
   delay(500);
	 digitalWrite(rw, LOW);
   delay(500);
	 digitalWrite(not_cs, HIGH);
   delay(500);
 }
 
 void BusMode(uint8_t mode)
 {
	 if(mode == WRITE){
		 pinMode(d0, OUTPUT);
		 pinMode(d1, OUTPUT);
		 pinMode(d2, OUTPUT);
		 pinMode(d3, OUTPUT);
	 }
	 else if( mode == READ){
		 pinMode(d0, INPUT);
		 pinMode(d1, INPUT);
		 pinMode(d2, INPUT);
		 pinMode(d3, INPUT);
	 }
 }
 
 uint8_t BusRead(void)
 {
	 uint8_t value = 0;
 
	 BusMode(READ);
	 bitWrite(value, 0, digitalRead(d0));
	 bitWrite(value, 1, digitalRead(d1));
	 bitWrite(value, 2, digitalRead(d2));
	 bitWrite(value, 3, digitalRead(d3));
 
	 return value;
 }
 
 void BusWrite(uint8_t value)
 {
	 BusMode(WRITE);
	 digitalWrite(d0, bitRead(value, 0));
	 digitalWrite(d1, bitRead(value, 1));
	 digitalWrite(d2, bitRead(value, 2));
	 digitalWrite(d3, bitRead(value, 3)); 
	 return;
 }
 
 uint8_t ReadReceiveRegister(void)
 { 
   BusMode(READ);
   digitalWrite(rw, HIGH);
   digitalWrite(rs0, LOW);
   digitalWrite(not_cs, LOW);
 
   return BusRead();
 }
 
 void PlayTone(uint8_t *value, int len)
 {
	 WriteControlRegister(B1011);
	 WriteControlRegister(B0000);
	 for(int i = 0; i < len; i++){
		 WriteTransmitRegister(value[i]);
		 delay(500);
	 }
 }

 /*
  * UTILITY
  */
unsigned Concatenate(unsigned x, unsigned y)
{
  return x * pow(10, (int)log10(y) + 1) + y;
}

void Timeout_5s(unsigned long time_in)
{
  unsigned long time_now = millis();
  unsigned long elapsed = time_now - time_in;
  if(enable_5s){
    if(elapsed > 5000){
        Serial.println(F("5 seconds has passed"));
        tx_cmd = 0;
        enable_5s = 0;
    }
  }
}

void Timeout_30m(unsigned long time_in)
{
  unsigned long time_now = millis();
  unsigned long elapsed = time_now - time_in;
  if(enable_3m){
    if(elapsed > 1800000){
      i = 0;
      enable_3m = 0;
      fona.sendCheckReply(F("AT+CVHU=0"), F("OK"));  
      fona.sendCheckReply(F("ATH"), F("OK"));  
      Serial.println(F("30m passed."));
      delay(100);
    }
  }
}





