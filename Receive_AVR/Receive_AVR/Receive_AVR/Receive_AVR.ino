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
uint8_t tone_data[TONE_SIZE];

volatile t_sysflgs sysflgs;

t_mt8880c mt8880c_rx;

volatile int g_last_irq, g_current_irq = 0;

unsigned long five_minutes = 5 * 1000;

Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();
Timeout_t dtmf_timer = Timeout_t(five_minutes);

unsigned long previousMillis;
char stableVals;

int temp2 = 0;
int temp = 0;
unsigned long g_timeout_now;
unsigned long timeout_10s = 10000; 

uint8_t data = 0;
int counter = 0;
int timer_status = 0;

/*----------------------------------------------*/
/*----------------------------------------------*/
/* INTERRUPT: Tone received */
void
IRQ_ToneReceived(void)
{		
	g_current_irq = millis();
	if (g_current_irq - g_last_irq > 100) {
		if (ReadIrqBit(&mt8880c_rx)) {
			sysflgs.irq_flg = 1;
			dtmf_timer.set_timeout();
			g_last_irq = g_current_irq;
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
#if 1
	if (counter == 99) { counter = 0; }
	UpdateDisplayCounter(&display, counter++);

	if (dtmf_timer.status()) {
		if (dtmf_timer.check()) {
			BufferReset(&tone_buff);
			dtmf_timer.clear_timeout();
		}
	}

	if (sysflgs.irq_flg) {
		sysflgs.irq_flg = 0;
		data = ReadReceiveRegister(&mt8880c_rx); /* Read the tone which triggered interrupt. */
		BufferWrite(&tone_buff, data);
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
