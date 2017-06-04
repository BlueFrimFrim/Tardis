/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/

/* Version: 0v01 */

/*----------------------------------------------*/
/* TARDIS LIBRARIES */
#include "tardis.h"

#define TIMEOUT1 120000

t_buffer tone_buff;
uint8_t tone_data[TONE_SIZE];

volatile t_sysflgs sysflgs;

t_mt8880c mt8880c_rx;

volatile int g_last_irq, g_current_irq = 0; 

Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();

/*----------------------------------------------*/
/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{
	//uint8_t data = 0;
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
	sysflgs.phone_flg = 0;
	attachInterrupt(digitalPinToInterrupt(mt8880c_rx.not_irq), IRQ_ToneReceived, CHANGE);
	
	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */
	while (!Serial);
	Serial.println("Tardis Initialized.");
	SetupDisplay(&display);
}

// the loop function runs over and over again until power down or reset
void loop() {
	uint8_t data = 0;
	int counter = 0;

	while (1) {
		if (counter == 99) { counter = 0; }
		UpdateDisplayCounter(&display, counter++);
		if (sysflgs.irq_flg) {
			unsigned long command_timeout = millis();
			sysflgs.irq_flg = 0;
			data = ReadReceiveRegister(&mt8880c_rx); /* Read the tone which triggered interrupt. */
			if (data == 10) { data = 0; }
			BufferWrite(&tone_buff, data);
			ReadStatusRegister(&mt8880c_rx); /* Clear interrupt register. */
			UpdateDisplayTone(&display, data); /* Update segment display */
			ProcessTone(&tone_buff);
			if (TimeoutMilliseconds(command_timeout, TIMEOUT1)) {
				ResetDisplay(&display);
				BufferReset(&tone_buff);
			}
		}
	}
}
