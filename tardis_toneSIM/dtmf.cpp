#include "dtmf.h"

void 
Reset(void)
{
	delay(100);
	WriteControlRegister(B0000);
	WriteControlRegister(B0000);
	WriteControlRegister(B1100);
	WriteControlRegister(B0000);
	ReadStatusRegister();
}

byte 
ReadStatusRegister(void)
{
	byte value = 0;
	BusMode(READ);
	digitalWrite(RW, HIGH);
	digitalWrite(RS0, HIGH);
	digitalWrite(CS_NOT, LOW);
	value = BusRead();
	digitalWrite(CS_NOT, HIGH);

 return value;
}

void
WriteTransmitRegister(byte value)
{
	BusWrite(value);
	digitalWrite(RS0, LOW);
	digitalWrite(RW, LOW);
	digitalWrite(CS_NOT, LOW);
	digitalWrite(CS_NOT, HIGH);

	return;
}

void
WriteControlRegister(byte value)
{
	BusWrite(value);
  digitalWrite(CS_NOT, LOW);
	digitalWrite(RS0, HIGH);
	digitalWrite(RW, LOW);
	digitalWrite(CS_NOT, HIGH);

	return;
}

void
BusMode(byte mode)
{
	if(mode == WRITE){
		pinMode(D0, OUTPUT);
		pinMode(D1, OUTPUT);
		pinMode(D2, OUTPUT);
		pinMode(D3, OUTPUT);
	}
	else if( mode == READ){
		pinMode(D0, INPUT);
		pinMode(D1, INPUT);
		pinMode(D2, INPUT);
		pinMode(D3, INPUT);
	}
	return;
}

byte
BusRead(void)
{
	BusMode(READ);
	byte value = 0;
	bitWrite(value, 0, digitalRead(D0));
	bitWrite(value, 1, digitalRead(D1));
	bitWrite(value, 2, digitalRead(D2));
	bitWrite(value, 3, digitalRead(D3));

	return value;
}

void
BusWrite(byte value)
{
	BusMode(WRITE);
	digitalWrite(D0, bitRead(value, 0));
	digitalWrite(D1, bitRead(value, 1));
	digitalWrite(D2, bitRead(value, 2));
	digitalWrite(D3, bitRead(value, 3));

	return;
}

byte
ReadReceiveRegister(void)
{
  byte tone_rx;
  BusMode(READ);
  digitalWrite(RW, HIGH);
  digitalWrite(RS0, LOW);
  digitalWrite(CS_NOT, LOW);
  tone_rx = BusRead();

  return tone_rx;
}

void
PlayTone(byte *value, int len)
{
	WriteControlRegister(B1011);
	WriteControlRegister(B0000);
	for(int i = 0; i < len; i++){
		WriteTransmitRegister(value[i]);
		delay(20000);
	}
}
