#ifndef DTMF_H
#define DTMF_H


#include "tardis.h"

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

extern void dtmf_init(void);
extern void set_pins(t_dtmf_pins *gpins);
extern u8 rd_rx_reg(void);
extern u8 rd_status_reg(void);


#endif /* DTMF_H */