/*
  MCP23S17 Class Example
  Version 0.2
  Cort Buffington 2013
  
  This example will use the methods in both "bit mode", and "byte mode". Also note
  that on the inputs, we use the internal pull-up resistors and an SPST button to
  ground when the button is pushed. While this uses simpler (less expensive) 
  pushbuttons, it does invert the logic. This is a perfect example of one of the 
  more advanced features of the MCP23S17 where we can invert the logic state of 
  the input pins. So, when a button is closed, we read a logic low state, but the 
  chip will report it as a logic high.
  
  In the example, we'll set up one chip. We will set "port A" to be all outputs and
  send to it in "byte mode". "port b" will be split into four inputs and four
  outputs and accessed in "bit mode". For the portA pins, we will indicate the state
  of inputs 0 and 2 on outputs 1 and 3 respectively. PortB will simply flash an LED.
  This is a completely useless program for any real-world application, but 
  demonstrates the functionality of this class, and is a relatively simple example.
  
  A few things are done less efficiently than possible to make the sketch easier to
  follow. The the hardware setup I used to write this example used one 8 position dip
  switch and 8 LEDs.
  
  Be sure to see the companion examples that use "bit mode" and "word-mode"
  exclusively.
*/

#include <SPI.h>              // We use this library, so it must be called here.
#include <MCP23S17.h>         // Here is the new class to make using the MCP23S17 easy.

MCP iochip(1, 10);             // Instantiate an object called "iochip" on an MCP23S17 device at address 1
  							   // and slave-select on Arduino pin 10

void setup() {
  iochip.begin();
  
  iochip.byteWrite(IODIRA, 0x00); //Use byte-write to set all 8 bits of IO Direction register for portB to outputs
  iochip.byteWrite(IODIRB, 0x00); //Use byte-write to set all 8 bits of IO Direction register for portB to outputs
  for(int i = 0; i++; i<16){
    iochip.digitalWrite(i, LOW);
  }
}


void loop() {
  static uint8_t toggle = 0;                      // Set up a static variable for toggling portB on/off
  static uint8_t i = 0;
  // Byte-write "toggle" to portB
  if(i == 16){i == 0;}
  iochip.digitalWrite(i, HIGH);
  delay(200);         
  iochip.digitalWrite(i, LOW);
  i++;
}



