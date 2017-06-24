#include "display.h"


static void wr_display(Adafruit_AlphaNum4 *display)
{
	display->writeDisplay();
}

/*
 * init_display - initialized the 4 7-segment displays
 * @func - sets 7-seg to '00RX'
 *
 * @return - nothing
 */
void init_display(Adafruit_AlphaNum4 *display)
{
	display->begin(0x70);
	display->writeDigitAscii(0, '0');
	display->writeDigitAscii(1, '0');
	display->writeDigitAscii(2, 'R');
	display->writeDigitAscii(3, 'X');
	wr_display(display);
}

/*
 * rst_display - resets 7-seg
 * @func - resets 7-seg to '00RX'
 *
 * @return - nothing
 */
void rst_display(Adafruit_AlphaNum4 *display)
{
	display->writeDigitAscii(0, '0');
	display->writeDigitAscii(1, '0');
	display->writeDigitAscii(2, 'R');
	display->writeDigitAscii(3, 'X');
	wr_display(display);
}

/*
 * display_tone - display's tone on 7-seg
 * @func - display tone on 7-segs
 *
 * @return - nothing
 */
void display_tone(Adafruit_AlphaNum4 *display, uint8_t tone)
{
	display->writeDigitAscii(3, g_seg3[tone]);
}

/*
* display_counter - display 7-seg counter
* @func - display counter up to 99
*
* @return - nothing
*/
void display_counter(Adafruit_AlphaNum4 *display, uint8_t increment)
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
	wr_display(display);
}