#include "mission.h" //include the declaration for this class
mission_6::mission_6() :mission()
    {
        //call constructor of parents class 
        mission_number=6;
        my_car.degree_offest=90;
       
        my_car.mult=1;
        my_car.distance_mult=2;
      
       
        
    }
mission_6::~mission_6()
    {
        
    }
int mission_6:: run()
    {
         int laser_left=my_car.lasers_right.get_distance();
    
     
        int forward=my_car.get_back_distance(23);
       
        delay(2000);
        
        while(forward>10)
              {
                    forward=my_car.get_back_distance(23);
                    my_car.keyboard_event(true, &mission_number);
                    my_car.now_degree=my_car.get_degree();
                    my_car.all_fix(my_car.mult,my_car.distance_mult , true);
                    // car::LC.start("n_d=",(double)my_car.now_degree ,"d="  ,(double)my_car.distance, "t-d=" , (double)my_car.target_distance- my_car.distance ,"t=",(double)my_car.target_distance  );
                      car::LC.start("n_d=",(double)my_car.now_degree ,"r=" , (double)laser_left , "t-d=" , (double)my_car.target_distance- my_car.distance ,"p_d=",(double)my_car.PD_control  );
              }
       
       my_car.set_speed(0,0, 0  , 0 );
       delay(2000);
       my_car.rotate(-90);
        my_car.set_speed(0,0, 0  , 0 );
        return true;  //go to next mission!
    }




