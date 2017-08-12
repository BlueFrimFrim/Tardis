#include "tardis.h"

/*----------------------------------------------*/
/* 7-Segment display functions */
void
WriteDisplay(Adafruit_AlphaNum4 *display)
{
	display->writeDisplay();
}

void
SetupDisplay(Adafruit_AlphaNum4 *display)
{
	display->begin(0x70);
	display->writeDigitAscii(0, '0');
	display->writeDigitAscii(1, '0');
	display->writeDigitAscii(2, 'R');
	display->writeDigitAscii(3, 'X');
	WriteDisplay(display);
}

void
UpdateDisplayCounter(Adafruit_AlphaNum4 *display, uint8_t increment)
{
	uint8_t s0, s1;
	if (increment > 9) {
		s0 = increment / 10;
		s1 = increment % 10;
		display->writeDigitAscii(0, g_seg0[s0]);
		display->writeDigitAscii(1, g_seg1[s1]);
	}
	else {
		s1 = increment;
		display->writeDigitAscii(0, '0');
		display->writeDigitAscii(1, g_seg1[s1]);
	}
	WriteDisplay(display);
}

void
UpdateDisplayTone(Adafruit_AlphaNum4 *display, volatile uint8_t tone)
{
	uint8_t s3;

	s3 = tone;
	display->writeDigitAscii(3, g_seg3[s3]);
}

/*----------------------------------------------*/
/* DTMF processing functions */

int
TimeoutMilliseconds(unsigned long start, unsigned long timeout_ms)
{
	unsigned long now = millis();
	unsigned long elapsed = now - start;
	if (elapsed > timeout_ms) { return 0; }
	return 1;
}

void
InitializeDTMF(t_mt8880c *mt8880c)
{
  BusMode(mt8880c, WRITE);
  pinMode(mt8880c->not_irq, INPUT);
  pinMode(mt8880c->rs0, OUTPUT);
  pinMode(mt8880c->not_cs, OUTPUT);
  pinMode(mt8880c->rw, OUTPUT);
  Reset(mt8880c);
  return;
}

void
MT8880C_RX_Init(t_mt8880c *mt8880c_rx)
{
	mt8880c_rx->not_irq = 2; /* Interrupt pin */

	mt8880c_rx->d0 = 3;
	mt8880c_rx->d1 = 4;
	mt8880c_rx->d2 = 5;
	mt8880c_rx->d3 = 6;

	mt8880c_rx->rs0 = 7;
	mt8880c_rx->rw = 8;
	mt8880c_rx->not_cs = 9;
}
#if 0
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
#endif
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
