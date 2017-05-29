#include "car.h" //include the declaration for this class
int car::rotate(int degree_in)  
    {
       now_degree=get_degree();
       while(      ! ( now_degree <  degree_in+3      &&    now_degree > degree_in-3 ))
          {
               now_degree=get_degree();
         
               int pd_c=all_fix(5 ,0, false);  //only fix degree
               
               if(pd_c>max_rotate)pd_c=max_rotate;
               if(pd_c<-max_rotate)pd_c=-max_rotate;
               
               if(pd_c>-min_rotate)pd_c=-min_rotate;
               if(pd_c<min_rotate)pd_c=min_rotate;
           if(now_degree-degree_in>0)  
                   {
                    LC.start( "d_in=" , degree_in  , "n_d=" , now_degree , "n-d=",now_degree-degree_in);
                    set_speed(pd_c,-pd_c,0,0);
                   }
           else if(now_degree-degree_in<0)  
                   {
                    LC.start( "d_in=" , degree_in  , "n_d=" , now_degree , "n-d=",now_degree-degree_in);
                    set_speed(-pd_c,pd_c,0,0);
                   }
               
         
          }
       set_speed(0,0,0,0);
     
    }
