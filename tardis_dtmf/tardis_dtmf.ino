#include "Arduino.h"

#define RECEIVE_TONE

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

byte bus_read(void);

const byte WRITE = 0;
const byte READ = 1;

byte status_register = 0;

int interrupt = 0;

byte tone_test[] = {one, two, three, four, five, six, seven, eight, nine,
                    zero, star, hash};

byte tone_received = 0;

unsigned long interrupt_time = 0;
unsigned long last_interrupt = 0;

#if 0
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
#endif /* REGENERATE_TONE */

#if 1

void test(void)
{
  Serial.println("test");
  status_register_read(); 
}

void setup(void)
{
  Serial.begin(115200);
  Serial.println();
  bus_mode(WRITE);
  pinMode(IRQ_NOT, INPUT);
  pinMode(RS0, OUTPUT);
  pinMode(CS_NOT, OUTPUT);
  pinMode(RW, OUTPUT);
  reset();
  Serial.print(F("Begin transmission...\r\n"));
  attachInterrupt(digitalPinToInterrupt(IRQ_NOT), print_received, CHANGE); /* READ STATUS REGISTER TO CLEAR INTERRUPT */
  delay(5000);
}

void loop(void)
{
  //read_receive_register();
}
#endif /* RECEIVE_TONE */

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
  if(interrupt_time - last_interrupt > 250)
  {
    read_receive_register();
    Serial.println(tone_received);
    /*
    switch(tone_received){
      case 1:
        Serial.println("1");
        break;
      case 2:
        Serial.println("2");
        break;
      case 3:
        Serial.println("3");
        break;
      case 4:
        Serial.println("4");
        break;
      case 5:
        Serial.println("5");
        break;
      case 6:
        Serial.println("6");
        break;
      case 7:
        Serial.println("7");
        break;
      case 8:
        Serial.println("8");
        break;
      case 9:
        Serial.println("9");
        break;
      case 10:
        Serial.println("0");
        break;
      case 11:
        Serial.println("*");
        break;
      case 12:
        Serial.println("#");
        break;    
      case 13:
        Serial.println("A");
        break;
      case 14:
        Serial.println("B");
        break;
      case 15:
        Serial.println("C");
        break;
      case 0:
        Serial.println("D");
        break;              
      default:
        break;
    }
    */
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
		delay(1000);
	}
}






