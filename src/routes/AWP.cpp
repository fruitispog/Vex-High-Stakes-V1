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
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 6.5, 0.3, true);
    MoveEncoderPID(TestPara, 100, 35, 0.4, 6.5, false);
    MoveEncoderPID(TestPara, 55, 11.4, 0.4, 6.5, true);
    Pistake.set(true);
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
    MoveEncoderPID(TestPara, -100, 9.5, 0.4, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 6.5, 0.3, true);
    MoveEncoderPID(TestPara, 100, 39, 0.4, 6.5, false);
    MoveEncoderPID(TestPara, 55, 11.4, 0.4, 6.5, true);
    Pistake.set(true);
    Clamp.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 6.5, 0.4, 7.5, true );
    TurnMaxTimePID(TestPara, 180, 0.8, true);
    MoveEncoderPID(TestPara, -100, 14, 0.3, 180, true);
    TurnMaxTimePID(TestPara, 120, 0.5, true);
    MoveEncoderPID(TestPara, -80, 27, 0.3, 120, true);
    TurnMaxTimePID(TestPara, -10, 0.6, true);
    MoveEncoderPID(TestPara, -100, 30, 0.3, -10, true);
    TurnMaxTimePID(TestPara, -28, 0.7, true);
    
    MoveEncoderPID(TestPara, -100, 47, 0.4, -28, true );
    RunRoller(0);
    OPMECH.set(true);
    MoveEncoderPID(TestPara, -40, 10, 0.5, -28, true);
    RunRoller(100);
    OPMECH.set(false);
    wait(400,msec);
    MoveEncoderPID(TestPara, 70, 15, 0.3,0,false );
    MoveEncoderPID(TestPara, 100, 12, 0.3, -70, true);
    MoveEncoderPID(TestPara, -100, 10, 0.3, -70, true);
    lift.spinToPosition(-1000, degrees, false);





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