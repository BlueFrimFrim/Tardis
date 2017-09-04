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
const uint8_t d0 = 2;
const uint8_t d1 = 3;
const uint8_t d2 = 4;
const uint8_t d3 = 5;
const uint8_t rs0 = 6;
const uint8_t rw = 7;
const uint8_t not_cs = 8;

volatile uint64_t tx_cmd = 0;
volatile uint8_t irq_event = 0;

/* fona */
#include <SoftwareSerial.h>


const uint8_t FONA_RST = 110; /* 11 */
const uint8_t FONA_RX = 120; /* 12 */
const uint8_t FONA_TX = 130; /* 13 */

char Cell_Keegan[] = "4032002497";
char Cell_Bruce[] = "4038162797";

uint8_t type;

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;
Adafruit_FONA_3G fona = Adafruit_FONA_3G(FONA_RST);

/* msp23s17 */
MCP ioexp_1(0, 10); /* io expander with address 0, slave select pin 10 */

/* general */
uint8_t enable_5s = 0;
uint8_t enable_3m = 0;
volatile unsigned long global_time = 0;
volatile unsigned long cell_time = 0;
uint8_t i = 1;
uint8_t foo = 1;

void IRQ_ToneReceived(void)
{	
	unsigned long time_now = millis();

	if (time_now - irq_time > 100) {
    enable_5s = 1;
    global_time = millis();
		irq_time = time_now;
//    dbg_print(".IRQ EVENT -> TRIGGERED\r\n");
    irq_event = 1;
	}
}


void setup() {
  /* Comment out next two lines if not connecting serial */
	while(!Serial);
	Serial.begin(9600);
  dbg_print("TARDIS.LOADING SYSTEM\r\n");

  ioexp_1.begin();
  delay(250);
	BusMode(WRITE);
	pinMode(not_irq, INPUT);
	ioexp_1.pinMode(rs0, LOW);
	ioexp_1.pinMode(not_cs, LOW);
	ioexp_1.pinMode(rw, LOW);
	Reset();
#if DBG_MSG
	Serial.println(F("\t.MT8880C -> INITIALIZED"));
#endif
#if 0
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
#endif

	ReadStatusRegister();
  delay(250);
#if DBG_MSG
	Serial.println(F("\t.SYSTEM LOADING COMPLETE"));
#endif
	attachInterrupt(digitalPinToInterrupt(not_irq), IRQ_ToneReceived, CHANGE); /* or change */
}

void loop() {
	uint8_t tone_in = 0;
  Timeout_5s(global_time);
  Timeout_30m(cell_time);
	if (irq_event) {
    noInterrupts();
    irq_event = 0;
    tone_in = ReadReceiveRegister();
		Serial.print(F("TARDIS.TONE RECEIVED -> "));
		Serial.println(tone_in);
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
	 BusMode(READ);
	 ioexp_1.digitalWrite(rw, HIGH);
	 ioexp_1.digitalWrite(rs0, HIGH);
	 ioexp_1.digitalWrite(not_cs, LOW);
	 ioexp_1.digitalWrite(not_cs, HIGH);
 
  return BusRead();
 }
 
 void WriteTransmitRegister(uint8_t value)
 {
	 BusWrite(value);
	 ioexp_1.digitalWrite(rs0, LOW);
	 ioexp_1.digitalWrite(rw, LOW);
	 ioexp_1.digitalWrite(not_cs, LOW);
	 ioexp_1.digitalWrite(not_cs, HIGH);
 }
 
 void WriteControlRegister(uint8_t value)
 {
	 BusWrite(value);
	 ioexp_1.digitalWrite(not_cs, LOW);
	 ioexp_1.digitalWrite(rs0, HIGH);
	 ioexp_1.digitalWrite(rw, LOW);
	 ioexp_1.digitalWrite(not_cs, HIGH);
 }
 
 void BusMode(uint8_t mode)
 {
	 if(mode == WRITE){
		 ioexp_1.pinMode(d0, LOW);
		 ioexp_1.pinMode(d1, LOW);
		 ioexp_1.pinMode(d2, LOW);
		 ioexp_1.pinMode(d3, LOW);
	 }
	 else if( mode == READ){
		 ioexp_1.pinMode(d0, HIGH);
		 ioexp_1.pinMode(d1, HIGH);
		 ioexp_1.pinMode(d2, HIGH);
		 ioexp_1.pinMode(d3, HIGH);
	 }
 }
 
 uint8_t BusRead(void)
 {
	 uint8_t value = 0;
   
	 BusMode(READ);
   bitWrite(value, 0, ioexp_1.digitalRead(d0));
   bitWrite(value, 1, ioexp_1.digitalRead(d1));
   bitWrite(value, 2, ioexp_1.digitalRead(d2));
   bitWrite(value, 3, ioexp_1.digitalRead(d3));

	 return value;
 }
 
 void BusWrite(uint8_t value)
 {
	 BusMode(WRITE);
	 ioexp_1.digitalWrite(d0, bitRead(value, 0));
	 ioexp_1.digitalWrite(d1, bitRead(value, 1));
	 ioexp_1.digitalWrite(d2, bitRead(value, 2));
	 ioexp_1.digitalWrite(d3, bitRead(value, 3)); 
	 return;
 }
 
 uint8_t ReadReceiveRegister(void)
 { 
   BusMode(READ);
   ioexp_1.digitalWrite(rw, HIGH);
   ioexp_1.digitalWrite(rs0, LOW);
   ioexp_1.digitalWrite(not_cs, LOW);
   return BusRead();
 }

 /*
  * UTILITY
  */
void dbg_print(char *msg)
{
#if DBG_MSG
  Serial.print(msg);
#endif
}

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
        foo = 0;
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





