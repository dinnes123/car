#include "mission.h" 
mission_1::mission_1() :mission()
    {
        mission_number=1;
        my_car.distance_mult=10;
        my_car.mult=1;
        my_car.control_space=10;
    }
mission_1::~mission_1()
    {
       
    }
int mission_1:: run()
    {
        my_car.all_fix(  my_car.mult,  my_car.distance_mult , true );
        car::LC.start("n_d=",(double)my_car.get_degree() ,"r=" , (double)my_car.lasers_right.get_distance() , "t=" , (double)my_car.target_distance ,"p_d=",(double)my_car.PD_control  );
        return false;
       
    }

