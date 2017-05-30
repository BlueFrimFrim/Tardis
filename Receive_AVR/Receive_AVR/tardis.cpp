#include "tardis.h"

void
InitializeDTMF(void)
{
  BusMode(WRITE);
  pinMode(IRQ_NOT, INPUT);
  pinMode(RS0, OUTPUT);
  pinMode(CS_NOT, OUTPUT);
  pinMode(RW, OUTPUT);
  Reset();
  return;
}

/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{
	interrupt_time = millis();
	if(interrupt_time - last_interrupt > 100){
	  sysflg.irq_flg = 1;
	  last_interrupt = interrupt_time;
	}
}