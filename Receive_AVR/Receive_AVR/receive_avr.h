#pragma once

#include "Arduino.h"

#include "dtmf.h"

static unsigned int rx_timeout;

void setup_task();
unsigned int *main_task(unsigned int irq_state);
