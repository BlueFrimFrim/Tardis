#include "includes/tardis.h"

unsigned int _notIRQ = 2; 

int rx_state = 0;
int rx_buffer = 0; 
int custom_number_state = 0;
int irq_state = 0;
int irq_timer = 0;

unsigned long int tx_data = 0;

static u16 dtmf_is_idle()
{
	if (irq_state)
		return 0;
	else
		return 1;
}

static u16 update() { 
	if (!dtmf_is_idle()) {
		rd_rx_reg();
		return rd_status_reg();
	}
}

static u16 process() 
{
	return 0;
}

static u16 execute() 
{ 
	return 0;
}

void _irq(void)
{
	int t = millis();
	if (t - irq_timer > 100) {
		irq_state = 1;
		irq_timer = t;
	}
}

unsigned int main_task()
{
	update();
	process();
	execute();
}