/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/


//#include "tardis.h"
#include <Wire.h>

#define READ 1
#define WRITE 0

volatile unsigned long g_last_irq, g_current_irq = 0;

unsigned long five_minutes = 5 * 1000;

//Timeout_t dtmf_timer = Timeout_t(five_minutes);

volatile unsigned long irq_time = 0;

const unsigned long timeout_10s = 10000; 

volatile uint64_t tx_cmd = 0;
volatile uint8_t irq_event = 0;

const uint8_t not_irq = 2;
const uint8_t d0 = 3;
const uint8_t d1 = 4;
const uint8_t d2 = 5;
const uint8_t d3 = 6;
const uint8_t rs0 = 7;
const uint8_t rw = 8;
const uint8_t not_cs = 9;

void IRQ_ToneReceived(void)
{	
	unsigned long time_now = millis();	

	if (time_now - irq_time > 100) {
		irq_event = 1;
		//dtmf_timer.set_timeout();
		irq_time = time_now;
	}
}


void setup() {
	BusMode(WRITE);
	pinMode(not_irq, INPUT);
	pinMode(rs0, OUTPUT);
	pinMode(not_cs, OUTPUT);
	pinMode(rw, OUTPUT);
	Reset();
	delay(100);

	attachInterrupt(digitalPinToInterrupt(not_irq), IRQ_ToneReceived, CHANGE);

	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */
	while (!Serial);
	Serial.println("TARDIS.LOADING SYSTEM");
	ReadStatusRegister();
}

void loop() {
	uint8_t tone_in = 0;
//	int counter = 0;

#if 1

#if 0
	if (dtmf_timer.status()) {
		if (dtmf_timer.check()) {
			BufferReset(&tone_buff);
			dtmf_timer.clear_timeout();
		}
	}
#endif
	if (irq_event) {
		irq_event = 0;
		tone_in = ReadReceiveRegister();
		Serial.print("tone_in: ");
		Serial.println(tone_in);
		ProcessTone(tone_in);
		ReadStatusRegister(); /* Clear interrupt register. */		
//		dtmf_timer.clear_timeout();
		Serial.println(F("\t.IRQ EVENT -> TRIGGERED"));
	}
#endif

#if 0
		if (temp == 0) {
				temp = 1;
				Serial.print(F("temp = "));
				Serial.println(temp);
		}

		if (temp == 1) {
			start = millis();
			temp = 2;
			Serial.print(F("temp = "));
			Serial.print(temp);
			Serial.print(F(" | start = "));
			Serial.println(start);
		}
		unsigned long now;
		unsigned long timeout = 300000;
		if (temp == 2) {
			now = millis();
		}
		unsigned long elapsed = now - start;
		Serial.print(F("elapsed = "));
		Serial.println(elapsed);
		if (elapsed >= timeout)
		{
			temp = 3;
			Serial.println(F("5 minutes has occured."));
			while (1) { ; }
		}
		if (timer_status) {
			Serial.print(F("Timer Status:"));
			Serial.println(timer_status);
			Serial.println((millis()));
			if (dtmf_timer.check()) {
				//BufferReset(&tone_buff);
				Serial.println(F("Timeout1: Resetting..."));
				dtmf_timer.clear_flg();
			}
		}
#endif
}

void ProcessTone(uint8_t data)
{
	uint8_t rx_tone = data;
	if(rx_tone == 10){
		rx_tone = 0;
	} else if(rx_tone == 11){
		tx_cmd = rx_tone;
		return;
	} else if(tx_cmd == 12){
		if(tx_cmd == 11){
			return;
		} else{
			ExecuteCommand(tx_cmd);
			return;
		}
	}
	tx_cmd = Concatenate(tx_cmd, rx_tone);
	return;
}

void ExecuteCommand(uint64_t cmd)
{
	switch (cmd) {
	case 11123:
		Serial.println("\t.TRANSMITTING *123# -> Calling Keegan");
		Wire.beginTransmission(7);
		Wire.write(0x01);
		Wire.endTransmission();
		delay(100);
		break;
	case 11246:
		Serial.println("\t.TRANSMITTING *456# -> Calling Bruce");
		Wire.beginTransmission(7);
		Wire.write(0x05);
		Wire.endTransmission();
		delay(100);
		break;
	case 11789:
		Serial.println("\t.TRANSMITTING *789# -> Answering");
		Wire.beginTransmission(7);
		Wire.write(0x10);
		Wire.endTransmission();
		delay(100);
		break;
	case 1111:
		Serial.println("\t.TRANSMITTING *11# -> Hanging Up");
		Wire.beginTransmission(7);
		Wire.write(0x15);
		Wire.endTransmission();
		delay(100);
		break;
	default:
		Serial.println("command default sending...");
		Wire.beginTransmission(7);
		Wire.write(0x00);
		Wire.endTransmission();
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
	 digitalWrite(rs0, HIGH);
	 digitalWrite(rw, LOW);
	 digitalWrite(not_cs, HIGH);
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
