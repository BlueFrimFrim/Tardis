#ifndef DTMF_H
#define DTMF_H

#include "Arduino.h"

/*----------------------------------------------*/
/* Definitions */
#define READ 1
#define WRITE 0

/*----------------------------------------------*/
/* Type definitions */
typedef struct
{
	byte d0;
	byte d1;
	byte d2;
	byte d3;
	byte not_irq;
	byte rs0;
	byte not_cs;
	byte rw;
} t_mt8880c;

/*----------------------------------------------*/
/* Function declarations */
extern void Reset(void);
extern void WriteControlRegister(byte value);
extern void BusMode (byte mode);
extern void WriteTransmitRegister(byte value);
extern void BusWrite(byte value);
extern void PlayTone(byte *value, int len);


extern byte BusRead(void);
extern byte ReadStatusRegister(void);
extern byte ReadReceiveRegister(void);

#endif /* DTMF_H */