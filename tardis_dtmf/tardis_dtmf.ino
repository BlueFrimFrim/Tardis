#include "Arduino.h"

static const byte one = 1;
static const byte two = 2;
static const byte three = 3;
static const byte four = 4;
static const byte five = 5;
static const byte six = 6;
static const byte seven = 7;
static const byte eight = 8;
static const byte nine = 9;
static const byte zero = 10;
static const byte star = 11;
static const byte hash = 12;
static const byte A = 13;
static const byte B = 14;
static const byte C = 15;
static const byte D = 0;

const byte D0 = 3;
const byte D1 = 4;
const byte D2 = 5;
const byte D3 = 6;
const byte IRQ_NOT = 7;
const byte RS0 = 8;
const byte RW = 9;
const byte CS_NOT = 10;
const byte DHT_IN = 11;
const byte SW = 12;

void reset(void);
byte status_register_read(void);
void transmit_register_write(byte value);
void control_register_write(byte value);
void bus_mode(byte mode);
void bus_write(byte value);
void play_tone(byte value, int length);

byte bus_read(void);

const byte WRITE = 0;
const byte READ = 1;

byte tone_test[] = {one, two, three, four, five, six, seven, eight, nine,
                    zero, star, hash};

void setup(void)
{
  reset();
	bus_mode(WRITE);
	pinMode(SW, INPUT);
	pinMode(IRQ_NOT, INPUT);
	pinMode(RS0, OUTPUT);
	pinMode(CS_NOT, OUTPUT);
	pinMode(RW, OUTPUT);

	Serial.begin(115200);
}

void loop(void)
{
  play_tone(tone_test, sizeof(tone_test));
  delay(1000);
}

void reset(void)
{
	delay(100);
	control_register_write(B0000);
	control_register_write(B0000);
	control_register_write(B1000);
	control_register_write(B0000);
	status_register_read();
}

byte status_register_read(void)
{
	byte value = 0;
	bus_mode(READ);
	digitalWrite(RW, HIGH);
	digitalWrite(RS0, HIGH);
	digitalWrite(CS_NOT, LOW);
	value = bus_read();
	digitalWrite(CS_NOT, HIGH);

	return value;
}

void transmit_register_write(byte value)
{
	bus_write(value);
 // delay(5);
	digitalWrite(RS0, LOW);
	digitalWrite(RW, LOW);
	digitalWrite(CS_NOT, LOW);
	digitalWrite(CS_NOT, HIGH);

	return;
}

void control_register_write(byte value)
{
	bus_write(value);
	digitalWrite(RS0, HIGH);
	digitalWrite(RW, LOW);
	digitalWrite(CS_NOT, LOW);
	digitalWrite(CS_NOT, HIGH);

	return;
}

void bus_mode(byte mode)
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

byte bus_read(void)
{
	bus_mode(READ);
	byte value = 0;
	bitWrite(value, 0, digitalRead(D0));
	bitWrite(value, 1, digitalRead(D1));
	bitWrite(value, 2, digitalRead(D2));
	bitWrite(value, 3, digitalRead(D3));

	return value;
}

void bus_write(byte value)
{
	bus_mode(WRITE);
	digitalWrite(D0, bitRead(value, 0));
	digitalWrite(D1, bitRead(value, 1));
	digitalWrite(D2, bitRead(value, 2));
	digitalWrite(D3, bitRead(value, 3));

	return;
}

#define TEST

void play_tone(byte *value, int len)
{
	control_register_write(B1101);
	control_register_write(B0000);
	for(int i = 0; i < len; i++){
		transmit_register_write(value[i]);
		delay(175);
	while(digitalRead(IRQ_NOT) == HIGH){
			delay (1);
		}
	}
}






