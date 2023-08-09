#ifndef SoftTimer_h
#define SoftTimer_h

#include <Arduino.h> 

class SoftTimer {
  
  public:

    SoftTimer(void);
    SoftTimer(unsigned long);
    void set(unsigned long);
    void start(void);
    void start(unsigned long);
    boolean elapsed(void);
 
  private:  
    unsigned long   startTime=0;
    unsigned long   timeout=0;
  
};

#endif 
