#include "tardis.h"

unsigned int _notIRQ = 2; 

int rx_state = 0;
int rx_buffer = 0; 
int custom_number_state = 0;
int irq_state = 0;
int irq_timer = 0;

unsigned long int tx_data = 0;

void __INT(void)
{
	int t = millis();
	if (t - irq_timer > 100) {
		irq_state = 1;
		irq_timer = t;
	}
}

unsigned int dtmf_is_idle()
{
	if (irq_state)
		return 0;
	else
		return 1;
}

unsigned int update() { 
	if (!dtmf_is_idle()) {
		tx_data = ReadReceiveRegister();
		ReadStatusRegister();
	}
}

unsigned int process() {
	;
}

unsigned int void execute() { ; }

unsigned int main_task()
{
	update();
	process();
	execute();
}