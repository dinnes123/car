#include "car.h" //include the declaration for this class

int car::keyboard_event(bool enamled, int *change_value_1)
    {
      if(enamled)
                {
                          int input=keyboards1.key_get_value() ;
                          switch (input)
                                {
                                      case 1:
                                          target_distance+=1;
                                          break;
                                      case 4:
                                          target_distance-=1;
                                          break;
                                      case 2:
                                          distance_mult+=0.1;
                                          break;
                                      case 5:
                                          distance_mult-=0.1;
                                          break;
                                      case 3:
                                          lasers_right.fix+=5;
                                          break;
                                      case 6:
                                          lasers_right.fix-=5;
                                          break;
                                      case 0:
                                          break;
                                      case 42:
                                          car::LC.start("saving...","please wait");
                                          eeprom_pd_control.block_1.arrayx[0]=basic_speed;
                                          eeprom_pd_control.block_1.arrayx[1]=distance_mult;
                                          eeprom_pd_control.block_1.arrayx[2]=mult;
                                          eeprom_pd_control.save();
                                          delay(1000);
                                          break;
                                      case 9:
                                          car::LC.start("loading...","please wait");
                                          eeprom_pd_control.load();
                                          basic_speed=eeprom_pd_control.block_1.arrayx[0];
                                          distance_mult=eeprom_pd_control.block_1.arrayx[1];
                                          mult=eeprom_pd_control.block_1.arrayx[2];
                                          delay(1000);
                                      break;
                                }
                }
    }
