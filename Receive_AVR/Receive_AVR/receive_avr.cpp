#include "receive_avr.h"

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

static u16 update() 
{ 
	if (!dtmf_is_idle()) {
		rd_rx_reg();
		return rd_status_reg();
	}
}

static u16 process(u16 data) 
{
	return 0;
}

static u16 execute(u16 cmd) 
{ 
	return 0;
}

unsigned int main_task()
{
	u16 data;
	u16 cmd;

	data = update();
	cmd = process(data);
	execute(cmd);

	return 0;
}