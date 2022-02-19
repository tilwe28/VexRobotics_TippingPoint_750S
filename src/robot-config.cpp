#include "vex.h"
#include <string>

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// // A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT20, ratio18_1, false);
motor leftMotorB = motor(PORT16, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT11, ratio18_1, true);
motor rightMotorB = motor(PORT13, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT1);
smartdrive Ddd = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.9, 320, 40, mm, 1);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 320, 40, mm, 1);
motor LiftMotorA = motor(PORT19, ratio36_1, false);
motor LiftMotorB = motor(PORT12, ratio36_1, true);
motor_group Lift = motor_group(LiftMotorA, LiftMotorB);
motor Claw = motor(PORT14, ratio36_1, false);
motor Clamp = motor(PORT10, ratio18_1, false);
digital_out pneumonia = digital_out(Brain.ThreeWirePort.H);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool Controller1LeftShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

int x = 1.65;


//1 means dont vibrate, 0 means vibrate, 2 means already has vibrated
int needsToVibrate = 1;

void rumbleController(int rumbling) {
  if (rumbling == 0) Controller1.rumble("..");
}

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {

    Controller1.Screen.clearLine(3);


    if(RemoteControlCodeEnabled) {


      if (needsToVibrate == 0) {
        needsToVibrate = 2;
      }

      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      double drivetrainLeftSideSpeed = Controller1.Axis3.value() + Controller1.Axis1.value();
      //drivetrainLeftSideSpeed *= 5;
      double drivetrainRightSideSpeed = Controller1.Axis3.value() - Controller1.Axis1.value();
      //drivetrainRightSideSpeed *= 5;  
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop(brakeType::coast);
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop(brakeType::coast);
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        //LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, pct);
        LeftDriveSmart.spin(forward, drivetrainLeftSideSpeed, volt);
        //Brain.Screen.print("LeftDrive Moving" + drivetrainLeftSideSpeed);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        //RightDriveSmart.setVelocity(drivetrainRightSideSpeed, pct);
        RightDriveSmart.spin(forward, drivetrainRightSideSpeed, volt);;
        //Brain.Screen.print("RightDrive Moving" + drivetrainRightSideSpeed);
      }
      // check the ButtonR1/ButtonR2 status to control Claw
      if (Controller1.ButtonR2.pressing()) {
        Claw.setVelocity(50, vex::velocityUnits::pct);
        Claw.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR1.pressing()) {
        Claw.setVelocity(50, vex::velocityUnits::pct);
        Claw.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        Claw.stop(brakeType::hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }

      double temp = Claw.temperature(pct);
      double temp2 = Clamp.temperature(pct);
      // Controller1.Screen.print("Clamp: ");
      // Controller1.Screen.print(temp);

      if (temp >= 10) {//70
        if (needsToVibrate == 1)//75
          needsToVibrate = 0;
      } else {
        needsToVibrate = 1;
      }

      if (temp >= 10) {//80
        Controller1.rumble("..");
      }

      rumbleController(needsToVibrate);

      


      // check the ButtonL1/ButtonL2 status to control Claw
      if (Controller1.ButtonL1.pressing()) {
        Clamp.setVelocity(100, vex::velocityUnits::pct);
        Clamp.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        
        Clamp.setVelocity(100, pct);
        
        
        Clamp.spin(forward);
        //if (Clamp.position(rev) >= x) Clamp.stop(); x+= 0.01;
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Clamp.stop(brakeType::hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
                                                            
      //Controller1.Screen.print(Clamp.current());
      

      // check the ButtonUp/ButtonDown status to control Lift
      if (Controller1.ButtonUp.pressing()) {
        Lift.setVelocity(100, vex::velocityUnits::pct);
        Lift.spin(forward);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        Lift.setVelocity(100, vex::velocityUnits::pct);
        Lift.spin(reverse);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (!Controller1UpDownButtonsControlMotorsStopped) {
        Lift.stop(brakeType::hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1UpDownButtonsControlMotorsStopped = true;
      }


      //check the ButtonLeft/ButtonRight status to control Pneumonia
      if (Controller1.ButtonLeft.pressing()) {
        pneumonia.set(true);
      }
      else if (Controller1.ButtonRight.pressing()) {
        pneumonia.set(false);
      }

      

    }//while loop






    
    // wait before repeating the process
    wait(5, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}