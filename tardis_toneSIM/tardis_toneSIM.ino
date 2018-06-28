#include "tardis.h"

// #define DBG_MSG

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

byte tone_test[] = {star, two, three, four, five, six, seven, eight, hash};
byte tone_clear[] = {0};
byte tone_sequence0[] = {star, one, two, three, hash};
byte tone_sequence1[] = {star, four, five, six, hash};
byte tone_sequence2[] = {star, two, two, hash};
byte tone_sequence3[] = {star, one, one, hash};

MT8880C_T sim;
int count = 0;

void PrintMenu(void)
{
  Serial.println("\t.PLEASE SELECT TONE");
  Serial.println("\t.[0] *123# -> Call Keegan");
  Serial.println("\t.[1] *456# -> Call Bruce");
  Serial.println("\t.[2] *22# -> Answer");
  Serial.println("\t.[3] *11# -> Hang Up");
  Serial.println("\t.[h] PRINT MENU");
}

void setup(void)
{
  sim.D3 = 3;
  sim.D2 = 4;
  sim.D1 = 5;
  sim.D0 = 6;
  sim.nIRQ = 12;
  sim.RS0 = 7;
  sim.RW = 10;
  sim.nCS = 11;

  sim.Reset();
	pinMode(sim.nIRQ, INPUT);
	pinMode(sim.RS0, OUTPUT);
	pinMode(sim.nCS, OUTPUT);
	pinMode(sim.RW, OUTPUT);
  delay(100);
  sim.ReadStatusRegister();
}

void loop(void)
{
  if(digitalRead(9)){
    //sim.PlayTone(tone_test, sizeof(tone_test));
    sim.PlayTone(tone_test, sizeof(tone_test), count);
    count++;
    if(count == 8){count = 0;}
    //sim.PlayTone(tone_clear, sizeof(tone_clear));
  }
}






