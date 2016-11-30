////////////////////////////////////////////////////////////////////////////////
// UCA VER 0.9 TEST PROGRAM

#class auto
#define OUTPUT 1
#define INPUT 0
#define LOW 0
#define HIGH 1

#define BINBUFSIZE  31
#define BOUTBUFSIZE 31
#define MSAT_BAUD_RATE 9600
#define CHIP_DELAY 1

/* General purpose functions */

void msDelay(unsigned int delay) /* Stops the program flow during X milisec */
{
auto unsigned long done_time;

   done_time = MS_TIMER + delay;
while( (long) (MS_TIMER - done_time) < 0 );

}

void clrscr() /* Clears the console */
{
   printf (" \x1Bt" );
}

void WrBitDemux(int port, int value, int bitcode)
{
   int data;
   int vr;

   //  Bits:             7 -- 6 -- 5 -- 4 -- 3 --  2 --  1 --  0  //
   //  Bits:             ? -- z -- y -- x -- D -- A2 -- A1 -- A0  //
   //  Mask Address:     0 -- 0 -- 0 -- 0 -- 0 -- 1  --  1 --  1  //
   //  Mask Address:     ****************************** 0x07 **********
   //  Mask Latch1:      0 -- 0 -- 0 -- 0 -- 1 -- 0  --  0 --  0  //
   //  Mask Latch1:      ****************** 0x08 **********************
   //  Mask Latch2:      0 -- 1 -- 1 -- 1 -- 0 -- 0  --  0 --  0  //
   //  Mask Latch2:      **** 0x70 ************************************
   //  Mask Latch3:      1 -- 0 -- 0 -- 0 -- 0 -- 0  --  0 --  0  //
   //  Mask Latch2:      0x80 *****************************************

data = 0x70 | ((0x01 & value) << 3) | (bitcode & 0x07);
   vr = (vr & 0x80) | (data & 0x7f);
   WrPortI(PADR, &PADRShadow, vr);
   msDelay(100);

   switch(port) {
    case 0: vr = vr & 0xef; break;
      case 1: vr = vr & 0xdf; break;
      case 2: vr = vr & 0xbf; break;
   }

   WrPortI(PADR, &PADRShadow, vr);
   msDelay(100);

   switch(port) {
    case 0: vr = vr | 0x10; break;
      case 1: vr = vr | 0x20; break;
      case 2: vr = vr | 0x40; break;
   }

   WrPortI(PADR, &PADRShadow, vr);
}

/* Functions for DTMF operation */

void Set_DTMF_bus_mode(int mode) /* Configures D0, D3, D6 and D7 as IN or OUT */
{
BitWrPortI(PDDDR, &PDDDRShadow, mode, 0); /* Configures PD0 */
BitWrPortI(PDDDR, &PDDDRShadow, mode, 3); /* Configures PD3 */
BitWrPortI(PDDDR, &PDDDRShadow, mode, 6); /* Configures PD6 */
BitWrPortI(PDDDR, &PDDDRShadow, mode, 7); /* Configures PD7 */
}

void Set_DTMF_bus(int r)
{
BitWrPortI(PDDR, &PDDRShadow, r & 0x01,0);  /* Set PD0 */
BitWrPortI(PDDR, &PDDRShadow, (r & 0x02) >> 1,3); /* Set PD3 */
BitWrPortI(PDDR, &PDDRShadow, (r & 0x04) >> 2,6); /* Set PD6 */
BitWrPortI(PDDR, &PDDRShadow, (r & 0x08) >> 3,7); /* Set PD7 */
}

int Get_DTMF_bus(void)
{
  int d1,d2,d3;
d1=BitRdPortI(PDDR,3);
d2=BitRdPortI(PDDR,6);
d3=BitRdPortI(PDDR,7);
   return BitRdPortI(PDDR,0) + (d1<<1) + (d2<<2) + (d3<<3);
}

void Set_DTMF_CS(int r)
{
    WrBitDemux(2, r, 1);
}

void Set_DTMF_WR(int r)
{
   WrBitDemux(2, r, 0);
}

void Set_DTMF_RD(int r)
{
   WrBitDemux(2, r, 3);
}

void Set_DTMF_RSO(int r)
{
   WrBitDemux(2, r, 2);
}

root void chip_delay(void)
{
int i;
for(i=0;i<CHIP_DELAY;i++);
    /* do nothing */
}

