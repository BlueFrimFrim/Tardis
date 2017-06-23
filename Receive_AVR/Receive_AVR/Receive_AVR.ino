/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/

/* Version: 0v01 */

/*
 * function_name - short function description
 * @func: short function description
 * @data: variable passed 
 *
 * Returns a thing.
 * Note: this is a note
 */

#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

#include "receive_avr.h"

#define TIMEOUT1 5000

t_dtmf_pins pins;

uint8_t tone_data[TONE_SIZE];

t_sysflgs sysflgs;

//t_mt8880c mt8880c_rx;

volatile int g_last_irq, g_current_irq = 0; 

Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();

unsigned int _notIRQ = 2; /* Interrupt pin */

int rx_state; /* State of DTMF receiver */
int rx_buffer; /* Receiving buffer */
int rx_int; /* Last integer received */

int tx_int; /* Integer being sent */

unsigned int irq_state;
unsigned int irq_timer;

static void init_variables(void)
{
	irq_state = 0;
	rx_state = 0;
}

static void irq_event(void)
{
	int t = millis();
	if (t - irq_timer > 100) {
		irq_state = 1;
		irq_timer = t;
	}
}

void setup() {
	noInterrupts();
	init_variables();
	setup_task();
	init_display(&display);

	attachInterrupt(digitalPinToInterrupt(_notIRQ), irq_event, CHANGE);
	
	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */

	while (!Serial)
		; /* Wait for serial coms */
	interrupts();
}

void loop() {
	int counter = 0;
	unsigned long mtsk_time = 0;

	while (1) {
		if (counter == 99) 
			counter = 0;
		display_counter(&display, counter++);

		mtsk_time = millis();
		main_task(irq_state, mtsk_time);

		if (sysflgs.irq_flg) {
			unsigned long command_timeout = millis();
			sysflgs.irq_flg = 0;
			data = ReadReceiveRegister(&mt8880c_rx); /* Read the tone which triggered interrupt. */
			if (data == 10) { data = 0; }
			BufferWrite(&tone_buff, data);
			ReadStatusRegister(&mt8880c_rx); /* Clear interrupt register. */
			UpdateDisplayTone(&display, data); /* Update segment display */
			ProcessTone(&tone_buff, &sysflgs);
			if (timeout_ms(command_timeout, TIMEOUT1)) {
				ResetDisplay(&display);
				BufferReset(&tone_buff);
			}
		}
	}
}
