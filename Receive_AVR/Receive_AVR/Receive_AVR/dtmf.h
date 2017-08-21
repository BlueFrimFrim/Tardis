#ifndef DTMF_H
#define DTMF_H

#include "Arduino.h"

/*----------------------------------------------*/
/* Definitions */
#define READ 1
#define WRITE 0

/*----------------------------------------------*/
/* Type definitions */
const uint8_t not_irq = 2;
const uint8_t d0 = 3;
const uint8_t d1 = 4;
const uint8_t d2 = 5;
const uint8_t d3 = 6;
const uint8_t rs0 = 7;
const uint8_t rw = 8;
const uint8_t not_cs = 9;

#if 0
/*----------------------------------------------*/
/* Function declarations */
extern void Reset(void);
extern void WriteControlRegister(byte value);
extern void BusMode(byte mode);
extern void WriteTransmitRegister(byte value);
extern void BusWrite(byte value);
extern void PlayTone(byte *value, int len);
//extern byte ReadIrqBit(void);

extern byte BusRead(void);
extern byte ReadStatusRegister(void);
extern byte ReadReceiveRegister(void);
#endif
#endif /* DTMF_H */