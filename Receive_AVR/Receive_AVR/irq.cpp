#include "irq.h"

static unsigned int irq_timer = 0;

void irq_event(void)
{
	int t = millis();
	if (t - irq_timer > 100) {
		irq_state = 1;
		irq_timer = t;
	}
}