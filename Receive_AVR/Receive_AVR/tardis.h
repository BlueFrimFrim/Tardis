#ifndef _TARDIS_H
#define _TARDIS_H

#include "dtmf.h"

#define TONE_SIZE 256

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
	uint8_t phone_flg;
}t_sysflgs;

/*----------------------------------------------*/
/* Function declarations */

/*****************************************************************/
extern void __INT(void);
extern unsigned int dtmf_is_idle();
extern unsigned int update();
extern unsigned int process();
extern unsigned int execute();
extern unsigned int main_task();

void dtmf_initialize(void);

extern void WriteDisplay(Adafruit_AlphaNum4 *display);
extern void SetupDisplay(Adafruit_AlphaNum4 *display);
extern void UpdateDisplayCounter(Adafruit_AlphaNum4 *display, uint8_t increment);
extern void UpdateDisplayTone(Adafruit_AlphaNum4 *display, uint8_t tone);
extern void ResetDisplay(Adafruit_AlphaNum4 *display);

extern int TimeoutMilliseconds(unsigned long start, unsigned long timeout_ms);
extern void InitializeDTMF(t_mt8880c *mt8880c);
extern void MT8880C_RX_Init(t_mt8880c *mt8880c_rx);
extern void ProcessTone(t_buffer *buffer, t_sysflgs *sysflgs);
extern void ExecuteCommand(t_buffer *buffer, t_sysflgs *sysflgs);
extern unsigned Concatenate(unsigned x, unsigned y);

#endif /* TARDIS_H */