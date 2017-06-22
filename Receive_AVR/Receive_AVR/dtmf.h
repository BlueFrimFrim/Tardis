#ifndef DTMF_H
#define DTMF_H

#include "Arduino.h"

typedef struct{
    u8 d0;
    u8 d1;
    u8 d2;
    u8 d3;
    u8 nirq;
    u8 rs0;
    u8 ncs;
    u8 rw;
}t_dtmf_pins;

static void rst(void);
static void _init(void);
static void wr_tx_reg(byte value);
static void wr_ctrl_reg(u8 value);
static void bus_mode(u8 mode);
static u8 rd_bus(void);
static void wr_bus(u8 value);


extern void dtmf_init(void);
extern void set_pins(t_dtmf_pins *gpins);
extern u8 rd_rx_reg(void);
extern u8 rd_status_reg(void);


#endif /* DTMF_H */