#include "Arduino.h"

class Timeout_t{

    unsigned long gstart;
    unsigned long gtime;
	int gflg;

public:
    Timeout_t(unsigned long timeout_value);
	void set_timeout();
	void set_flg();
	int status();
	void clear_flg();
	int check();
};