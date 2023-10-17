#ifndef SMELIB_RGBLED_CPP
#define SMELIB_RGBLED_CPP

#include "SMELib.h"

RGBLed::RGBLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
  _state = 0;
}

void RGBLed::setColor(int r, int g, int b)
{
  if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    DEBUG_PRINTLN("invalid value"); 
  analogWrite(_redPin, r);
  analogWrite(_greenPin, g);
  analogWrite(_bluePin, b);
}

#endif