#ifndef CAR_H
#define CAR_H

#include "Wire.h"
#include "Arduino.h"
#include "Keyboard_small.h"
#include "myservo.h"
#include "LCDX.h"
#include "distance_sensor.h"
#include "eeprom.h"
#include "toroi_new.h"

class car 
          { 
            public:   
                  car();
                  ~car();
                  static LCDX LC;
                  int min_rotate=20;
                  int max_rotate=35;
                  laser lasers_left;
                  laser lasers_right;
                  eeprom eeprom_pd_control;
                  keyboards keyboards1;
                  UltraSonic_3_pin *UltraSonic_3_pin_forward;  //23 is the pin number of UltraSonic of singal
                  UltraSonic_3_pin *UltraSonic_3_pin_back;     //25 is the pin number of UltraSonic of singal
                  
                  int basic_speed=50;
                  int mult=1;
                  int distance_mult=1;
                 
                  double fix_degree(double mult , bool enabled );
                  double fix_distance(double distance_mult, bool enabled);
                  double get_degree();
                  int keyboard_event(bool enamled , int *change_value_1);
                  
                  int now_degree;
                  int degree;
            
                  int PD_control;
                  int target_distance=80;
                  int distance;
                  void set_speed(int right_speed,int left_speed,  int right_speed_plus,int left_speed_plus );
                  int get_forward_distance(int pin_set);
                  int get_back_distance(int pin_set) ;
                  int control_space=20;
                  int max_distance=150;
                  
                  int rotate(int degree_in);
                  int degree_offest=0;
                  bool find_wall_or_rotate=true;
                  bool reverse_find_wall=false;
                  int all_fix(int mult_in ,int distance_mult_in, bool speed_set_enabled);
                 
           };
     


           
#endif
