#include "tardis.h"

/*****************************************************************/
/* ARDUINO PIN Stuff */
unsigned int _notIRQ = 2; /* Interrupt pin */

/*****************************************************************/
/* RECEIVER Stuff */
int rx_state = 0; /* State of DTMF receiver */
int rx_buffer = 0; /* Receiving buffer */

/*****************************************************************/
/* TRANSMITTER Stuff */
int tx_state = 0; /* State of CUSTOM phone number */
unsigned long int tx_data = 0; /* Buffer for incoming data */

/*****************************************************************/
/* INTERRUPT Stuff */
int irq_state = 0;
int irq_timer = 0;

/*****************************************************************/
/* Interrupt Service Routine */
void __INT(void)
{
	int t = millis();
	if (t - irq_timer > 100) {
		irq_state = 1;
		irq_timer = t;
	}
}

/*****************************************************************/
int dtmf_is_idle()
{
	if (irq_state)
		return 0;
	else
		return 1;
}

/*****************************************************************/
unsigned int update() { 
	if (!dtmf_is_idle()) {
		tx_data = ReadReceiveRegister();
		ReadStatusRegister();
	}
}

/*****************************************************************/
void process() {
	;
}

/*****************************************************************/
void execute() { ; }

/*****************************************************************/
/*****************************************************************/
void main_task()
{
	update();
	process();
	execute();
}