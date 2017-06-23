#ifndef DTMF_H
#define DTMF_H

#include "Arduino.h"

typedef struct{
	uint8_t d0;
	uint8_t d1;
	uint8_t d2;
	uint8_t d3;
	uint8_t nirq;
	uint8_t rs0;
	uint8_t ncs;
	uint8_t rw;
}t_dtmf_pins;

static void rst(void);
static void _init(void);
static void wr_tx_reg(byte value);
static void wr_ctrl_reg(uint8_t value);
static void bus_mode(uint8_t mode);
static uint8_t rd_bus(void);
static void wr_bus(uint8_t value);


extern void dtmf_init(void);
extern void set_pins(t_dtmf_pins *gpins);
extern uint8_t rd_rx_reg(void);
extern uint8_t rd_status_reg(void);


#endif /* DTMF_H */