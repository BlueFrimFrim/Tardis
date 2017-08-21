

#include "tardis.h"

/*----------------------------------------------*/
/* DTMF processing functions */
#if 0
int
TimeoutMilliseconds(unsigned long start, unsigned long timeout_ms)
{
	unsigned long now = millis();
	unsigned long elapsed = now - start;
	if (elapsed > timeout_ms) { return 0; }
	return 1;
}

void
InitializeDTMF(void)
{
  BusMode(WRITE);
  pinMode(not_irq, INPUT);
  pinMode(rs0, OUTPUT);
  pinMode(not_cs, OUTPUT);
  pinMode(rw, OUTPUT);
  Reset();
  return;
}


void
ProcessTone(t_buffer *buffer)
{
	uint8_t tone_in = 0;
	tone_in = BufferRead(buffer); /* Read tone received. */
	if (tone_in == g_hash) {
		if (buffer->command == g_star) { return; }
		else { ExecuteCommand(buffer->command); }
	}
	if (tone_in == g_star) { buffer->command = tone_in; }
	else { buffer->command = Concatenate(buffer->buff_size, tone_in); }
}

void
ExecuteCommand(uint64_t command)
{
	switch (command) {
	case 11123:
		Wire.beginTransmission(7);
		Wire.write(0x02);
		Wire.endTransmission();
		delay(100);
		break;
	case 112468:
		Wire.beginTransmission(7);
		Wire.write(0x03);
		Wire.endTransmission();
		delay(100);
		break;
	default:
		Wire.beginTransmission(7);
		Wire.write(0x01);
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
unsigned
Concatenate(unsigned x, unsigned y)
{
	return x * pow(10, (int)log10(y) + 1) + y;
}
#endif
