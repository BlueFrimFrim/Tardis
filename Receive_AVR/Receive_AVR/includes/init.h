#ifndef _INIT_H
#define _INIT_H


#include "includes/tardis.h"

void(*init[]) (void) = {
	dtmf_init
};

int num_init_func(void);

#endif
