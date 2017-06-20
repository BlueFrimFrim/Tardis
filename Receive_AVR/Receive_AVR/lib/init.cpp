#include "includes/init.h"


/*
 * num_init_func - calculates the amount of functions in init()
 * @func - calulate number of init functions
 *
 * @return - size of init() functions
 */
int num_init_func(void) 
{
	return sizeof(init) / sizeof(char *);
}