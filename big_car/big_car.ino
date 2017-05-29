#include "mission.h"
mission_1 mission_1_run;
mission_2 mission_2_run;

mission *mission_pointer;
bool mission_flag=false;
void setup()
      {
         Serial.begin(9600);
         mission_pointer=&mission_1_run;
         mission_1_run.next_mission=&mission_2_run;
         mission_2_run.next_mission=0;
      }
void loop()
      { 
            while(!mission_flag)
                {
                  mission_flag=mission_pointer->run();
                }
              car::LC.start("mission ",(double)mission_pointer->mission_number , "complete!" ,(double)0);
              delay(3000);
              if(mission_pointer->next_mission)
                  {
                      mission_pointer=mission_pointer->next_mission;
                      delay(3000);
                  }
              else  
                  {
                      car::LC.start("mission ", "all finished!");
                      delay(9999999);
                  }
              mission_flag=false;
      }


