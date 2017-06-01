#ifndef TARDIS_H
#define TARDIS_H

/* Version: 0v01 */

/*----------------------------------------------*/
/* Includes */

#include "Arduino.h"
#include <Wire.h>

#include "buffer.h"
#include "dtmf.h"

/*----------------------------------------------*/
/* Definitions */
#define TONE_SIZE 256

/*----------------------------------------------*/
/* Type definitions */
const byte g_one = 1;
const byte g_two = 2;
const byte g_three = 3;
const byte g_four = 4;
const byte g_five = 5;
const byte g_six = 6;
const byte g_seven = 7;
const byte g_eight = 8;
const byte g_nine = 9;
const byte g_zero = 10;

const byte g_star = 11;
const byte g_hash = 12;

/*----------------------------------------------*/
/* Type definitions */
typedef struct
{
    uint8_t irq_flg;
}t_sysflgs;

/*----------------------------------------------*/
/* Function declarations */
extern void InitializeDTMF(t_mt8880c *mt8880c);
extern void MT8880C_RX_Init(t_mt8880c *mt8880c_rx);
extern void ProcessTone(t_buffer *buffer);
extern void ExecuteCommand(uint64_t command);
extern unsigned Concatenate(unsigned x, unsigned y);

#endif /* TARDIS_H */