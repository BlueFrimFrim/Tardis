/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/

#include "tardis.h"

t_buffer tone_buff;
uint8_t tone_data[TONE_SIZE];

volatile t_sysflgs sysflgs;

t_mt8880c mt8880c_rx;


volatile int g_last_irq, g_current_irq = 0; 

/*----------------------------------------------*/
/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{
	g_current_irq = millis();
	if (g_current_irq - g_last_irq > 100) {
		sysflgs.irq_flg = 1;
		g_last_irq = g_current_irq;
	}
}
/*----------------------------------------------*/
/*----------------------------------------------*/

// the setup function runs once when you press reset or power the board
void setup() {
	BufferInit(&tone_buff, tone_data, (uint16_t)TONE_SIZE);
	MT8880C_RX_Init(&mt8880c_rx);
	InitializeDTMF(&mt8880c_rx);
	delay(100);

	sysflgs.irq_flg = 0;
	attachInterrupt(digitalPinToInterrupt(mt8880c_rx.not_irq), IRQ_ToneReceived, CHANGE);
	
	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */
	while (!Serial);
}

// the loop function runs over and over again until power down or reset
void loop() {
	uint8_t data = 0; 
	if (sysflgs.irq_flg) {
		sysflgs.irq_flg = 0;

		data = ReadReceiveRegister(&mt8880c_rx); /* Read the tone which triggered interrupt. */
		BufferWrite(&tone_buff, data);
		ReadStatusRegister(&mt8880c_rx); /* Clear interrupt register. */

	}
}

