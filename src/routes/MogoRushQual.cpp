#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void MogoRushQual() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 21.15, 0.4, 0, true);//Grab mogo rush angled
    Clamp.set(true);
    MoveEncoderPID(TestPara, 100, -4.3, 0.4,30, true);//peel back to get ready to turn to ring 1
    RunRoller(-100);
    TurnMaxTimePID(TestPara, 135, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100,24, 0.3, 135, true);//Drive to Ring 1     
//i hate niggers8
}

void RedMogoRushQual()
{
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 21.15, 0.4, 0, true);//Grab mogo rush angled
    Clamp.set(true);
    MoveEncoderPID(TestPara, 100, -4.3, 0.4,30, true);//peel back to get ready to turn to ring 1
    RunRoller(-100);
    TurnMaxTimePID(TestPara, -135, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100,24, 0.3, -135, true);//Drive to Ring 1  


}