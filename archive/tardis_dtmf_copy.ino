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

void print_received(void);
void play_tone(byte value, int length);

void simulate(void);


const byte WRITE = 0;
const byte READ = 1;

byte status_register = 0;

int interrupt = 0;
int interrupt2 = 0;

byte tone_test[] = {star, one, two, three, four, hash};
byte tone_clear[] = {0};

byte tone_received = 0;
byte tones_rx[7] = {0};
int tone_position = 0;
char train_code = 0;

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
  memset(tones_rx, 0, sizeof(tones_rx));
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
  int value = 0;
  Serial.println("No detection...");
  delay(500);
  if(interrupt){
    interrupt = 0;
    for(int i = 0; i<6; i++){
      value = concatenate(tones_rx[i], tones_rx[i+1]);

    }
    Serial.print("tones_rx: ");
    Serial.println(value);
    if(tones_rx[6] == hash){

    }
  }
}
#endif /* RECEIVE_TONE (i2c Master) */

void print_received(void)
{
    interrupt_time = millis();
    if(interrupt_time - last_interrupt > 100){
      Serial.println("Interrupt...");
      interrupt = 1;
      read_receive_register();
      if(tone_received == star){
        tone_position = 0;
      }
      tones_rx[tone_position] = tone_received;
      tone_position++;
      if(tone_position == 7){tone_position = 0;}
      last_interrupt = interrupt_time;
      status_register_read();
    }
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


