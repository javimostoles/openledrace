#include "olr-param.h"

void param_setdefault( struct cfgparam* cfg ) {
    cfg->ver      = CFGPARAM_VER;

    cfg->race.startline = true;   
    cfg->race.nlap = NUMLAP;  
    cfg->race.nrepeat = 1;
    cfg->race.finishline = true;

    param_option_set(cfg, BATTERY_MODE_OPTION, BATTERY_MODE); 
    cfg->battery.delta =  2;
    cfg->battery.min   = 60;
    cfg->battery.speed_boost_scaler = 10;

    param_option_set(cfg, AUTOSTART_MODE_OPTION, AUTOSTART_MODE); 

    cfg->ramp.init   = 80; // COMIENZO DE RAMPA
    cfg->ramp.center = 90;
    cfg->ramp.end    = 100;
    cfg->ramp.high   = 5; // 4 DIFICIL - 3 MEDIO - 2 FÁCILs. RAMPAA
    param_option_set(cfg, SLOPE_MODE_OPTION, SLOPE_ALWAYS_ON);

    cfg->track.nled_total = MAXLED;  // MAXLED: Total LED number in the racetrack (default:300 -> 5mt, 60LED/mt Strip)
    cfg->track.nled_main  = MAXLED; // 240 when boxes length = 60
    cfg->track.nled_aux   = 0; // 60 
    cfg->track.init_aux   = -1;  // 239   
    cfg->track.box_len    = BOXLEN;
    param_option_set(cfg, BOX_MODE_OPTION, BOX_ALWAYS_ON); 
    
    cfg->track.kf         = 0.015; // 0.015 friction constant
    cfg->track.kg         = 0.006; // 0.006 gravity constant  - Used in Slope

    param_option_set(cfg, PLAYER_3_OPTION, PLAYER_3);
    param_option_set(cfg, PLAYER_4_OPTION, PLAYER_4);
    param_option_set(cfg, PLAYER_5_OPTION, PLAYER_5);
    param_option_set(cfg, PLAYER_6_OPTION, PLAYER_6);
    
}

void param_option_set( struct cfgparam* cfg, uint8_t option, boolean value ) {
  bitWrite(cfg->option, option, value);
}
boolean param_option_is_active( struct cfgparam* cfg, uint8_t option) {
  return(bitRead(cfg->option, option));
}
