#ifndef SMELIB_BLUETOOTH_CPP
#define SMELIB_BLUETOOTH_CPP

#include "SMELib.h"

Bluetooth::Bluetooth(uint8_t tx, uint8_t rx) : SoftwareSerial(tx, rx)
{
  _tx = tx;
  _rx = rx;
}

void Bluetooth::setName()
{
  while (1)
  {
    if (DEBUG_PRINTER.available())
    {
      SoftwareSerial::write(DEBUG_PRINTER.read());
    }
    if (SoftwareSerial::available())
    {
      DEBUG_PRINTER.write(SoftwareSerial::read());
    }
  }
}

void Bluetooth::begin(long speed)
{
  return SoftwareSerial::begin(speed);
}

int Bluetooth::read()
{
  return SoftwareSerial::read();
}

int Bluetooth::available()
{
  return SoftwareSerial::available();
}

#endif