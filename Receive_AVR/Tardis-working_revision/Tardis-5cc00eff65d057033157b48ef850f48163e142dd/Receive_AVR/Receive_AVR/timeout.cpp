#include "timeout.h"

Timeout::timeout(unsigned long timeout_value)
{
    gstart = 0;
    gtime = timeout_value;
}

Timeout::set_timeout()
{
    gstart = millis();
}

Timeout::check()
{
    unsigned long now = millis();
    unsigned long elapsed = now - gstart;

    if(elapsed > gtime)
    {
        return 1;
    }
    return 0;
}