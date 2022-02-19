/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */ 
/*    Author:       C:\Users\Ayush                                            */
/*    Created:      Fri Jan 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    20, 16, 11, 13, 6
// MotorGroup19         motor_group   19, 12          
// Motor17              motor         17              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>

using namespace vex;

competition Competition;
//controller c1;




// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonRightSideWinAndMiddle() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  // LeftDriveSmart.spinFor(reverse, 1.05, seconds); (if shit goes wrong)
  Claw.setVelocity(50, rpm);
  Claw.spinFor(reverse, 0.5, seconds);
  Drivetrain.setTurnVelocity(200, rpm);
  Drivetrain.turnFor(right, 97.5, deg);
  Drivetrain.setDriveVelocity(200,rpm);
  Drivetrain.driveFor(forward, 52, inches, false);
  wait(1, sec);
  Claw.setVelocity(50, pct);
  Claw.spinFor(forward, 0.5, seconds);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 25, inches);
  Claw.spinFor(reverse, 1, seconds);
  Claw.setVelocity(50, rpm);
  Drivetrain.driveFor(reverse, 10, inches);
  Drivetrain.turnFor(left, 200, degrees);
  Drivetrain.driveFor(forward, 130, inches, false);
  wait(2.5, sec);
  Claw.spinFor(forward, 1, seconds);
  wait(1, sec);
  Drivetrain.driveFor(reverse, 100, inches, true);

}

void autonLeftSideWinPoint() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 20, inches);
  wait(0.3, sec);
  Claw.setVelocity(50, rpm);
  Claw.spinFor(forward, 0.5, sec);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 20, inches);
  Claw.spinFor(reverse, 0.5, sec);
  Drivetrain.driveFor(reverse, 10, inches, true);
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(left, 120, degrees);
  Drivetrain.driveFor(forward, 170, inches, false);
  wait(3, sec);
  Claw.spinFor(forward, 0.5, sec);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 150, inches);

}

void autonMiddle() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 175, inches, false);
  Claw.setVelocity(100, pct);
  Claw.spinFor(reverse, 0.5, seconds);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(3, seconds);
  Claw.setVelocity(75, pct);
  Claw.spinFor(forward, 1, seconds);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 160, inches, true);
}

void autonDefault() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 130, inches, false);
  wait(2.2, seconds);
  Claw.setVelocity(50, rpm);
  Claw.spinFor(forward, 0.5, seconds);
  Drivetrain.driveFor(reverse, 110, inches, true);
}

void fortyLeft() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);


  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 160, inches, false);
  Claw.setVelocity(100, pct);
  Claw.spinFor(reverse, 0.5, seconds);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(2.75, seconds);
  Claw.setVelocity(75, pct);
  Claw.spinFor(forward, 1, seconds);
  Clamp.setVelocity(100, pct);
  Clamp.spinFor(forward, 0.75, sec);
  Clamp.setBrake(vex::brakeType::hold);
  wait(0.5, sec);
  Drivetrain.turnFor(right, 86, deg);
  Drivetrain.driveFor(reverse, 75, inches, false);
  wait(1.6, sec);
  Clamp.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(left, 115, deg);
  Drivetrain.driveFor(reverse, 120, inches);
}

void fortyRight() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);


  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 160, inches, false);
  Claw.setVelocity(100, pct);
  Claw.spinFor(reverse, 0.5, seconds);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(2.75, seconds);
  Claw.setVelocity(75, pct);
  Claw.spinFor(forward, 1, seconds);
  Clamp.setVelocity(100, pct);
  Clamp.spinFor(forward, 0.75, sec);
  Clamp.setBrake(vex::brakeType::hold);
  wait(0.5, sec);
  Drivetrain.turnFor(left, 86, deg);
  Drivetrain.driveFor(reverse, 75, inches, false);
  wait(1.6, sec);
  Clamp.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(right, 115, deg);
  Drivetrain.driveFor(reverse, 120, inches);
}

void skills() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  //Get mobile goal on back and turn
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, seconds);
  Claw.setVelocity(100, pct);
  Claw.spinFor(reverse, 0.5, seconds);
  Clamp.setVelocity(100, pct);
  Clamp.spinFor(forward, 0.75, seconds);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 20, inches, false);
  wait(0.8, seconds);
  Clamp.setVelocity(50, pct);
  Clamp.spinFor(reverse, 1, seconds);//0.75
  Drivetrain.driveFor(forward, 17.5, inches, true);
  Clamp.setBrake(vex::brakeType::hold);
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(right, 193.5, deg);//197.5 //190
  
  //Get yellow mobile goal and stack
  Drivetrain.stop();
  Drivetrain.driveFor(forward, 120, inches, false);
  wait(2.5, seconds);
  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 1, seconds);
  wait(0.5, sec);
  Drivetrain.turnFor(right, 90, degrees);//92.5
  Drivetrain.stop();
  wait(100, msec);
  Drivetrain.driveFor(forward, 82.5, inches, false);
  //wait(0.1, sec);
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.2, seconds);
  RightDriveSmart.setVelocity(100, pct);
  RightDriveSmart.spinFor(forward, 0.5, seconds);
  wait(0.5, seconds);
  Lift.spinFor(reverse, 0.8, seconds);
  Claw.spinFor(reverse, 1, seconds);
  wait(.8, sec);
  Drivetrain.driveFor(reverse, 10, inches, false);
  Lift.spinFor(forward, 0.4, sec);
  wait(0.2, sec);
  Drivetrain.driveFor(reverse, 10, inches, false);
  Lift.spinFor(forward, 0.4, seconds);//0.4
  

  //Take win point mobile goal and stack on opposite bridge
  wait(1, sec);
  Drivetrain.turnFor(left, 191, degrees);//200
  Drivetrain.stop();
  wait(1, sec);
  Lift.spinFor(reverse, 2, seconds);
  Drivetrain.driveFor(forward, 95, inches, false);
  Claw.spinFor(reverse, 1, sec);
  wait (2, seconds);
  Claw.spinFor(forward, 1, seconds);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 10, inches, true);
  Drivetrain.turnFor(left, 297.5, degrees);//300 //292.5
  Drivetrain.stop();
  Drivetrain.driveFor(forward, 180, inches, false); //160
  wait(1.4, sec);//2
  Lift.spinFor(forward, 2, seconds);
  wait(2, sec);
  LeftDriveSmart.spinFor(forward, 0.5, seconds);
  wait(0.5, seconds);
  Lift.spinFor(reverse, 0.6, seconds);
  Claw.spinFor(reverse, 1, seconds);
  wait(1, sec);
  Drivetrain.driveFor(reverse, 10, inches, false);
  Lift.spinFor(forward, 0.4, sec);
  wait(0.4, sec);
  Drivetrain.driveFor(reverse, 10, inches, true);
  //Drivetrain.turnFor(right, 10, degrees);
  Lift.spinFor(forward, 0.6, seconds);
  Drivetrain.turnFor(right, 30, degrees);//
  Drivetrain.driveFor(reverse, 110, inches); //90

  //140
  Drivetrain.turnFor(left, 102.5, deg);
  Lift.spinFor(reverse, 2, sec);
  Claw.spinFor(reverse, 0.8, sec);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 120, inches, false);
  wait(2, sec);
  Claw.spinFor(forward, 1, sec);
  wait(0.8, sec);
  Drivetrain.driveFor(reverse, 170, inches, true);
  Drivetrain.stop();

  //Aauyush
  // Lift.spinFor(reverse, 2, seconds);
  // Claw.spinFor(reverse, 0.5, seconds);
  // Clamp.spinFor(forward, 0.75, seconds);
  // Drivetrain.driveFor(reverse, 20, inches);
  // Drivetrain.turnFor(left, 90, deg);
  // Drivetrain.driveFor(forward, 60, inches, false);
  // wait(1.2, sec);
  // Claw.spinFor(forward, 0.5, seconds);
  // Drivetrain.turnFor(right, 190, deg);
  // Drivetrain.driveFor(forward, 80, inches, false);
  // wait(0.8, sec);
  // Lift.spinFor(forward, 2, seconds);
  // waitUntil(Drivetrain.isDone());
  // RightDriveSmart.spinFor(forward, 0.6, seconds);
  // Lift.spinFor(reverse, 0.6, seconds);
  // Claw.spinFor(reverse, 0.5, seconds);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void runAuton(int index) {
  switch (index) {
    case 1: autonDefault(); break;
    case 2: autonMiddle(); break;
    case 3: autonLeftSideWinPoint(); break;
    case 4: autonRightSideWinAndMiddle(); break;
    case 5: skills(); break;
    case 6: fortyLeft(); break;
    case 7: fortyRight(); break;
    default: autonMiddle(); break;
  }
}

void autonomous(void) {
  
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  //1 is auton default
  //2 is auton middle
  //3 is left side win point
  //4 is right side win point
  //5 is skills
  //6 is 40 left
  //default is auton default
  runAuton(6);

  

  wait(20, msec);
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



void usercontrol(void) {

  
  

}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(5, msec);
  }
}
