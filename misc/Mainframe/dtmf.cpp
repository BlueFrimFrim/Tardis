#include "mbed.h"



//-------------------------------------------------------------------------
// Pin Definitions
DigitalInOut DTMF_D3(PC_9);
DigitalInOut DTMF_D2(PC_8);
DigitalInOut DTMF_D1(PB_8);
DigitalInOut DTMF_D0(PC_6);
DigitalInOut DTMF_RS0(PC_5);
DigitalInOut DTMF_RW(PA_5);
DigitalInOut DTMF_notCS(PA_12);

DigitalOut myled(LED1);

InterruptIn notIRQ(PB_9);

Serial pc(USBTX, USBRX); /*USB serial coms */

int main() {
    pc.printf("Tardis Initializing...\r\n");
    while (true) {
        pc.printf("Loop...\r\n");
        wait_ms(100);
        receiveDTMF();
    }
}

//-------------------------------------------------------------------------
// Functions
int
receiveDTMF(void)
{
    ledBlink();
    int value = 0;
    wait_ms(500);
    if(irqFlg){
        irqFlg = 0;
        for(int i = 0; i < 6; i++){
            value = concatenate(TonesRx[i], TonesRx[i+1]);
        }
        pc.printf("TonesRx = %d\r\n", value);
    }
    return 0;
}

int
generateDTMF(void)
{
    return 0;
}

void
setupDTMF(void)
{
    memset(TonesRx, 0, sizeof(TonesRx));
    busMode(WRITE);
    reset();
    pc.printf("DTMF setup complete.\r\n");
    wait_ms(100);
    return;
}

void
initializeMT8880C(void)
{
    /*
     * Receive Tone Setup
     * bus mode -> write 
     * pin mode -> notIRQ, input
     * pin mode -> rs0, output
     * pin mode -> notCS, output
     * pin mode -> rw, output
     * reset
     * delay 100ms
     */
}

void
reset(void)
{
    wait_ms(100); /* wait 100ms */
    controlRegister_write(0x00);
    controlRegister_write(0x00);
    controlRegister_write(0xC);
    controlRegister_write(0x00);
    statusRegister_read();
}

void
transmitRegister_write(unsigned char value)
{
    busWrite(value);
    DTMF_RS0.write(0);
    DTMF_RW.write(0);
    DTMF_notCS.write(0);
    DTMF_notCS.write(1);

    return;
}

unsigned char
receiveRegister_read(void)
{
    unsigned char ToneReceived = 0;

    busMode(READ);
    DTMF_RW.write(1);
    DTMF_RS0.write(0);
    DTMF_notCS.write(0);
    ToneReceived = busRead();

    return ToneReceived;
}

void
busMode(unsigned char mode)
{
    if(mode == WRITE){
        DTMF_D0.output();
        DTMF_D1.output();
        DTMF_D2.output();
        DTMF_D3.output();
    }
    else if(mode == READ){
        DTMF_D0.input();
        DTMF_D1.input();
        DTMF_D2.input();
        DTMF_D3.input();
    }

    return;
}

void
busWrite(unsigned char value)
{
    busMode(WRITE);
    bitWrite(&DTMF_D3, value);
    bitWrite(&DTMF_D2, value);
    bitWrite(&DTMF_D1, value);
    bitWrite(&DTMF_D0, value);

    return;
}

unsigned char 
busRead(void)
{
    byte value = 0;
    
    busMode(READ);

    value = value << 1;
    value = value ^ bitRead(&DTMF_D3);

    value = value << 1;
    value = value ^ bitRead(&DTMF_D2);

    value = value << 1;
    value = value ^ bitRead(&DTMF_D1);

    value = value << 1;
    value = value ^ bitRead(&DTMF_D0);

    return value;
}

void
controlRegister_write(unsigned char value)
{
    busWrite(value);
    DTMF_notCS.write(0);
    DTMF_RS0.write(1);
    DTMF_RW.write(0);
    DTMF_notCS.write(1);

    return;
}

unsigned char 
statusRegister_read(void)
{
    byte value = 0;
    busMode(READ);
    DTMF_RW.write(1);
    DTMF_RS0.write(1);
    DTMF_notCS.write(0);

    value = busRead();

    DTMF_notCS.write(1);

    return value;
}

float
concatenate(float x, float y)
{
    return x * pow(10, log10(y) + 1) + y;
}

unsigned char
bitRead(DigitalInOut *pin_t)
{
    byte value = 0;
    value = pin_t->read();
    return value;
}

void
bitWrite(DigitalInOut *pin_t, byte value)
{
    pin_t->write(value);
    return;
}

void
irq_printReceived(void)
{
    if(irq_delay == 1){
        irqFlg = 1;
        receiveRegister_read();
        if(ToneReceived == star){
            TonePosition = 0;
        }
        TonePosition[TonesRx] = ToneReceived;
        TonePosition++;
        if(TonePosition == 7){TonePosition = 0;}
        statusRegister_read();      
        irq_delay = 2;
        if(ToneReceived == hash){;}
    }
    else{irq_delay = 1;}
}

void
ledBlink(void)
{
    myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
        return;
}