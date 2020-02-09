#ifndef CAPCTRL_H
#define CAPCTRL_H

#include <Arduino.h>
#include <Stepper.h>
#include <EEPROM.h>

class CapCtrl 
{
public:
  CapCtrl(int steps, int pin1, int pin2, int pin3, int pin4, int pinBtn);
  
  void setFreq(int freqKhz);
  
  void setPos(int newPos);
  void park();
  
  void up();
  void down();

private:
  void release();
  void calibrate(int freqKhz, int pos);
  
private:
  const int ConfigSpeed = 64;
  const int ConfigStep = 100;
  const int ConfigMaxPos = 5200;

  const int ConfigCalPoints = 10;
  const int ConfigCalAddr = 0x0;

private:
  Stepper stepper_;
  int pin1_, pin2_, pin3_, pin4_, pinBtn_;
  int pos_;
};

#endif // CAPCTRL_H
