#include "dtmf.h"
#if 0
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
  uint8_t rx_tone = 0;

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
#endif