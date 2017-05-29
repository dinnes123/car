#include "car.h" //include the declaration for this class
    
int car::all_fix(int mult_in ,int distance_mult_in, bool speed_set_enabled)
    {
        PD_control=fix_degree((double)mult_in,true);
        PD_control = PD_control  +  fix_distance((double)distance_mult_in,true);
        if(speed_set_enabled==true)   set_speed(basic_speed,basic_speed, PD_control  , -PD_control );
        return PD_control;
    }
double car::fix_degree(double mult, bool enabled )
    {
        if(enabled!=true) return 0;
        now_degree=get_degree();
        
                if(now_degree<-179 ) 
                    {
                      now_degree=2*179+1+now_degree;
                    }
                if(now_degree>179 ) 
                    {
                      now_degree=now_degree-(2*179+1);
                    }
        int return_degree=now_degree;
        if(return_degree>control_space) return_degree=control_space;
        if(return_degree<-control_space) return_degree=(-control_space);

        return return_degree*mult;
    }

double car::fix_distance(double dis_mult, bool enabled)
    {
       if(enabled!=true) return 0;
       
           distance_mult=dis_mult;
           
           distance=lasers_left.get_distance();
           
           
           if(distance>max_distance)
              {
                return 0;
              }
           int check=(target_distance-distance)*distance_mult;
           if(check>control_space) check=control_space;
           if(check<-control_space) check=(-control_space);
           
           return check;
    }

