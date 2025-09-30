#include "helper.h"

const int NUM_LEDS = 32;  
byte ledStates[NUM_LEDS]; 

// Turn all LEDs off
void clearAll() {
  for (int i = 0; i < NUM_LEDS; i++) {
    ledStates[i] = 0;
  }
}

// Update the shift registers based on ledStates[]
void updateShiftRegisters() {
  byte registers[4] = {0,0,0,0};

  for (int i = 0; i < NUM_LEDS; i++) {
    int reg = i / 8;     
    int bit = i % 8;     
    if (ledStates[i]) registers[reg] |= (1 << bit);
  }

  digitalWrite(3, LOW);  // LATCH_PIN
  for (int i = 3; i >= 0; i--) {
    shiftOut(2, 4, MSBFIRST, registers[i]);  // DATA_PIN, CLOCK_PIN
  }
  digitalWrite(3, HIGH);
}

// Light up a custom set of LEDs for 1 second
void lightCustom(int leds[], int length) {
  clearAll();
  for (int i = 0; i < length; i++) {
    ledStates[leds[i]] = 1;
  }
  updateShiftRegisters();
  delay(10000);
}