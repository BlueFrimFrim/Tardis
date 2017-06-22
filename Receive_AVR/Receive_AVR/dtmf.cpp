#include "dtmf.h"

#define READ 1
#define WRITE 0
#define HIGH 1
#define LOW 0

static t_dtmf_pins pins;

static void rst(void)
{
	delay(100);
	wr_ctrl_reg(B0000);
	wr_ctrl_reg(B0000);
	wr_ctrl_reg(B1100);
	wr_ctrl_reg(B0000);
	rd_status_reg();
}

static void _init(void)
{
	bus_mode(WRITE);
	pinMode(pins.nirq, INPUT);
	pinMode(pins.rs0, OUTPUT);
	pinMode(pins.ncs, OUTPUT);
	pinMode(pins.rw, OUTPUT);
	rst();
}

static void wr_tx_reg(byte value)
{
	wr_bus(value);
	digitalWrite(pins.rs0, LOW);
	digitalWrite(pins.rw, LOW);
	digitalWrite(pins.ncs, LOW);
	digitalWrite(pins.ncs, HIGH);
}

static void wr_ctrl_reg(u8 value)
{
	wr_bus(value);
	digitalWrite(pins.ncs, LOW);
	digitalWrite(pins.rs0, HIGH);
	digitalWrite(pins.rw, LOW);
	digitalWrite(pins.ncs, HIGH);
}

static void bus_mode(u8 mode)
{
	if(mode == WRITE){
		pinMode(pins.d0, OUTPUT);
		pinMode(pins.d1, OUTPUT);
		pinMode(pins.d2, OUTPUT);
		pinMode(pins.d3, OUTPUT);
	}
	else if( mode == READ){
		pinMode(pins.d0, INPUT);
		pinMode(pins.d1, INPUT);
		pinMode(pins.d2, INPUT);
		pinMode(pins.d3, INPUT);
	}
}

static u8 rd_bus(void)
{
	byte value = 0;

	bus_mode(READ);
	bitWrite(value, 0, digitalRead(pins.d0));
	bitWrite(value, 1, digitalRead(pins.d1));
	bitWrite(value, 2, digitalRead(pins.d2));
	bitWrite(value, 3, digitalRead(pins.d3));

	return value;
}

static void wr_bus(u8 value)
{
	bus_mode(WRITE);
	digitalWrite(pins.d0, bitRead(value, 0));
	digitalWrite(pins.d1, bitRead(value, 1));
	digitalWrite(pins.d2, bitRead(value, 2));
	digitalWrite(pins.d3, bitRead(value, 3));

	return;
}

/*
 * dtmf_init - this function will initialize the mt8880c
 * @func - initialize mt8880c
 *
 * @return - nothing
 */
void dtmf_init(void)
{
	_init();
}

/*
 * set_pins - function to set pins for static functions
 * @func - set pins for functions
 *
 * @return - nothing
 */
void set_pins(t_dtmf_pins *gpins)
{
	pins.d0 = gpins->d0;
	pins.d1 = gpins->d1;
	pins.d2 = gpins->d2;
	pins.d3 = gpins->d3;

	pins.nirq = gpins->nirq;

	pins.rs0 = gpins->rs0;
	
	pins.ncs = gpins->ncs;

	pins.rw = gpins->rw;
}

/*
 * rd_rx_reg - read receive register of mt8880c
 * @func - read receive register
 *
 * @return - dtmf tone received
 */
u8 rd_rx_reg(void)
{
	u8 tone_rx = 0;

	bus_mode(READ);
	
	digitalWrite(pins.rw, HIGH);
	digitalWrite(pins.rs0, LOW);
	digitalWrite(pins.ncs, LOW);

	tone_rx = rd_bus();

	return tone_rx;
}

/*
 * rd_status_reg - read status register
 * @func - read register to clear irq
 *
 * @return - previous dtmf tone recieved
 */
u8 rd_status_reg(void)
{
	u8 value = 0;

	bus_mode(READ);

	digitalWrite(pins.rw, HIGH);
	digitalWrite(pins.rs0, HIGH);
	digitalWrite(pins.ncs, LOW);

	value = rd_bus();
	
	digitalWrite(pins.ncs, HIGH);

	return value;
}