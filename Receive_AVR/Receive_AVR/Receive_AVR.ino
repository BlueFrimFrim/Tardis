/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/

#include "tardis.h"

t_buffer tone_buff;
uint8_t tone_data[TONE_SIZE];

volatile t_sysflgs sysflgs;

volatile int last_irq, current_irq = 0; 

/*----------------------------------------------*/
/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{
	current_irq = millis();
	if (current_irq - last_irq > 100) {
		sysflgs.irq_flg = 1;
		last_irq = current_irq;
	}
}
/*----------------------------------------------*/
/*----------------------------------------------*/

// the setup function runs once when you press reset or power the board
void setup() {
	BufferInit(&tone_buff, tone_data, (uint16_t)TONE_SIZE);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (sysflgs.irq_flg) {
		sysflgs.irq_flg = 0;
	}
}

