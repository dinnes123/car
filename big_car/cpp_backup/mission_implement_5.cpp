#include "mission.h" //include the declaration for this class

//sin wave
mission_5::mission_5() :mission()
    {
        //call constructor of parents class 
        mission_number=5;
        my_car.distance_mult=2;
        my_car.mult=3;

    }
mission_5::~mission_5()
    {
       
    }
int mission_5:: run()
    {
        my_car.basic_speed=60;
        my_car.now_degree=my_car.get_degree();
         //--------------------------------------------------------------------------rotate
         int forward=my_car.get_back_distance(23);
          if(forward<20)
             {
                    my_car.set_speed(0,0, 0  , 0 );
                    delay(3000);
                    my_car.rotate(-90);
                    my_car.basic_speed=50;
                    return true;
             }
          //--------------------------------------------------------------------------
       /* abs_stop++;
        if(abs_stop>1)
            {
                //my_car.rotate(0);
                    my_car.set_speed(40,40, 0  , 0 );
               // delay(1000);
                delay(20);
                //my_car.rotate(0);
                //delay(20);
                abs_stop=0;
            }*/
       /* if(my_car.now_degree>=5  || my_car.now_degree<=-5)
            {
                my_car.set_speed(0,0, 0  , 0 );
                delay(1000);
                my_car.rotate(0);
            }*/
        my_car.all_fix(  my_car.mult,  my_car.distance_mult , true );
        int laser_left=my_car.lasers_right.get_distance();
        //car::LC.start("n_d=",(double)my_car.now_degree ,"r=" , (double)laser_left , "t-d=" , (double)my_car.target_distance- my_car.distance ,"p_d=",(double)my_car.PD_control  );
        //    car::LC.start("r=",(double)right_distance ,"r-f=" , (double)right_distance-flower_stop , "d=" , (double) my_car.lasers_left.get_distance() ,"p_d=",(double)my_car.PD_control  );
         car::LC.start("n_d=",(double)my_car.now_degree , "t-d=" , (double)my_car.target_distance- my_car.lasers_left.get_distance() , "abs=" , (double) abs_stop ,"t=",(double)my_car.target_distance  );
        return false;
       
    }

