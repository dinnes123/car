#include "car.h" //include the declaration for this class

void car::set_speed(int right_speed,int left_speed,  int right_speed_plus,int left_speed_plus )
    {
            static servo myservo(2,3);
            myservo.speed_set(right_speed,left_speed,right_speed_plus,left_speed_plus);
    }
    
