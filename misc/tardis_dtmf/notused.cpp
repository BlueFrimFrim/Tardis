/* 
 *  
 *  
 *  TONE GENERATION 
 *
 *
 */
#if 0 /* REGENERATE_TONE */
void setup(void)
{
  reset();
	bus_mode(WRITE);
	pinMode(SW, INPUT);
	pinMode(IRQ_NOT, INPUT);
	pinMode(RS0, OUTPUT);
	pinMode(CS_NOT, OUTPUT);
	pinMode(RW, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(IRQ_NOT), simulate, CHANGE); /* READ STATUS REGISTER TO CLEAR INTERRUPT */
  delay(1500);
}

void loop(void)
{
  if(interrupt == 1){
    play_tone(tone_test, sizeof(tone_test));
    interrupt = 0;
    play_tone(tone_clear, sizeof(tone_clear));
  }
}
#endif /* REGENERATE_TONE */