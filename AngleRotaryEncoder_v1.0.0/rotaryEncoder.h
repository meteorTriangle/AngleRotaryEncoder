/*
  rotaryEncoder.h - Library for rotaryEncoder code.
  Created by Angle Tsai, September 21, 2021.
  Released into the public domain.
*/

#ifndef rotaryEncoder_h
#define rotaryEncoder_h

#include "Arduino.h"
class rotaryEncoder {
  private:
    uint8_t PhaseCLK, PhaseDT;
    int counter;
    bool aState;
    bool aLastState;
  public:
    void setCLK(uint8_t);
    void setDT(uint8_t);
    void setPhase(uint8_t, uint8_t);
    void init();
    void startCounter();
    void run();
    void resetCounter();
    void stopCounter();
    int read();
};
void rotaryEncoder::setCLK(uint8_t CLKpin){ PhaseCLK = CLKpin; }
void rotaryEncoder::setDT(uint8_t DTpin){ PhaseDT = DTpin; }
void rotaryEncoder::setPhase(uint8_t CLKpin, uint8_t DTpin) {
  PhaseCLK = CLKpin;
  PhaseDT = DTpin;
}
void rotaryEncoder::init(){
  pinMode(PhaseCLK, INPUT);
  pinMode(PhaseDT, INPUT);
}
void rotaryEncoder::startCounter(){
  counter = 0;
  aLastState = digitalRead(PhaseCLK);
}
void rotaryEncoder::run(){
  aState = digitalRead(PhaseCLK);

  if (aState != aLastState){

    if (digitalRead(PhaseDT) != aState) {
      counter ++;
    } else {
      counter --;
    }
  }
  aLastState = aState;
}
void rotaryEncoder::resetCounter(){
  detachInterrupt(PhaseCLK);
  counter = 0;
  aLastState = digitalRead(PhaseCLK);
}
void rotaryEncoder::stopCounter(){
  detachInterrupt(PhaseCLK);
}
int rotaryEncoder::read(){
  return(counter);
}


#endif
