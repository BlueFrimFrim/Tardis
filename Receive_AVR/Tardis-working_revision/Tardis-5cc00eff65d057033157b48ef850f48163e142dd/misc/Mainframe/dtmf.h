#include "tardis.h"



//--------------------------------------------------------------------------
// Constants.
#define WRITE 0
#define READ 1

//--------------------------------------------------------------------------
// Data types.
typedef unsigned char byte;
//-------------------------------------------------------------------------
// Variables.

unsigned long LastInterruptCount = 0;

/* DTMF CHARACTERS */
static const byte star = 11;
static const byte hash = 12;


byte ToneReceived = 0;
byte TonesRx[7] = {0};
int TonePosition = 0;

int irqFlg = 0;

int irq_delay = 1.0; /* 1 sec */

//-------------------------------------------------------------------------
// Function prototypes.
int receiveDTMF(void);
int generateDTMF(void);
void setupDTMF(void);

void initializeMT8880C(void);
void reset(void);
unsigned char statusRegister_read(void);
unsigned char receiveRegister_read(void);
void transmitRegister_write(unsigned char value);
void busMode(unsigned char mode);
void busWrite(unsigned char value);
unsigned char busRead(void);
void controlRegister_write(unsigned char value);

float concatenate(float x, float y);
unsigned char bitRead(DigitalInOut *pin_t);
void bitWrite(DigitalInOut *pin_t, byte value);

void irq_printReceived(void);




