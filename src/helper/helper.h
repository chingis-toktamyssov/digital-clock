#ifndef LEDHELPERS_H
#define LEDHELPERS_H

#include <Arduino.h>

extern const int NUM_LEDS;
extern byte ledStates[];

// Declare helper functions
void clearAll();
void updateShiftRegisters();
void lightCustom(int leds[], int length);

#endif