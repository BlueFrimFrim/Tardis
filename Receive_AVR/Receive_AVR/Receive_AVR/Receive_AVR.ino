/*
 Name:		Receive_AVR.ino
 Created:	5/29/2017 6:39:36 PM
 Author:	Keegan-Dev
*/

/*----------------------------------------------*/
/* TARDIS LIBRARIES */
#include "tardis.h"

#define CHECK_EVERY_MS 10
#define MIN_STABLE_VALS 1

t_buffer tone_buff;
t_mt8880c mt8880c_rx;
volatile t_sysflgs sysflgs;

volatile uint8_t tone_data[TONE_SIZE];
volatile unsigned long g_last_irq, g_current_irq = 0;

unsigned long five_minutes = 5 * 1000;

Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();

Timeout_t dtmf_timer = Timeout_t(five_minutes);

volatile unsigned long irq_time = 0;

const unsigned long timeout_10s = 10000; 

volatile uint64_t Command = 0;

/*----------------------------------------------*/
/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{	
	unsigned long time_now = millis();	

	if (time_now - irq_time > 100) {
		if (ReadIrqBit(&mt8880c_rx)) {
			sysflgs.irq_flg = 1;
			dtmf_timer.set_timeout();
			irq_time = time_now;
		}
	}
}
/*----------------------------------------------*/
/*----------------------------------------------*/


void setup() {
	BufferInit(&tone_buff, tone_data, (uint16_t)TONE_SIZE);
	MT8880C_RX_Init(&mt8880c_rx);
	InitializeDTMF(&mt8880c_rx);
	delay(100);

	sysflgs.irq_flg = 0;

	attachInterrupt(digitalPinToInterrupt(mt8880c_rx.not_irq), IRQ_ToneReceived, CHANGE);

	Serial.begin(9600); /* Serial communication */
	Wire.begin(); /* I2C communication */
	while (!Serial);
	Serial.println("Tardis Initialized.");
	SetupDisplay(&display);
	ReadStatusRegister(&mt8880c_rx);
}

// the loop function runs over and over again until power down or reset
void loop() {
	uint8_t data = 0;
	int counter = 0;

#if 1
	if (counter == 99) { counter = 0; }

	UpdateDisplayCounter(&display, counter++);
#if 0
	if (dtmf_timer.status()) {
		if (dtmf_timer.check()) {
			BufferReset(&tone_buff);
			dtmf_timer.clear_timeout();
		}
	}
#endif
	if (sysflgs.irq_flg) {
		sysflgs.irq_flg = 0;
		data = ReadReceiveRegister(&mt8880c_rx); /* Read the tone which triggered interrupt. */
		Serial.print("data: ");
		Serial.println(data);
//		BufferWrite(&tone_buff, data);
//		Serial.print("Buffer: ");
//		Serial.println(BufferRead(&tone_buff));
		ProcessTone(data);
		UpdateDisplayTone(&display, data); /* Update segment display */
		ReadStatusRegister(&mt8880c_rx); /* Clear interrupt register. */		
		dtmf_timer.clear_timeout();
		Serial.println(F("Interrupt"));
	}
#endif

#if 0
		if (temp == 0) {
				temp = 1;
				Serial.print(F("temp = "));
				Serial.println(temp);
		}

		if (temp == 1) {
			start = millis();
			temp = 2;
			Serial.print(F("temp = "));
			Serial.print(temp);
			Serial.print(F(" | start = "));
			Serial.println(start);
		}
		unsigned long now;
		unsigned long timeout = 300000;
		if (temp == 2) {
			now = millis();
		}
		unsigned long elapsed = now - start;
		Serial.print(F("elapsed = "));
		Serial.println(elapsed);
		if (elapsed >= timeout)
		{
			temp = 3;
			Serial.println(F("5 minutes has occured."));
			while (1) { ; }
		}
		if (timer_status) {
			Serial.print(F("Timer Status:"));
			Serial.println(timer_status);
			Serial.println((millis()));
			if (dtmf_timer.check()) {
				//BufferReset(&tone_buff);
				Serial.println(F("Timeout1: Resetting..."));
				dtmf_timer.clear_flg();
			}
		}
#endif
}

void
ProcessTone(uint8_t data)
{
	uint8_t tone_in = data;
	//tone_in = BufferRead(buffer); /* Read tone received. */
	//Serial.print("tone_in: ");
	//Serial.println(tone_in);
	
	if (tone_in == g_hash) {
		if (Command == g_star) { return; }
		else { ExecuteCommand(Command); }
	}
	if (tone_in == g_star) { Command = tone_in; }
	else { Command = Concatenate(Command, tone_in); }
}

void
ExecuteCommand(uint64_t command)
{
	switch (command) {
	case 11123:
		Serial.println("command 1123 sending...");
		Wire.beginTransmission(7);
		Wire.write(0x02);
		Wire.endTransmission();
		delay(100);
		break;
	case 112468:
		Wire.beginTransmission(7);
		Wire.write(0x03);
		Wire.endTransmission();
		delay(100);
		break;
	default:
		Wire.beginTransmission(7);
		Wire.write(0x01);
		Wire.endTransmission();
		delay(100);
		break;
	}
}
