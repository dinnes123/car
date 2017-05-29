#include "mission.h" //include the declaration for this class

mission::mission()
      {
          my_car.basic_speed=30;
          my_car.mult=1;
          my_car.distance_mult=1;
          my_car.degree_offest=0;
          my_car.lasers_left.laser_pin=A0;
          my_car.lasers_right.laser_pin=A1; 
          next_mission=0;
          back_mission=0;
        }
mission::~mission(){}

