#include "C:/Tardis/library/tardis.h"

t_buffer tone_buff;
uint8_t tone_data[TONE_SIZE];

volatile t_sysflgs sysflgs;

void setup() {
  // put your setup code here, to run once:
  BufferInit(&tone_buff, tone_data, (uint16_t)TONE_SIZE);
}

void loop() {
  if(sysflgs.irq_flg){
    sysflgs.irq_flg = 0;
    
  }
}
