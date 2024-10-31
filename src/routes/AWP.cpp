#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);



void  RedRingBlueMogo(){
    // corner swipe 4 ring safe
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    lift.resetPosition();
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 0, 0.07, true);
    MoveEncoderPID(TestPara, 100, 30, 0.4, 0, false);
    TurnMaxTimePID(TestPara, 4.2, 0.12, true);
    MoveEncoderPID(TestPara, 55, 11.8, 0.4, 4.2, true);
    lift.spinToPosition(90, degrees, false);
    Pistake.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 2, 0.4, 4.2, true );
    TurnMaxTimePID(TestPara, 120, 0.37, true);
    MoveEncoderPID(TestPara, -100, 12, 0.4, 120, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 15, 0.4, 120, true );
    TurnMaxTimePID(TestPara, -30.5, 0.7, true);
    OPMECH.set(true);

    MoveEncoderPID(TestPara, -100, 63, 0.4, -30.5, true );
    
    
    RunRoller(100);
    
    RunRoller(100);
    
    wait(500,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -160, 0.9, true);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -160, true);
    



    // MoveEncoderPID(TestPara, 100, 12, 0.3, -70, true);
   // MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true);
  //  lift.spinToPosition(-1000, degrees, false);
    


}

void Red9PTRing() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 10.6, 0.4, 0, true); 
    Clamp.set(true); //Dunk
   
    MoveEncoderPID(TestPara, 100, 35, 0.4, 0, false); // drive to mogo 
    TurnMaxTimePID(TestPara, 7, 0.2, true);
    MoveEncoderPID(TestPara, 55, 20.4, 0.4, 7, true); // slow down for mogo
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 1.5, 0.4, 5, true ); // move back a little more 
    TurnMaxTimePID(TestPara, 160, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,15.6, 0.3, 160, true); // drive to get first ring
    TurnMaxTimePID(TestPara, 125, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -100, 10, 0.3, 125, true); // drive to second ring
    Clamp.set(false);
    TurnMaxTimePID(TestPara, 5, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 13, 0.3, 5, true); // drive to third ring
    OPMECH.set(true); 
    TurnMaxTimePID(TestPara, -35, 0.7, true); // turn to last ring
    
    
    MoveEncoderPID(TestPara, -100, 75, 0.4, -35, true ); // drive full speed to last ring
 
     // raise up intake
    
    RunRoller(100);
    
    wait(400,msec);
    MoveEncoderPID(TestPara, 60, 20, 0.3,0,false ); // pull back
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false); //raise arm
    MoveEncoderPID(TestPara, 100, 16, 0.3, -70, true); // align with ladder
    MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true); // drive to ladder 
    





}

