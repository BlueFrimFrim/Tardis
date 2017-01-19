#include "Arduino.h"

typedef struct {
	static const byte one;
	static const byte two
	static const byte three;
	static const byte four;
	static const byte five;
	static const byte six;
	static const byte seven;
	static const byte eight;
	static const byte nine;
	static const byte star;
	static const byte hash;
	static const byte A;
	static const byte B;
	static const byte C;
	static const byte D;
} t_CHARACTERS;

typedef struct {
	const byte D0;
	const byte D1;
	const byte D2;
	const byte D3;
	const byte IRQ_NOT;
	const byte RS0;
	const byte RW;
	const byte CS_NOT;
	const byte CLK;
	const byte SW;
} t_PINS;

typedef struct {
	t_CHARACTERS Characters;
	t_PINS Pins;
} T_MT8880;

T_MT8880 MT8880;

void init_dtmf_keys(MT8880 *dtmf);
void init_pins(T_MT8880 *pins);

void setup(void)
{
	init_dtmf_keys(&MT8880);
	init_pins(&MT8880)

}

void loop(void)
{

}

void init_dtmf_keys(T_MT8880 *dtmf)
{
	dtmf->one = 1;
	dtmf->two = 2;
	dtmf->three = 3;
	dtmf->four = 4;
	dtmf->five = 5;
	dtmf->six = 6;
	dtmf->seven = 7; 
	dtmf->eight = 8;
	dtmf->nine = 9;
	dtmf->zero = 10;
	dtmf->star = 11;
	dtmf->hash = 12;
	dtmf->A = 13;
	dtmf->B = 14;
	dtmf->C = 15;
	dtmf->D = 0;
}

void init_pins(T_MT8880 *pins)
{
	pins->D0 = 3;
	pins->D1 = 4;
	pins->D2 = 5;
	pins->D3 = 6;
	pins->IRQ_NOT = 7;
	pins->RS0 = 8;
	pins->RW = 9;
	pins->CS_NOT = 10;
	pins->CLK = 11;
	pins->SW = 12;
}







