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

    MoveEncoderPID(TestPara, -100, 55.5, 0.4, -30.5, true );
    RunRoller(0);
    MoveEncoderPID(TestPara, -65, 6, 0.5, -30.5, true);
    RunRoller(100);
    OPMECH.set(false);
    wait(300,msec);
    MoveEncoderPID(TestPara, 70, 7, 0.3,-30.5, true );
    MoveEncoderPID(TestPara, 50, 8, 0.3,0,false );

  
    TurnMaxTimePID(TestPara, 80, 0.7, true);
    doinker.set(true);
    MoveEncoderPID(TestPara, -100, 39.5, 0.4, 80, true);
    RunRoller(0);
   
    MoveEncoderPID(TestPara, -100, 18.4, 0.4, 80, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, 200, 0.46, true);
    RunRoller(-100);
    TurnMaxTimePID(TestPara, 220, 0.2, true);
    doinker.set(false);
    TurnMaxTimePID(TestPara, 88, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -95, 19, 0.3, 88, true);
    wait(200, msec);
    MoveEncoderPID(TestPara, 100, 50, 0.3, 88, true);
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false);
    MoveEncoderPID(TestPara, -100, 5, 0.3, -98, true);
    MoveEncoderPID(TestPara, -100, 30, 0.3, -98, true);
    lift.spinToPosition(20, degrees, false);
    



    // MoveEncoderPID(TestPara, 100, 12, 0.3, -70, true);
   // MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true);
  //  lift.spinToPosition(-1000, degrees, false);
    


}

void Red9PTRing() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    TurnMaxTimePID(TestPara, 6.6, 0.3, true); // turn to line up with mogo
    MoveEncoderPID(TestPara, 100, 35, 0.4, 6.6, false); // drive to mogo 
    MoveEncoderPID(TestPara, 55, 15.4, 0.4, 6.6, true); // slow down for mogo
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, 6.6, true ); // move back a little more 
    TurnMaxTimePID(TestPara, 165, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,16.3, 0.3, 165, true); // drive to get first ring
    TurnMaxTimePID(TestPara, 124, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -90, 14.7, 0.3, 124, true); // drive to second ring
    TurnMaxTimePID(TestPara, 5, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 22.5, 0.3, 5, true); // drive to third ring
    TurnMaxTimePID(TestPara, -36.4, 0.7, true); // turn to last ring
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 47, 0.4, -31.4, true ); // drive full speed to last ring
    RunRoller(0);
    OPMECH.set(true); // raise up intake
    MoveEncoderPID(TestPara, -46, 7, 0.5, -28, true); // slow down so you dont knock it out
    RunRoller(100);
    OPMECH.set(false);
    wait(400,msec);
    MoveEncoderPID(TestPara, 70, 20, 0.3,0,false ); // pull back
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false); //raise arm
    MoveEncoderPID(TestPara, 100, 12, 0.3, -70, true); // align with ladder
    MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true); // drive to ladder 
    





}

void blue9PTRing() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 11.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    TurnMaxTimePID(TestPara, -4.6, 0.3, true); // turn to line up with mogo
    MoveEncoderPID(TestPara, 100, 35, 0.4, -4.6, false); // drive to mogo 
    MoveEncoderPID(TestPara, 55, 18.4, 0.4, -4.6, true); // slow down for mogo
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, -4.6, true ); // move back a little more 
    TurnMaxTimePID(TestPara, -165, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,14.3, 0.3, -165, true); // drive to get first ring
    TurnMaxTimePID(TestPara, -122, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -90, 14.7, 0.3, -122, true); // drive to second ring
    TurnMaxTimePID(TestPara, -5, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 22.5, 0.3, -5, true); // drive to third ring
    TurnMaxTimePID(TestPara, 38.2, 0.7, true); // turn to last ring
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 47, 0.4, 38.2, true ); // drive full speed to last ring
    RunRoller(0);
    OPMECH.set(true); // raise up intake
    MoveEncoderPID(TestPara, -46, 9, 0.5, 33.2, true); // slow down so you dont knock it out
    RunRoller(100);
    OPMECH.set(false);
    wait(500,msec);
    MoveEncoderPID(TestPara, 70, 20, 0.3,0,false ); // pull back
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false); //raise arm
    MoveEncoderPID(TestPara, 100, 12, 0.3, 70, true); // align with ladder
    MoveEncoderPID(TestPara, -100, 10, 0.3, 70, true); // drive to ladder 
    





}
void BlueRingRedMogo(){
    //Corner swipe 4 ring safe
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, -100, 11.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    TurnMaxTimePID(TestPara, -4.8, 0.3, true); // turn to line up with mogo
    MoveEncoderPID(TestPara, 100, 35, 0.4, -4.8, false); // drive to mogo 
    MoveEncoderPID(TestPara, 55, 18.4, 0.4, -4.8, true); // slow down for mogo
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, -4.8, true ); // move back a little more 
    
    TurnMaxTimePID(TestPara, -132, 0.7, true);
    MoveEncoderPID(TestPara, -100, 12, 0.4, -132, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 15, 0.4, -132, true );
    TurnMaxTimePID(TestPara, 33, 0.7, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 55, 0.4, 33, true );
    RunRoller(0);
    OPMECH.set(true);
    MoveEncoderPID(TestPara, -40, 12, 0.5, 33, true);
    RunRoller(100);
    OPMECH.set(false);
    wait(500,msec);
    lift.spinToPosition(-1000, degrees, false);
    MoveEncoderPID(TestPara, 70, 15, 0.3,0,false );

    wait(300,msec);
    MoveEncoderPID(TestPara, 70, 7, 0.3,30.5, true );
    MoveEncoderPID(TestPara, 50, 8, 0.3,0,false );

  
    TurnMaxTimePID(TestPara, -80, 0.7, true);
    doinker.set(true);
    MoveEncoderPID(TestPara, -100, 39.5, 0.4, -80, true);
    RunRoller(0);
   
    MoveEncoderPID(TestPara, -100, 18.4, 0.4, -80, true);
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
    

   // MoveEncoderPID(TestPara, 100, 12, 0.3, 70, true);
    //MoveEncoderPID(TestPara, -100, 10, 0.3, 70, true);
}
    