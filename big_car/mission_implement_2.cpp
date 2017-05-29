#include "mission.h" //include the declaration for this class
mission_2::mission_2() :mission()
    {
        //call constructor of parents class 
        mission_number=2;
        my_car.degree_offest=90;
       
        my_car.mult=1;
        my_car.distance_mult=1;
      
       
        
    }
mission_2::~mission_2()
    {
        
    }
int mission_2:: run()
    {
         int laser_left=my_car.lasers_right.get_distance();
      car::LC.start("n_d=",(double)my_car.now_degree ,"r=" , (double)laser_left , "t-d=" , (double)my_car.target_distance- my_car.distance ,"p_d=",(double)my_car.PD_control  );
        int forward=my_car.get_back_distance(23);
        delay(2000);
        
        while(forward>30)
              {
                    forward=my_car.get_back_distance(23);
                    my_car.now_degree=my_car.get_degree();
                    my_car.all_fix(my_car.mult,my_car.distance_mult , true);
                 
                       car::LC.start("n_d=",(double)my_car.now_degree , "t-d=" , (double)my_car.target_distance- my_car.lasers_left.get_distance() , "d=" , (double) my_car.lasers_left.get_distance() ,"t=",(double)my_car.target_distance  );
              }
       
       my_car.set_speed(0,0, 0  , 0 );
       delay(2000);
       my_car.rotate(-90);
        my_car.set_speed(0,0, 0  , 0 );
        return true;  //go to next mission!
    }




