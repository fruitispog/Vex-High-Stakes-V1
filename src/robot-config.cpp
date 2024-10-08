#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT11, ratio6_1, true);
motor LM = motor(PORT12, ratio6_1, true);
motor RF = motor(PORT18, ratio6_1, false);
motor RM = motor(PORT19, ratio6_1, false);
motor LB = motor(PORT13, ratio6_1, true);
motor RB = motor(PORT20, ratio6_1, false);
motor In1 = motor(PORT21, ratio6_1, false);
motor In2 = motor(PORT10, ratio6_1, true);
motor lift= motor(PORT9, ratio36_1, true);
optical OpSens = optical(PORT1);

//define lift to brake when stopped

//Motor Groups
motor_group Roller = motor_group(In1,In2);

//Pistons
digital_out Pistake = digital_out(Brain.ThreeWirePort.B);
//digital_out Tilt = digital_out(Brain.ThreeWirePort.B);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
digital_out OPMECH =digital_out(Brain.ThreeWirePort.C);
digital_out doinker = digital_out(Brain.ThreeWirePort.D);
//Gyro and stuff for PID
inertial Gyro = inertial(PORT2);
//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}