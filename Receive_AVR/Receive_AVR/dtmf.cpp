#include "dtmf.h"
#include "buffer.h"

/*
 *
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

byte 
ReadStatusRegister(void)
{
	byte value = 0;
	BusMode(READ);
	digitalWrite(mt8880c->rw, HIGH);
	digitalWrite(mt8880c->rs0, HIGH);
	digitalWrite(mt8880c->not_cs, LOW);
	value = BusRead(mt8880c);
	digitalWrite(mt8880c->not_cs, HIGH);

 return value;
}

void
WriteTransmitRegister(byte value)
{
	BusWrite(mt8880c, value);
	digitalWrite(mt8880c->rs0, LOW);
	digitalWrite(mt8880c->rw, LOW);
	digitalWrite(mt8880c->not_cs, LOW);
	digitalWrite(mt8880c->not_cs, HIGH);
}

void
WriteControlRegister(t_mt8880c *mt8880c, byte value)
{
	BusWrite(mt8880c, value);
	digitalWrite(mt8880c->not_cs, LOW);
	digitalWrite(mt8880c->rs0, HIGH);
	digitalWrite(mt8880c->rw, LOW);
	digitalWrite(mt8880c->not_cs, HIGH);
}

void
BusMode(t_mt8880c *mt8880c, byte mode)
{
	if(mode == WRITE){
		pinMode(mt8880c->d0, OUTPUT);
		pinMode(mt8880c->d1, OUTPUT);
		pinMode(mt8880c->d2, OUTPUT);
		pinMode(mt8880c->d3, OUTPUT);
	}
	else if( mode == READ){
		pinMode(mt8880c->d0, INPUT);
		pinMode(mt8880c->d1, INPUT);
		pinMode(mt8880c->d2, INPUT);
		pinMode(mt8880c->d3, INPUT);
	}
}

byte
BusRead(t_mt8880c *mt8880c)
{
	byte value = 0;

	BusMode(mt8880c, READ);
	bitWrite(value, 0, digitalRead(mt8880c->d0));
	bitWrite(value, 1, digitalRead(mt8880c->d1));
	bitWrite(value, 2, digitalRead(mt8880c->d2));
	bitWrite(value, 3, digitalRead(mt8880c->d3));

	return value;
}

void
BusWrite(t_mt8880c *mt8880c, byte value)
{
	BusMode(mt8880c, WRITE);
	digitalWrite(mt8880c->d0, bitRead(value, 0));
	digitalWrite(mt8880c->d1, bitRead(value, 1));
	digitalWrite(mt8880c->d2, bitRead(value, 2));
	digitalWrite(mt8880c->d3, bitRead(value, 3));

	return;
}

byte
ReadReceiveRegister(void)
{
  byte tone_rx = 0;

  BusMode(mt8880c, READ);
  digitalWrite(mt8880c->rw, HIGH);
  digitalWrite(mt8880c->rs0, LOW);
  digitalWrite(mt8880c->not_cs, LOW);
  tone_rx = BusRead(mt8880c);

  return tone_rx;
}

void
PlayTone(t_mt8880c *mt8880c ,byte *value, int len)
{
	WriteControlRegister(mt8880c, B1011);
	WriteControlRegister(mt8880c, B0000);
	for(int i = 0; i < len; i++){
		WriteTransmitRegister(mt8880c, value[i]);
		delay(500);
	}
}
