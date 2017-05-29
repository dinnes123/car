#include "car.h" //include the declaration for this class


int car::get_back_distance(int pin_set)  
    {
        static UltraSonic_3_pin UltraSonic_3_pin(pin_set);
        return UltraSonic_3_pin.get_distance();
    }
