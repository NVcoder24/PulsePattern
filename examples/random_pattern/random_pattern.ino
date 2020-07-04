//
//    FILE: random_pattern.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2020-07-04
//
// PUPROSE: demo of the PulsePattern Library
//          uses timer1
//

#include "PulsePattern.h"

// a pattern consts of durations of LOW and HIGH periods
// so the first line of the SOSpattern
// 500 units LOW, 500 units HIGH etc
// for a dutycycle of 50% LOW and HIGH should have equal periods
// NOTE max period = 4095.
// min period = about 12
uint16_t random_pattern[] = { 500, 500 };
uint8_t patternSize = 2;
uint8_t startLevel = LOW;

void setup()
{
  Serial.begin(115200);
  Serial.println("Start PulsePattern");

  // as the prescaler = 1024 the periods of the pattern are a
  // few percent less than a millecond
  PPGenerator.init(13, random_pattern, patternSize, startLevel, PRESCALE_1024);
  PPGenerator.start();
}

void loop()
{
  random_pattern[0] = 100 + mill() % 1000;
  random_pattern[1] = 100 + micros() % 1000;
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(micros());
  Serial.print('\t');
  Serial.print(random_pattern[0]);
  Serial.print('\t');
  Serial.print(random_pattern[1]);
  Serial.println();
  delay(5000);
}

