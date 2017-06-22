#pragma once

#include "Arduino.h"

struct irq_data {
	unsigned int irq;
};

extern void irq_event(void);