void blue9PTRing() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 11.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    MoveEncoderPID(TestPara, 100, 30, 0.4, 0, false); // drive to mogo 
    TurnMaxTimePID(TestPara, -5.2, 0.12, true);
    MoveEncoderPID(TestPara, 55, 21.4, 0.4, -5.2, true);
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 4.5, 0.4, -2.8, true ); // move back a little more 
    TurnMaxTimePID(TestPara, -153, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,10.7, 0.3, -150, true); // drive to get first ring
    TurnMaxTimePID(TestPara, -124, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -90, 7.9, 0.3, -124, true); // drive to second ring
    Clamp.set(false);
    TurnMaxTimePID(TestPara, -3, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 7, 0.3, -3, true); // drive to third ring4
    Clamp.set(false);
  //  OPMECH.set(true); // raise up intake
    TurnMaxTimePID(TestPara, 32, 0.7, true); // turn to last ring
    OPMECH.set(true); // raise up intake
    
    MoveEncoderPID(TestPara, -100, 65, 0.4, 32, true ); // drive full speed to last ring
    
    OPMECH.set(true); // raise up intake
    //MoveEncoderPID(TestPara, -46, 11, 0.5, 41, true); // slow down so you dont knock it out
    RunRoller(100);
    
    wait(500,msec);
    MoveEncoderPID(TestPara, 60, 10, 0.3,41,false ); // pull back
    wait(300,msec);
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false); //raise arm
    MoveEncoderPID(TestPara, 100, 20, 0.3, 100, true); // align with ladder
    MoveEncoderPID(TestPara, -80, 26, 0.3, 100, true); // drive to ladder 
    





}
void MogoRush(){
    PIDDataSet TestPara={1.5,0.1,0.15};
    //Corner swipe 4 ring safe
    MoveEncoderPID(TestPara, 100, 26, 0.2, -1.7, false); 
    MoveEncoderPID(TestPara, 100, 23, 0.2, -25.6, false);
    MoveEncoderPID(TestPara, 100, 3, 0.2, -26, false);
    MoveEncoderPID(TestPara, 60, 5.5, 0.2, -26.8, false);
    //MoveEncoderPID(TestPara, 60, .8, 0.2, -26.8, true);
    Clamp.set(false);
   
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 4.6, 0.2, -26, true);
    TurnMaxTimePID(TestPara, 87, 0.4, true);
    RunRoller(80);
    MoveEncoderPID(TestPara, -100, 15.7, 0.3, 87, true);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -140, 0.6, true);
    MoveEncoderPID(TestPara, 100, 16, 0.2,-140, true);
    Clamp.set(true);




   










    


    
    /*
    wait(300,msec);
    MoveEncoderPID(TestPara, -70, 7, 0.3,30.5, true );
    MoveEncoderPID(TestPara, -50, 8, 0.3,0,false );

  
    TurnMaxTimePID(TestPara, -75, 0.7, true);
    doinker.set(true);
    MoveEncoderPID(TestPara, -100, 39.5, 0.4, -75, true);
    RunRoller(0);
   
    MoveEncoderPID(TestPara, -100, 18.4, 0.4, -75, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -200, 0.46, true);
    RunRoller(-100);
    TurnMaxTimePID(TestPara, -220, 0.2, true);
    doinker.set(false);
    TurnMaxTimePID(TestPara, -88, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -95, 19, 0.3, -88, true);
    wait(200, msec);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -88, true);
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false);
    MoveEncoderPID(TestPara, -100, 5, 0.3, 98, true);
    MoveEncoderPID(TestPara, -100, 23, 0.3, 98, true);
    lift.spinToPosition(20, degrees, false);
    */

   // MoveEncoderPID(TestPara, 100, 12, 0.3, 70, true);
    //MoveEncoderPID(TestPara, -100, 10, 0.3, 70, true);
}
    
void Simple6(){
  PIDDataSet TestPara={1.5,0.1,0.15};
  lift.resetPosition();
  MoveEncoderPID(TestPara, 100,13 , 0.4, 0, false);
  MoveEncoderPID(TestPara, 80, 9.6, 0.4, 0, false);
  Clamp.set(false);
  wait(200,msec);
  //MoveEncoderPID(TestPara, 100, 3.3 , 0.3, 0, true);
  TurnMaxTimePID(TestPara, 139, 0.6, true);
  RunRoller(90);
  MoveEncoderPID(TestPara, -100, 26.3, 0.2, 139 ,true);
  RunRoller(90);
  MoveEncoderPID(TestPara, 100, 4, 0.2, 139 ,true);
  TurnMaxTimePID(TestPara, 115, 0.25, true);
  MoveEncoderPID(TestPara, -100, 16.5, 0.2, 115, true);
  MoveEncoderPID(TestPara, 100, 10, 0.2, 115, false);
  MoveEncoderPID(TestPara, -100, 13, 0.2, 30, false);
  MoveEncoderPID(TestPara, -100, 26, 0.2, -13, false);
  MoveEncoderPID(TestPara, -100, 23, 0.2, 50, true);
  MoveEncoderPID(TestPara, -100, 25, 0.2, 60, true);
  wait(100,msec);
  MoveEncoderPID(TestPara, 100, 25, 0.2, 60, true);
  TurnMaxTimePID(TestPara, -90, 0.5, true);
  MoveEncoderPID(TestPara, -100, 25, 0.2, -90, true);
  lift.setVelocity(60,percent);
  lift.spinTo(-77, degrees);
  Pistake.set(true);
  MoveEncoderPID(TestPara, -70, 20, 0.3, -90, true);
  Pistake.set(false);
  wait(200,msec);
  MoveEncoderPID(TestPara, 65, 11, 0.3, -90, true);
  TurnMaxTimePID(TestPara, -27, 0.5, true);
  MoveEncoderPID(TestPara, -70, 13, 0.5, -27, true);
  RunLift(-60);
  wait(150,msec);
  MoveEncoderPID(TestPara, 70, 5, 0.5, -26, true);
  lift.setVelocity(100,percent);
  
}
