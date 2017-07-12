#include "tardis.h"
/*
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
*/

byte gtone_received = 0;

void print_received(void);
unsigned concatenate(unsigned x, unsigned y);

int interrupt = 0;
int interrupt2 = 0;

byte tone_test[] = {star, one, two, three, hash};
byte tone_clear[] = {0};

char train_code = 0;

volatile long int gcommand = 0;

unsigned long interrupt_time = 0;
unsigned long last_interrupt = 0;

unsigned long interrupt_time2 = 0;
unsigned long last_interrupt2 = 0;

int timer = 0;

/* 
 *  
 *  
 *  TONE DETECTION 
 *
 *
 */

void InitializeDTMF(void);
int seconds(int sec);

void ToneIRQ(void);
void ProcessTone(long int input);

void setup(void)
{
  Serial.begin(9600);
  while(!Serial);
  attachInterrupt(digitalPinToInterrupt(IRQ_NOT), ToneIRQ, CHANGE); /* READ STATUS REGISTER TO CLEAR INTERRUPT */
  InitializeDTMF();
  delay(100);
  Wire.begin(); /* i2c communication */
}

void loop(void)
{
  if(interrupt){
	interrupt = 0;
	ProcessTone(gtone_received);
	Serial.print("Tardis:~ Detected$ ");
	Serial.println(gtone_received);
  }
}

//--------------------------------------------------------------------------
// 2017-05-23 Newer functions.
void
InitializeDTMF(void)
{
  BusMode(WRITE);
  pinMode(IRQ_NOT, INPUT);
  pinMode(RS0, OUTPUT);
  pinMode(CS_NOT, OUTPUT);
  pinMode(RW, OUTPUT);
  Reset();
  return;
}

int
TimeoutMilliseconds(unsigned long start, unsigned long timeout_ms)
{
  unsigned long now = millis();
  unsigned long elapsed = now - start;
  if(elapsed > timeout_ms){return 0;}
  return 1;
}

// End of changes.



void
ToneIRQ(void)
{
	interrupt_time = millis();
	if(interrupt_time - last_interrupt > 100){
	  interrupt = 1;
	  ReadReceiveRegister();
	  ReadStatusRegister();
	  last_interrupt = interrupt_time;
	}
}

void 
ProcessTone(long int input)
{
	#ifdef DEBUG
		Serial.print(F("Horizon:~ Tardis-Debug$ Input: "));
		Serial.println(input);
	#endif

	if(input == 12){

		#ifdef DEBUG
			Serial.print(F("Horizon:~ Tardis-Debug$ Execute: "));
			Serial.println(gcommand);
		#endif
		if(gcommand == star){return;}
		else{execute_command(gcommand);}
	}
	if(input == 11){gcommand = input;}

	else{

		#ifdef DEBUG
			Serial.print(F("Tardis:~ Concatenate$ gcommand: "));
			Serial.print(gcommand);  
			Serial.print(F("  input: "));
			Serial.println(input);
		#endif

		gcommand = concatenate(gcommand, input);

		#ifdef DEBUG
			Serial.print(F("Horizon:~ Tardis-Debug$ Tones Received: "));
			Serial.print(gcommand);  
		#endif
	}
}

void execute_command(long int command)
{
  switch (command){
	case 11123:
	  Wire.beginTransmission(7); // transmit to device #8
	  Wire.write(0x07);              // sends one byte
	  Wire.endTransmission();
	  delay(100);
	break;

	default:
	  Wire.beginTransmission(7); // transmit to device #8
	  Wire.write(0xff);              // sends one byte
	  Wire.endTransmission();
	  delay(100);
	break;
  }
}

/*
 * concatenate(unsigned x, unsigned y)
 *
 * 1) get number of digits: digits = log10(y)+1
 * 2) shift: shifted = x * pow(10, digits)
 * 3) add second variable: z = shifted + y
 *
 */
unsigned concatenate(unsigned x, unsigned y)
{
  return x * pow(10, (int)log10(y)+1) + y;
}




