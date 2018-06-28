#ifndef MT8880C_H
#define MT8880C_H

#include "tardis.h"

class MT8880C_T{
public:
  uint8_t D0;
  uint8_t D1;
  uint8_t D2;
  uint8_t D3;
  uint8_t RW;
  uint8_t RS0;
  uint8_t nCS;
  uint8_t nIRQ;
  
  void Reset(void);
  uint8_t ReadStatusRegister(void);
  void WriteTransmitRegister(uint8_t value);
  void WriteControlRegister(uint8_t value);
  uint8_t BusRead(void);
  void BusWrite(uint8_t value);
  uint8_t ReadReceiveRegister(void);
  void PlayTone(uint8_t *value, int len);
  void PlayTone(uint8_t *value, int len, int count);

private:
  void BusMode(uint8_t mode);
};

#endif
