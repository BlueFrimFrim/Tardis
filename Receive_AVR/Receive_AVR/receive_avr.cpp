#include "receive_avr.h"

static int timeout_ms(unsigned long start, unsigned long timeout_ms)
{
	unsigned long now = millis();
	unsigned long elapsed = now - start;
	if (elapsed > timeout_ms) { return 0; }
	return 1;
}

static uint16_t dtmf_is_idle(unsigned int irq_state)
{
	if (irq_state)
		return 0;
	else
		return 1;
}



static uint16_t fetch_tone(unsigned int irq_state)
{ 
	if (!dtmf_is_idle(irq_state)) {
		rd_rx_reg();
		return rd_status_reg();
	}
}

static uint16_t parse(uint16_t data)
{
	if (data == 10)
		data = 0;
	return 0;
}

static uint16_t process(uint16_t parsed_data)
{
	return 0;
}

static uint16_t execute(uint16_t cmd)
{ 
	return 0;
}

/* 
 * setup_task - initializes everything needed for receive_avr 
 * @func - runs all init functions
 *
 * @return - nothing
 */
void setup_task()
{
	rx_timeout = 0;

	dtmf_init();
}

/*
 * main_task - main receive_avr task
 * @func - runs all the processes to handle the dtmf
 *
 * @return - timeout data
 */
unsigned int *main_task(unsigned int irq_state, unsigned long mtsk_time)
{
	unsigned int data;
	unsigned int parsed_data;
	unsigned int cmd;

	if (timeout_ms(mtsk_time, 5000)){
		
	}

	data = fetch_tone(irq_state);
	parsed_data = parse(data);
	cmd = process(parsed_data);
	execute(cmd);


	return 0;
}

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