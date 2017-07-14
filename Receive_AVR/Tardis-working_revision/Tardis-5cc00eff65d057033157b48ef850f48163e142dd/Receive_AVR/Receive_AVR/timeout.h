#include "Arduino.h"

class Timeout_t{

    unsigned long gstart;
    unsigned long gtime;

public:
    Timeout(unsigned long timeout_value);
    void set_timeout();
    int check();
}