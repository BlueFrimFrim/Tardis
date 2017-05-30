#ifndef DTMF_H
#define DTMF_H

/* Version: 0v00 */

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
extern void Reset(t_mt8880c *mt8880c);
extern void WriteControlRegister(t_mt8880c *mt8880c, byte value);
extern void BusMode(t_mt8880c *mt8880c, byte mode);
extern void WriteTransmitRegister(t_mt8880c *mt8880c, byte value);
extern void BusWrite(t_mt8880c *mt8880c, byte value);
extern void PlayTone(byte *value, int len);


extern byte BusRead(void);
extern byte ReadStatusRegister(t_mt8880c *mt8880c);
extern byte ReadReceiveRegister(void);

#endif /* DTMF_H */