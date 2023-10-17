#ifndef SMELIB_H
#define SMELIB_H

#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Servo.h>

#define DEBUG_PRINTER Serial
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }

/* Bluetooth - inheritance: SoftwareSerial */
class Bluetooth : public SoftwareSerial
{
public:
  Bluetooth(uint8_t tx, uint8_t rx);
  void setName();          
  void begin(long speed);  
  virtual int read();      
  virtual int available(); 
private:
  uint8_t _tx;
  uint8_t _rx;
};

/* Buzzer */
class Buzzer
{
public:
  Buzzer(uint8_t pin);
  void note(char key, unsigned long  = 1000);
private:
  uint8_t _pin;
};

/* RGB LED */
class RGBLed
{
public:
  RGBLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin); 
  void setColor(int r, int g, int b);                        

private:
  int _state;
  uint8_t _redPin;
  uint8_t _greenPin;
  uint8_t _bluePin;
};

#endif