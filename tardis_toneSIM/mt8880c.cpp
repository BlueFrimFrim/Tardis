#include "mt8880c.h"

void MT8880C_T::Reset(void)
{
	delay(100);
	WriteControlRegister(B0000);
	WriteControlRegister(B0000);
	WriteControlRegister(B1100);
	WriteControlRegister(B0000);
	ReadStatusRegister();
}

uint8_t MT8880C_T::ReadStatusRegister(void)
{
	byte value = 0;
	BusMode(READ);
	digitalWrite(RW, HIGH);
	digitalWrite(RS0, HIGH);
	digitalWrite(nCS, LOW);
	value = BusRead();
	digitalWrite(nCS, HIGH);

	return value;
}

void MT8880C_T::WriteTransmitRegister(uint8_t value)
{
	BusWrite(value);
	digitalWrite(RS0,LOW);
	digitalWrite(RW, LOW);
	digitalWrite(nCS, LOW);
	digitalWrite(nCS, HIGH);
}

void MT8880C_T::WriteControlRegister(uint8_t value)
{
	BusWrite(value);
	digitalWrite(nCS, LOW);
	digitalWrite(RS0, HIGH);
	digitalWrite(RW, LOW);
	digitalWrite(nCS, HIGH);
}

void MT8880C_T::BusMode(uint8_t mode)
{
	if (mode == WRITE) {
		pinMode(D0, OUTPUT);
		pinMode(D1, OUTPUT);
		pinMode(D2, OUTPUT);
		pinMode(D3, OUTPUT);
	} else if (mode == READ) {
		pinMode(D0, INPUT);
		pinMode(D1, INPUT);
		pinMode(D2, INPUT);
		pinMode(D3, INPUT);
	}
}

uint8_t MT8880C_T::BusRead(void)
{
	uint8_t value = 0;

	BusMode(READ);
	bitWrite(value, 0, digitalRead(D0));
	bitWrite(value, 1, digitalRead(D1));
	bitWrite(value, 2, digitalRead(D2));
	bitWrite(value, 3, digitalRead(D3));

	return value;
}

void MT8880C_T::BusWrite(uint8_t value)
{
	BusMode(WRITE);
	digitalWrite(D0, bitRead(value, 0));
	digitalWrite(D1, bitRead(value, 1));
	digitalWrite(D2, bitRead(value, 2));
	digitalWrite(D3, bitRead(value, 3));

	return;
}

uint8_t MT8880C_T::ReadReceiveRegister(void)
{
	BusMode(READ);
	digitalWrite(RW, HIGH);
	digitalWrite(RS0, LOW);
	digitalWrite(nCS, LOW);

	return BusRead();
}

void MT8880C_T::PlayTone(uint8_t *value, int len)
{
	WriteControlRegister(B1011);
	WriteControlRegister(B0000);
	for (int i = 0; i < len; i++) {
		WriteTransmitRegister(value[i]);
		delay(500);
	}
}

void MT8880C_T::PlayTone(uint8_t *value, int len, int count)
{
  WriteControlRegister(B1011);
  WriteControlRegister(B0000);
  WriteTransmitRegister(value[count]);
  delay(500);
}
