#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"
#include "helper/helper.h"
#include "digits/digits.h"

#define DATA_PIN 2   // SER (DS)
#define LATCH_PIN 3  // RCLK (ST_CP)
#define CLOCK_PIN 4  // SRCLK (SH_CP)

RTC_DS3231 rtc;

int digitLengths[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial monitor to open

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  clearAll();
  updateShiftRegisters();

  // Uncomment this to manually set the RTC time
  // rtc.adjust(DateTime(2025, 9, 30, 10, 13, 0));
}

void loop() {
  DateTime now = rtc.now();

  int digHourTens   = now.hour() / 10;
  int digHourOnes   = now.hour() % 10;
  int digMinuteTens = now.minute() / 10;
  int digMinuteOnes = now.minute() % 10;

  Serial.print("Hour: ");
  Serial.print(digHourTens);
  Serial.print(digHourOnes);
  Serial.print(" Minute: ");
  Serial.print(digMinuteTens);
  Serial.println(digMinuteOnes);

  int timeDigits[4] = {
    digHourTens,
    digHourOnes,
    digMinuteTens,
    digMinuteOnes
  };

  int lengthDigits[4] = {
    digitLengths[digHourTens],
    digitLengths[digHourOnes],
    digitLengths[digMinuteTens],
    digitLengths[digMinuteOnes]
  };

  int totalLength =
    digitLengths[digHourTens] +
    digitLengths[digHourOnes] +
    digitLengths[digMinuteTens] +
    digitLengths[digMinuteOnes];

  int allDigits[32];
  int cur = 0;

  for (int i = 0; i < 4; i++) {
    int digit = timeDigits[i];
    int length = lengthDigits[i];

    for (int j = 0; j < length; j++) {
      if (i == 0) allDigits[cur + j] = HT[digit][j];
      if (i == 1) allDigits[cur + j] = HO[digit][j];
      if (i == 2) allDigits[cur + j] = MT[digit][j];
      if (i == 3) allDigits[cur + j] = MO[digit][j];
    }

    cur += length;
  }
  allDigits[totalLength] = 8;
  allDigits[totalLength+1] = 21;

  lightCustom(allDigits, totalLength+2);
}