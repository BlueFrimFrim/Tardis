/*
 * File:   main.c
 * Author: Keegan
 *
 * Created on November 30, 2016, 10:18 PM
 */



#include <xc.h>

/* CONFIG2H */
#pragma config WDT = OFF        /* Watchdog Timer Enable bit */

#define _XTAL_FREQ 500000 /* internal clock frequency for __delay_ms*/

#define D0_LED 0x01
#define D1_LED 0x02
#define D2_LED 0x04
#define D3_LED 0x08
#define LEDS 0x0F

#define ON 0xFF
#define OFF 0x00

#define TEST_DELAY 10

void io_write(unsigned int mask, unsigned int on_off_mask);
void knight_rider(void);

void main(void)
{
    /* initialize */	
    PORTA = 0x00;
    LATA = 0x00;
    ADCON1 = 0x7F;
    TRISA = 0xD0;
	
	knight_rider();
    while(1){;}
    return;
}

void io_write(unsigned int mask, unsigned int on_off_mask)
{
	TRISA = mask ^ on_off_mask;
    PORTA = mask;
}

#if 1
void knight_rider(void)
{
	int i, n, c;
	int loop_count;
	
	loop_count = 0;
	c = 0;
	for(i = 0; i<= 15 && loop_count < 15; i++){
		io_write(i, ON);
		__delay_ms(TEST_DELAY);
		io_write(i, OFF);
		__delay_ms(TEST_DELAY);
		
		if(i == 7){
			for(n = 6; n <= 0; n--){
				io_write(n, ON);
				__delay_ms(TEST_DELAY);
				io_write(n, OFF);
				__delay_ms(TEST_DELAY);
			}
			
			if(n == -1){
				i = 1;
				loop_count++;
			}
		}
	}
}
#endif