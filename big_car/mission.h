#ifndef MISSION_H
#define MISSION_H

#include "mission.h" //include the declaration for this class
#include "car.h"

class mission 
          { 
            public:   
      				mission();
      				~mission();
      				mission *next_mission;
      				mission *back_mission;
      				car my_car;
             
      				virtual int run()=0;
      				bool distance_fix_enabled=true;
      				bool degree_fix_enabled=true;
              int mission_number=0;
             
           };
class mission_1 : public mission
          {
            public:  
                mission_1();
                ~mission_1();
                int flower_stop=95;
                int run();
                
          };
class mission_2 : public mission
          {
            public:  
                mission_2();
                ~mission_2();
                int run();
          };
class mission_3 : public mission
          {
            public:  
                mission_3();
                ~mission_3();
                int temp_target;
                int run();
          };
class mission_4 : public mission
          {
            public:  
                mission_4();
                ~mission_4();
                int run();
          };
class mission_5 : public mission
          {
            public:  
                mission_5();
                ~mission_5();
                int abs_stop=0;
                int run();
          };    
class mission_6 : public mission
          {
            public:  
                mission_6();
                ~mission_6();
                int run();
          };   
class mission_7 : public mission
          {
            public:  
                mission_7();
                ~mission_7();
                int flower_catch=90;
                int run();
                Servo myservo1;
                Servo myservo2;
                int n=0;
          };   
#endif
