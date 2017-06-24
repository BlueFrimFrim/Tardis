#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <Adafruit_LEDBackpack.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include "Arduino.h"


const uint8_t g_seg0[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const uint8_t g_seg1[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const uint8_t g_seg3[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '*', 'H' };

void init_display(Adafruit_AlphaNum4 *display);
void rst_display(Adafruit_AlphaNum4 *display);
void display_counter(Adafruit_AlphaNum4 *display, uint8_t increment);

#endif