/*
 * main.c
 *
 *  Created on: 2017 Aug 05 18:34:57
 *  Author: Keegan
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

#define TIMEOUT 500000U

volatile uint8_t tick = 0;

void status_led(void);
void ptt_timeout(void);

void delay(uint32_t decrement)
{
	volatile uint32_t i = decrement;
	while(--i);
}

int main(void)
{

  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  uint32_t TimerId = SYSTIMER_CreateTimer(TIMEOUT,SYSTIMER_MODE_PERIODIC, (void*)ptt_timeout, NULL);
  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }
  SYSTIMER_StartTimer(TimerId);
  SYSTIMER_Stop();
  while(1U)
  {
	  if(DIGITAL_IO_GetInput(&PTT_IN)){
		  DIGITAL_IO_SetOutputHigh(&LED2);
		  delay(0xFF);
		  if(!DIGITAL_IO_GetInput(&PTT_IN)){SYSTIMER_Start();}
	  }
	  else{
		  DIGITAL_IO_SetOutputLow(&LED2);
	  }
  }
}

void ptt_timeout(void)
{
	tick++;
	if(tick == 1)
	{
		tick = 0;
		SYSTIMER_Stop();
		DIGITAL_IO_SetOutputHigh(&LED1);
		delay(0xFFFF);
		DIGITAL_IO_SetOutputLow(&LED1);
		delay(0xFFFFF);
		DIGITAL_IO_SetOutputHigh(&LED1);
		delay(0xFFFF);
		DIGITAL_IO_SetOutputLow(&LED1);
		delay(0xFFFF);
	}
}

void status_led(void)
{
	  DIGITAL_IO_SetOutputHigh(&LED1);
	  delay(0xFFFF);
	  DIGITAL_IO_SetOutputLow(&LED1);
	  delay(0xFFFF);
}




