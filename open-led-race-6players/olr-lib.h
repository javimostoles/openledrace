
#ifndef _OLR_LIB_h
#define _OLR_LIB_h                   

#ifdef __cplusplus

extern "C"{
#endif

#include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include "olr-controller.h"
#include "olr-param.h"


#define SPD_MIN_TRACK_AUX       0.8   // change track by low speed
//#define BATTERY_DELTA           0.03  // Decrease BATTERY_DELTA on each controller activation - used in charge rate too
//#define BATTERY_DELTA           3     // unsigned char value [1-254] / will be divided by 100 [0.01-2.54]
//#define BATTERY_MIN             60    // Battery does not descharge below BATTERY_MIN
//#define SPEED_BOOST_SCALER      10 

enum stcoin{ 
  COIN_RESET = -2,
  COIN_WAIT  = -1,
};

enum{
  NOT_TRACK = 0,
  TRACK_MAIN,
  TRACK_AUX,
  TRACK_IN,
  TRACK_OUT,
  NUM_TRACKS,
};


enum status{
    CAR_WAITING = 0,
    CAR_COMING,
    CAR_ENTER,
    CAR_RACING,
    CAR_LEAVING,
    CAR_GO_OUT,
    CAR_FINISH
};

typedef struct{
    controller_t* ct;
    float speed;
    float dist;
    float dist_aux;
    byte nlap;
    byte repeats;
    uint32_t color;
    uint8_t trackID;
    enum status st;
    bool leaving;
    float battery;
    bool charging;
}car_t;



typedef struct {
  struct cfgparam cfg;
  int ledcoin;      //LED_SPEED_COIN
  uint32_t ledtime;
  bool rampactive;
  bool boxactive;
}track_t;


void car_init( car_t* car, controller_t* ct, uint32_t color );

void car_updateController( car_t* car );

void car_resetPosition( car_t* car);

void update_track( track_t* tck, car_t* car );

void process_main_track( track_t* tck, car_t* car );

void process_aux_track( track_t* tck, car_t* car );

void box_init( track_t* tck );

bool box_isactive( track_t* tck );

int tracklen_configure( track_t* tck, int nled );

int autostart_configure( track_t* tck, int autostart );

int players_n_configure( track_t* tck, int val );

int boxlen_configure( track_t* tck, int box_len, int boxalwaysOn );

int physic_configure( track_t* tck,  float kgp,  float kfp );

int  track_configure( track_t* tck, int init_box );

void ramp_init( track_t* tck );

bool ramp_isactive( track_t* tck );

int  ramp_configure( track_t* tck, int init, int center, int end, uint8_t high, int alwaysOn );

int  battery_configure( track_t* tck, int delta, int min, int boost, int active );

int  race_configure( track_t* tck, int startline, int nlap, int nrepeat, int finishline );

#ifdef __cplusplus
} // extern "C"
#endif

#endif
