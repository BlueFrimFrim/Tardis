#include "Arduino.h"
#include <Wire.h>

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
const byte IRQ_NOT = 2;
const byte RS0 = 8;
const byte RW = 9;
const byte CS_NOT = 10;
const byte DHT_IN = 11;
const byte SW = 12;

void reset(void);
byte status_register_read(void);
byte read_receive_register(void);
void transmit_register_write(byte value);
void control_register_write(byte value);
void bus_mode(byte mode);
void bus_write(byte value);
void print_received(void);
void play_tone(byte value, int length);

void simulate(void);

byte bus_read(void);

const byte WRITE = 0;
const byte READ = 1;

byte status_register = 0;

int interrupt = 0;
int interrupt2 = 0;

byte tone_test[] = {star, one, two, three, four, hash};
byte tone_clear[] = {0};

byte tone_received = 0;

unsigned long interrupt_time = 0;
unsigned long last_interrupt = 0;

unsigned long interrupt_time2 = 0;
unsigned long last_interrupt2 = 0;

int timer = 0;

/* 
 *  
 *  
 *  TONE GENERATION 
 *
 *
 */
#if 0 /* REGENERATE_TONE */
void setup(void)
{
  reset();
	bus_mode(WRITE);
	pinMode(SW, INPUT);
	pinMode(IRQ_NOT, INPUT);
	pinMode(RS0, OUTPUT);
	pinMode(CS_NOT, OUTPUT);
	pinMode(RW, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(IRQ_NOT), simulate, CHANGE); /* READ STATUS REGISTER TO CLEAR INTERRUPT */
  delay(1500);
}

void loop(void)
{
  if(interrupt == 1){
    play_tone(tone_test, sizeof(tone_test));
    interrupt = 0;
    play_tone(tone_clear, sizeof(tone_clear));
  }
}
#endif /* REGENERATE_TONE */

#if 1 /* RECEIVE_TONE (i2c Master) */

void test(void)
{
  Serial.println("test");
  status_register_read(); 
}
/* 
 *  
 *  
 *  TONE DETECTION 
 *
 *
 */
void setup(void)
{
  Serial.begin(9600);
  bus_mode(WRITE);
  pinMode(IRQ_NOT, INPUT);
  pinMode(RS0, OUTPUT);
  pinMode(CS_NOT, OUTPUT);
  pinMode(RW, OUTPUT);
  reset();
  while(!Serial);
  Serial.print(F("Begin transmission...\r\n"));
  attachInterrupt(digitalPinToInterrupt(IRQ_NOT), print_received, CHANGE); /* READ STATUS REGISTER TO CLEAR INTERRUPT */
  delay(100);

  Wire.begin(); /* i2c communication */
}

void loop(void)
{
  Wire.beginTransmission(7);
  Serial.println(F("Begin transmission (7)"));
  delay(1);
  Serial.println(F("Printing..."));
  Wire.write(tone_received);
  Serial.println(F("Print completed"));
  delay(1);
  Wire.endTransmission();
  Serial.println(F("Transmission ended"));
  delay(1000);
}
#endif /* RECEIVE_TONE (i2c Master) */

void reset(void)
{
	delay(100);
	control_register_write(B0000);
	control_register_write(B0000);
	control_register_write(B1100);
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
	digitalWrite(RS0, LOW);
	digitalWrite(RW, LOW);
	digitalWrite(CS_NOT, LOW);
	digitalWrite(CS_NOT, HIGH);

	return;
}

void control_register_write(byte value)
{
	bus_write(value);
  digitalWrite(CS_NOT, LOW);
	digitalWrite(RS0, HIGH);
	digitalWrite(RW, LOW);
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

byte read_receive_register(void)
{
  bus_mode(READ);
  digitalWrite(RW, HIGH);
  digitalWrite(RS0, LOW);
  digitalWrite(CS_NOT, LOW);
  tone_received = bus_read();

  return tone_received;
}

void print_received(void)
{
    interrupt_time = millis();
    if(interrupt_time - last_interrupt > 100)
    {
      read_receive_register();
      last_interrupt = interrupt_time;
    
    }
    status_register_read();
}

void play_tone(byte *value, int len)
{
	control_register_write(B1011);
	control_register_write(B0000);
	for(int i = 0; i < len; i++){
		transmit_register_write(value[i]);
		delay(500);
	}
}

void simulate(void)
{
  interrupt_time2 = millis();
  if(interrupt_time2 - last_interrupt2 > 250)
  {
    interrupt = 1;
    last_interrupt2 = interrupt_time2;
  }
}






