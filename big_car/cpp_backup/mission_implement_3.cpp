#include "mission.h" //include the declaration for this class
mission_3::mission_3() :mission()
    {
        //call constructor of parents class 
        mission_number=3;
        my_car.degree_offest=-179;  //90  -->go right      -90  -->go left
        
        my_car.mult=1;
        my_car.distance_mult=3;
        
        
        my_car.reverse_find_wall=true;
        //-------------------------------------------------------------------
        
                      
        //--------------------------------------------------------------------   push the value of target_distance
    }
mission_3::~mission_3()
    {
        
    }
int mission_3:: run()
    {
        int temp=my_car.target_distance;
        my_car.target_distance=(my_car.target_distance/2)+8;  //-13
     // my_car.target_distance=my_car.target_distance-13; 
        int forward=my_car.get_back_distance(23);
        
        delay(3000);
       

        
        
        while(forward>20  )
              {
                    forward=my_car.get_back_distance(23);
                    // my_car.keyboard_event(true, &mission_number);
                    my_car.now_degree=my_car.get_degree();
                    my_car.all_fix(my_car.mult,my_car.distance_mult , true);
                    
                   //car::LC.start("n_d=",(double)my_car.now_degree ,"d="  ,(double)my_car.distance, "t-d=" , (double)my_car.target_distance- my_car.distance ,"t=",(double)my_car.target_distance  );
                   int laser_left=my_car.lasers_right.get_distance();
                  //car::LC.start("n_d=",(double)my_car.now_degree ,"r=" , (double)laser_left , "t-d=" , (double)my_car.target_distance- my_car.distance ,"p_d=",(double)my_car.PD_control  );
                   car::LC.start("n_d=",(double)my_car.now_degree , "t-d=" , (double)my_car.target_distance- my_car.lasers_left.get_distance() , "d=" , (double) my_car.lasers_left.get_distance() ,"t=",(double)my_car.target_distance  );
              }
      
       my_car.set_speed(0,0, 0  , 0 );
       my_car.rotate(90);

       my_car.target_distance=temp;
       return true;  //go to next mission!
       
    }




