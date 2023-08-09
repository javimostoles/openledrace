#include "SoftTimer.h"

SoftTimer::SoftTimer(unsigned long tout) {
  this->set(tout);
}

SoftTimer::SoftTimer() {
}

/*
 * 
 */
void SoftTimer::set(unsigned long tout) {
  this->timeout=tout;
}


void SoftTimer::start() {
  this->startTime=millis();
}

void SoftTimer::start(unsigned long tout) {
  this->set(tout);
  this->start();
}


/*
 * 
 */
boolean SoftTimer::elapsed(){
  if((millis() - this->startTime) > this->timeout) {
    return(true);
  }
  return(false);
}
