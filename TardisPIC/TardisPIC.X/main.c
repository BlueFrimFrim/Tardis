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

#define OUTPUT 1
#define INPUT 0

#define TEST_DELAY 5

#define DEBUG 1
#define RUN 1

void ConfigSystem(void);

void BitWrPortI(int port, int value,int bitcode)
{
    LATA = value << bitcode;
}

int BitRdPortA(int r)
{
	return PORTA << r;
}

void Set_DTMF_bus_mode(int mode) /* configure d0-d3 as IN or OUT */
{
	BitWrPortI(TRISA, mode, 0);
	BitWrPortI(TRISA, mode, 1);
	BitWrPortI(TRISA, mode, 2);
	BitWrPortI(TRISA, mode, 3);
}
void Set_DTMF_bus(int r)
{
	BitWrPortI(LATA, (r & 0x01) >> 0, 0); /* Set RA0 */
	BitWrPortI(LATA, (r & 0x02) >> 1, 1); /* Set RA1 */
	BitWrPortI(LATA, (r & 0x04) >> 2, 2); /* Set RA2 */
	BitWrPortI(LATA, (r & 0x08) >> 3, 3); /* Set RA3 */
}

void Set_DTMF_CS(int r)
{
	BitWrPortI(PORTB, r, 2);
}

void Set_DTMF_WR(int r)
{
	BitWrPortI(PORTB, r, 3);
}

void Set_DTMF_RD(int r)
{
	BitWrPortI(PORTB, r, 3);
}

void Set_DTMF_RS0(int r)
{
	BitWrPortI(PORTB, r, 1);
}

void DTMF_Tx_Tone(int tone)
{
	Set_DTMF_bus_mode(OUTPUT);
	Set_DTMF_RS0(0);
//	Set_DTMF_bus(tone);
	BitWrPortI(LATA, 1, 0);
	BitWrPortI(LATA, 0, 1);
	BitWrPortI(LATA, 0, 2);
	BitWrPortI(LATA, 0, 3);

	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus_mode(INPUT);
}

void knight_rider(void)
{
	int i, n, c;
	int loop_count;
	
	loop_count = 0;
	c = 0;
	for(i = 0; i<= 15 && loop_count < 15; i++){
		BitWrPortI(PORTA, i, ON);
		__delay_ms(TEST_DELAY);
		BitWrPortI(PORTA, i, OFF);
		__delay_ms(TEST_DELAY);
		
		if(i == 7){
			for(n = 6; n <= 0; n--){
				BitWrPortI(PORTA, n, ON);
				__delay_ms(TEST_DELAY);
				BitWrPortI(PORTA, n, OFF);
				__delay_ms(TEST_DELAY);
			}
			if(n == -1){
				i = 1;
				loop_count++;
			}
		}
	}
}

void main(void)
{
	BitWrPortI(TRISA, 0, 0xF0);
	BitWrPortI(TRISB, 0, 0xF0);
	
	knight_rider(); /* Test ports */
	
	/* Reset DTMF Chip */
	
	Set_DTMF_bus_mode(INPUT);
	Set_DTMF_CS(0);
	Set_DTMF_RS0(1);
	Set_DTMF_RD(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus_mode(OUTPUT);
	Set_DTMF_bus(0x00);
	__delay_ms(1);
	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus(0x08);
	__delay_ms(1);
	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus(0x00);
	__delay_ms(1);
	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);


	Set_DTMF_bus_mode(INPUT);
	Set_DTMF_RD(0);  /* Read from the chip to clear flags */
	__delay_ms(1);
	Set_DTMF_RD(1);

	/*** Now we configure the DTMF tx mode *///
	Set_DTMF_bus_mode(OUTPUT);
	Set_DTMF_bus(0x0D);
	__delay_ms(1);
	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus(0x00);
	__delay_ms(1);
	Set_DTMF_WR(0);
	__delay_ms(1);
	Set_DTMF_WR(1);
	Set_DTMF_bus_mode(INPUT);
	/* End of reset */
	
    while(1){
		DTMF_Tx_Tone(1);
		__delay_ms(1000);
		DTMF_Tx_Tone(2);
		__delay_ms(1000);
		DTMF_Tx_Tone(3);
		__delay_ms(1000);
		DTMF_Tx_Tone(4);
		__delay_ms(1000);
	}
    return;
}

void ConfigSystem(void)
{
	WDTCONbits.SWDTEN = 0;
	
	/* initialize PORTA */	
    PORTA = 0x00;
    LATA = 0x00;
    ADCON1 = 0x7F;
    TRISA = 0xD0;
}