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

#include "includes/tardis.h"

#define TIMEOUT1 5000

/*
 * THIS SETS ALL THE PINS FOR THE MT8880C
 */
t_dtmf_pins pins;

t_buffer tone_buff;
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

int irq_state;
int irq_timer;

void initialize_variables(void)
{
	irq_state = 0;
	rx_state = 0;
}

/*****************************************************************/
/*****************************************************************/
void setup() {
	noInterrupts();	/* Prevent interrupts from tripping during setup. */
	initialize_variables(); 
	dtmf_initialize();

	/* Attach __INT() to interrupt pin */
	attachInterrupt(digitalPinToInterrupt(_notIRQ), __INT, CHANGE);
	
	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */

	while (!Serial)
		; /* Wait for serial coms */

	SetupDisplay(&display);
}

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
			ProcessTone(&tone_buff, &sysflgs);
			if (TimeoutMilliseconds(command_timeout, TIMEOUT1)) {
				ResetDisplay(&display);
				BufferReset(&tone_buff);
			}
		}
	}
}