void DTMF_Tx_Tone(int tone)
{
  Set_DTMF_bus_mode(OUTPUT);
   Set_DTMF_RSO(0);
   Set_DTMF_bus(tone);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus_mode(INPUT);
}

void knightRider()
{
  int i, n;
   int loopCount;

   loopCount = 0;
   for(i = 0; i <= 7 && loopCount < 7; i++) {
    WrBitDemux(2, 1, i);
      msDelay(100);
      WrBitDemux(2, 0, i);
      msDelay(100);

      if(i == 7) {
      for(n = 6; n >= 0; n--) {
        WrBitDemux(2, 1, n);
        msDelay(100);
        WrBitDemux(2, 0, n);
        msDelay(100);
         }

         if(n == -1) {
     
i = 1;
      
loopCount++;
         }
      }
   }
}

root interrupt void dtmfIntHandler(void)
{
  int status;
   int digit;

   printf("interrupt\n");

   Set_DTMF_bus_mode(INPUT);
   Set_DTMF_WR(1);
Set_DTMF_RSO(1);
   Set_DTMF_RD(0);
   chip_delay();
   status = Get_DTMF_bus();
   chip_delay();
   Set_DTMF_RD(1);

   if ((status & 0x04) >> 2)
   {
    Set_DTMF_RSO(0);
      Set_DTMF_RD(0);
      chip_delay();
      digit=Get_DTMF_bus();
      chip_delay();
      Set_DTMF_RD(1);

      printf("Rcd: %d\r\n",digit);
}
}

void main()
{
int c;
   WrPortI(SPCR, &SPCRShadow, 0x84); 
  /* Port A as an output */
   BitWrPortI(PEDDR, &PEDDRShadow, INPUT, 4);  
/* Pin PE4 as input */
   BitWrPortI(PEDDR, &PEDDRShadow, OUTPUT, 5); 
/* Pin PE5 as output */

    /*************************************************************************/
   /* THE FOLLOWING SECTION RESETS THE DTMF CHIP 
   */
   /*************************************************************************/

   Set_DTMF_bus_mode(INPUT);
   Set_DTMF_CS(0);
   Set_DTMF_RSO(1);
   Set_DTMF_RD(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus_mode(OUTPUT);
   Set_DTMF_bus(0x00);
   msDelay(1);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus(0x08);
   msDelay(1);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus(0x00);
   msDelay(1);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);


   Set_DTMF_bus_mode(INPUT);
   Set_DTMF_RD(0);  /* Read from the chip to clear flags */
   msDelay(1);
   Set_DTMF_RD(1);

   /*** Now we configure the DTMF tx mode *///
   Set_DTMF_bus_mode(OUTPUT);
   Set_DTMF_bus(0x0D);
   msDelay(1);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus(0x00);
   msDelay(1);
   Set_DTMF_WR(0);
   msDelay(1);
   Set_DTMF_WR(1);
   Set_DTMF_bus_mode(INPUT);


   /******** End of Reset ******/

   SetVectExtern3000(0, dtmfIntHandler);
   WrPortI(I0CR, &I0CRShadow, 0x1b);

   printf("Program Running...");  /* Forces the console to open */
   while(1)
{
      if (kbhit())  /* Console commands used for testing */
    {
      c=getchar();
         switch (c)
         {
            case '0':  DTMF_Tx_Tone(10); break;
            case '1':  DTMF_Tx_Tone(1); break;
            case '2':  DTMF_Tx_Tone(2); break;
            case '3':  DTMF_Tx_Tone(3); break;
            case '4':  DTMF_Tx_Tone(4); break;
            case '5':  DTMF_Tx_Tone(5); break;
            case '6':  DTMF_Tx_Tone(6); break;
            case '7':  DTMF_Tx_Tone(7); break;
            case '8':  DTMF_Tx_Tone(8); break;
            case '9':  DTMF_Tx_Tone(9); break;
            case 'a':  Set_DTMF_CS(0); break;
            case 'A':   Set_DTMF_CS(1);
break;
            case 'b':  Set_DTMF_WR(0); break;
            case 'B':  Set_DTMF_WR(1); break;
            case 'c':  Set_DTMF_RD(0); break;
            case 'C':   Set_DTMF_RD(1);
break;
            case 'd':  Set_DTMF_RSO(0); break;
            case 'D': Set_DTMF_RSO(1);
break;
            case 'k':   knightRider();
break;
         } /* End of switch instruction */
      } /* End of Kbhit() */
   } /* End of while loop */
} /* End of main program */