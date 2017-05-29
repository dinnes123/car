#include "mission.h" //include the declaration for this class


mission_7::mission_7() :mission()
    {
        //call constructor of parents class 
        mission_number=7;
        my_car.distance_mult=5;
        my_car.mult=1;
        my_car.degree_offest=-179;  //90  -->go right      -90  -->go left
       
        
    }
mission_7::~mission_7()
    {
       
    }
int mission_7:: run()
    {

      
   
        my_car.now_degree=my_car.get_degree();
       
         
         //--------------------------------------------------------------------------rotate
         int forward=my_car.get_back_distance(23);
          if(forward<15)
             {
                    my_car.set_speed(0,0, 0  , 0 );
                    delay(3000);
                    my_car.rotate(-90);
                   
                    return true;
             }
          //--------------------------------------------------------------------------
         
        
                         //-------------------------------------------------------------------flower stop
  float right_distance=my_car.lasers_right.get_distance();
          
if( right_distance < flower_catch){

 
         if(n==2) 
                {
                    car::LC.start("r_d=",right_distance  , "f_s="  , flower_catch ,"fix=", my_car.lasers_left.fix);
                    my_car.rotate(0);
                    delay(1000);
                    my_car.all_fix(  my_car.mult,  my_car.distance_mult , true );   
                    delay(1650);
                    my_car.rotate(0);
                    delay(100);
                    my_car.set_speed(0,0, 0 , 0 );   
                    delay(1000); 
                    my_car.rotate(0);
                    delay(1000);  
                    myservo1.attach(24);//手臂馬達腳位
                    myservo1.write(20);//手臂馬達初始角度 
                    delay(100);
                    myservo2.attach(26);//夾爪馬達腳位
                    myservo2.write(79);//夾爪馬達初始角度
                    delay(3000);
                    
                    int downdeg=90;//手臂下降角度
                    int folddeg=96;//夾爪放開角度
                    int updeg=15;//手臂回到初始角度
                    int infolddeg=85;//夾爪回到初始角度
                    delay(200);
                    myservo1.write(downdeg); 
                    delay(2000);
                    myservo2.write(folddeg);
                    delay(200); 
                    myservo1.write(updeg);
                    delay(200);
                    myservo2.write(infolddeg=85);
                    my_car.set_speed(my_car.basic_speed,my_car.basic_speed, 0  , 0 );
                    delay(1000);
                    my_car.keyboard_event(true, &flower_catch);         
                  } 
       
       
           if(n==1) 
                  {
                    n=n+1;
                    car::LC.start("r_d=",right_distance  , "f_s="  , flower_catch  ,"fix=", my_car.lasers_left.fix);
                    my_car.rotate(0);
                    delay(1000);
                    my_car.all_fix(  my_car.mult,  my_car.distance_mult, true );   
                    delay(1650);
                    
                    my_car.rotate(0);
                    delay(100);
                    my_car.set_speed(0,0, 0 , 0 );   
                    delay(1000);
                    my_car.rotate(0);
                    delay(1000);   
                    
                    myservo1.attach(24);//手臂馬達腳位
                    myservo1.write(20);//手臂初始角度
                    delay(100);
                    myservo2.attach(26);//夾爪馬達腳位
                    myservo2.write(95);//夾爪初始角度
                    delay(3000);
                    
                    int downdeg=95;//手臂下降角度
                    int folddeg=77;//夾爪夾取角度
                    int updeg=25;//回到手臂初始角度
                    delay(200);
                    myservo1.write(downdeg); 
                    delay(2000);
                    myservo2.write(folddeg);
                    delay(200); 
                    myservo1.write(updeg);
                    delay(500);
                    my_car.set_speed(my_car.basic_speed,my_car.basic_speed, 0  , 0 );
                    delay(1000);
                    my_car.keyboard_event(true, &flower_catch); 
                }
         if(n==0) 
                { 
                    n=n+1;
                    car::LC.start("r_d=",right_distance  , "f_s="  , flower_catch  ,"fix=", my_car.lasers_left.fix);
                    my_car.all_fix(  my_car.mult,  my_car.distance_mult , true );   
                    delay(1000);
                    my_car.keyboard_event(true, &flower_catch); 
                }
} 
            
         //----------------------------------------------------------------------
                       

        
     
        
       
        my_car.all_fix(  my_car.mult,  my_car.distance_mult , true );
        int laser_left=my_car.lasers_right.get_distance();
        car::LC.start("n_d=",(double)my_car.now_degree ,"r=" , (double)laser_left , "t-d=" , (double)my_car.target_distance- my_car.distance ,"p_d=",(double)my_car.PD_control  );
         //   car::LC.start("r=",(double)right_distance ,"r-f=" , (double)right_distance-flower_stop , "d=" , (double) my_car.lasers_left.get_distance() ,"p_d=",(double)my_car.PD_control  );
        return false;
       
    }

