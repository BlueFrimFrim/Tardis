#ifndef DTMF_H
#define DTMF_H

#include "Arduino.h"

/*----------------------------------------------*/
/* Function declarations */
extern void Reset(void);
extern void WriteControlRegister(byte value);
extern void BusMode (byte mode);
extern void WriteTransmitRegister(byte value);
extern void BusWrite(byte value);
extern void PlayTone(byte *value, int len);


extern unsigned int BusRead(void);
extern unsigned int ReadStatusRegister(void);
extern unsigned int ReadReceiveRegister(void);

#endif /* DTMF_H */