#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true);
    Clamp.set(true);




}

void redAWP(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    lift.spinToPosition(.20, degrees, false);
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 6.6, 0.3, true);
    MoveEncoderPID(TestPara, 100, 35, 0.4, 6.6, false);
    MoveEncoderPID(TestPara, 55, 15.4, 0.4, 6.6, true);
    lift.spinToPosition(20, degrees, false);
    Pistake.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, 7.5, true );
    TurnMaxTimePID(TestPara, 120, 0.7, true);
    MoveEncoderPID(TestPara, -100, 12, 0.4, 120, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 15, 0.4, 120, true );
    TurnMaxTimePID(TestPara, -33, 0.7, true);
    
    MoveEncoderPID(TestPara, -100, 55, 0.4, -33, true );
    RunRoller(0);
    OPMECH.set(true);
    MoveEncoderPID(TestPara, -40, 10, 0.5, -33, true);
    RunRoller(100);
    OPMECH.set(false);
    wait(400,msec);
    MoveEncoderPID(TestPara, 70, 15, 0.3,0,false );
    MoveEncoderPID(TestPara, 100, 12, 0.3, -70, true);
    MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true);
    lift.spinToPosition(-1000, degrees, false);
    


}

void redSafeAWP() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    lift.spinToPosition(.20, degrees, false);
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
void redSuperSafe() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, 80, 32, 0.3,0, true);
    MoveEncoderPID(TestPara, 40, 4, 0.3, 0, true); //grab mogro
    Clamp.set(true);
    wait(30,msec);
    MoveEncoderPID(TestPara, 40, 6, 0.3, 0, true);
    Pistake.set(false);
    //grab first ring
    RunRoller(-100);
    TurnMaxTimePID(TestPara, 58, 0.8, true);
    MoveEncoderPID(TestPara, -80, 35, 0.3,58, true); //pickup first ring
    TurnMaxTimePID(TestPara, 150, 0.8, true); //approach second ring
    MoveEncoderPID(TestPara, -70, 15, 0.3,150, true); //pickup second ring
    MoveEncoderPID(TestPara, 80, 5, 0.3,150, true); //pickup second ring
    TurnMaxTimePID(TestPara, 180, 0.5, true); //approach third ring
    MoveEncoderPID(TestPara, -70, 9, 0.3,180, true); //pickup third ring 
    MoveEncoderPID(TestPara, 70, 12.5, 0.3,180, true); //approach ladder 
    TurnMaxTimePID(TestPara, -138.5, 0.8, true); //turn to face ladder
    MoveEncoderPID(TestPara, -70, 37, 0.3,-138.5, true); //touch ladder with flex wheels
    RunRoller(0);




}
void blueSafeAWP() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 11.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    TurnMaxTimePID(TestPara, -6.6, 0.3, true); // turn to line up with mogo
    MoveEncoderPID(TestPara, 100, 35, 0.4, -6.6, false); // drive to mogo 
    MoveEncoderPID(TestPara, 55, 17.4, 0.4, -6.6, true); // slow down for mogo
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, -6.6, true ); // move back a little more 
    TurnMaxTimePID(TestPara, -155, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,15, 0.3, -155, true); // drive to get first ring
    TurnMaxTimePID(TestPara, -122, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -90, 14.7, 0.3, -122, true); // drive to second ring
    TurnMaxTimePID(TestPara, -5, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 22.5, 0.3, -5, true); // drive to third ring
    TurnMaxTimePID(TestPara, 33.2, 0.7, true); // turn to last ring
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 47, 0.4, 33.2, true ); // drive full speed to last ring
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