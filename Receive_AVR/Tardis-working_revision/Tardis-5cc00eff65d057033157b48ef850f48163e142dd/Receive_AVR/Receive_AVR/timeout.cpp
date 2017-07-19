#include "timeout.h"

Timeout_t::Timeout_t(unsigned long timeout_value)
{
    gstart = 0;
	gflg = 0;
    gtime = timeout_value;
}

void Timeout_t::set_timeout()
{
    gstart = millis();
}

void Timeout_t::set_flg()
{
	gflg = 1;
}

int Timeout_t::status()
{
	return gflg;
}

void Timeout_t::clear_flg()
{
	gflg = 0;
	gstart = 0;
}

int Timeout_t::check()
{
    unsigned long now = millis();
    unsigned long elapsed = now - gstart;

    if(elapsed > gtime)
    {
        return 1;
    }
    return 0;
}