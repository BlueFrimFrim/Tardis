

#include "tardis.h"

#define DBG_MSG 0


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

byte tone_test[] = {star, one, two, three, hash};
byte tone_clear[] = {0};
byte tone_sequence0[] = {star, one, two, three, hash};
byte tone_sequence1[] = {star, four, five, six, hash};
byte tone_sequence2[] = {star, seven, eight, nine, hash};
byte tone_sequence3[] = {star, one, one, hash};


void PrintMenu(void)
{
  Serial.println("\t.PLEASE SELECT TONE");
  Serial.println("\t.[0] *123# -> Call Keegan");
  Serial.println("\t.[1] *456# -> Call Bruce");
  Serial.println("\t.[2] *789# -> Answer");
  Serial.println("\t.[3] *11# -> Hang Up");
  Serial.println("\t.[h] PRINT MENU");
}

void setup(void)
{
  Reset();
	BusMode(WRITE);
	pinMode(IRQ_NOT, INPUT);
	pinMode(RS0, OUTPUT);
	pinMode(CS_NOT, OUTPUT);
	pinMode(RW, OUTPUT);

  delay(500);

#if DBG_MSG
  Serial.begin(9600); /* Serial communication */
  while (!Serial);
  Serial.println("TARDIS.LOADING SYSTEM");
#endif
}

void loop(void)
{
#if DBG_MSG
  while(!digitalRead(9)){;}
  Serial.println("\t.SIMULATION ENABLED");
  PrintMenu();
  while(1){
    char command = Serial.read();
    switch(command){
      case 'h':
        PrintMenu();
      break;
      
      case '0':
        PlayTone(tone_sequence0, sizeof(tone_sequence0));
        Serial.println("\t.TONE SEQUENCE 0 -> PLAY");
      break;
      
      case '1':
        PlayTone(tone_sequence1, sizeof(tone_sequence1));
        Serial.println("\t.TONE SEQUENCE 1 -> PLAY");
      break;
      
      case '2':
        PlayTone(tone_sequence2, sizeof(tone_sequence2));
        Serial.println("\t.TONE SEQUENCE 2 -> PLAY");
      break;
      
      case '3':
        PlayTone(tone_sequence3, sizeof(tone_sequence3));
        Serial.println("\t.TONE SEQUENCE 3 -> PLAY");
      break;

      default:
      break;
    }
  }
#endif
#if !DBG_MSG
  if(digitalRead(9)){
      PlayTone(tone_test, sizeof(tone_test));
      PlayTone(tone_clear, sizeof(tone_clear));
  }
#endif
}






