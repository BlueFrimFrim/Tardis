#ifndef DTMF_H
#define DTMF_H

#include "tardis.h"

extern void Reset(void);
extern void WriteControlRegister(byte value);
extern void BusMode(byte mode);
extern void WriteTransmitRegister(byte value);
extern void BusWrite(byte value);
extern void PlayTone(byte *value, int len);


extern byte BusRead(void);
extern byte ReadStatusRegister(void);
extern byte ReadReceiveRegister(void);

#endif
