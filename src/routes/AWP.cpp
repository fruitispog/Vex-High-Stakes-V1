#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    




}

void redAWP(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, -100, 8.5, 0.4, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 7.5, 0.6, true);
    MoveEncoderPID(TestPara, 100, 34, 0.4, 7.5, false);
    MoveEncoderPID(TestPara, 65, 11.4, 0.4, 7.5, false);
    Pistake.set(false);
    TurnMaxTimePID(TestPara, 120, 0.7, true);
}

void redSafeAWP() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    
    RunRoller(-100);//
    wait(180, msec);
    MoveEncoderPID(TestPara, 85, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -85, 6, 0.3, 0, true ); // drive forward to clear ring
    wait(80, msec);
    TurnMaxTimePID(TestPara, -140, 0.6, true );        
    MoveEncoderPID(TestPara, 55, 12.5, 0.5, -140, true);
    MoveEncoderPID(TestPara, -50, .4, 0.5, -140, true);
    TurnMaxTimePID(TestPara, -63, 0.5, true);
    MoveEncoderPID(TestPara, 85, 5.8, 0.5, -63, true);
    MoveEncoderPID(TestPara, 60, 4.2 , 0.3, -63, true);
    
    RunRoller(-100); //score onto alliance stake
    wait(500, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -85, 5.9, 0.7, -63, true);// delta angle needs to be 58(ik its weird)
    TurnMaxTimePID(TestPara, 79, 0.8, true);
    //Tilt.set(true); // up to grab mogo

    MoveEncoderPID(TestPara, 100, 42, 0.5, 79, true);
    MoveEncoderPID(TestPara, 85,4,0.6,79,false);
     //slow down to grab mogo
    Clamp.set(true); //close clamp 
   
    MoveEncoderPID(TestPara, 100, 1.5, 0.4, 79, true);
   // Tilt.set(false); // tilt mogo
   // wait(380,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara,-150, 0.6,true); 
    RunRoller(-100);
    MoveEncoderPID(TestPara, -100, 30, 0.6, -150, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 10, 0.8, true);
    MoveEncoderPID(TestPara, -100 ,15 , 0.3, 10, true);  
    RunRoller(0);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 26, 0.4, 3 , true);                                                                  





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