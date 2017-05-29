#include "car.h" //include the declaration for this class


double car::get_degree()
    {
   
        static toroi_new car_toroi_new;
        int te=car_toroi_new.get_v();
        
        return  te+degree_offest;
    }
