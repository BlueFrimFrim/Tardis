#include "tardis.h"

/* Version: 0v00 */

void
InitializeDTMF(t_mt8880c *mt8880c)
{
  BusMode(mt8880c, WRITE);
  pinMode(mt8880c->not_irq, INPUT);
  pinMode(mt8880c->rs0, OUTPUT);
  pinMode(mt8880c->not_cs, OUTPUT);
  pinMode(mt8880c->rw, OUTPUT);
  Reset(mt8880c);
  return;
}

