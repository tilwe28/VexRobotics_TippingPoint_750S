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



bool pid = false;


//change

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

// std::to_string();
// to_string();

//vex::brakeType::hold;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  LeftDriveSmart.setStopping(brakeType::brake);
  RightDriveSmart.setStopping(brakeType::brake);

  DrivetrainInertial.setHeading(0, deg);
  Ddd.setTurnThreshold(2);

}

void turnRight(double d) {
  Drivetrain.setTurnVelocity(25, pct);
  Drivetrain.turn(left);
  while (true) {
    if (DrivetrainInertial.rotation()<=d) {
      Drivetrain.stop();
      break;
    }
  }
}

void turnLeft(double d) {
  Drivetrain.setTurnVelocity(25, pct);
  Drivetrain.turn(right);
  while (true) {
    if (DrivetrainInertial.rotation()>=d) {
      Drivetrain.stop();
      break;
    }
  }
}

void autonRightSideWinAndMiddle() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  Frontclamp.set(false);
  Drivetrain.setTurnVelocity(25, pct);
  Drivetrain.turnFor(left, 97.5, deg);
  Drivetrain.setDriveVelocity(200,rpm);
  Drivetrain.driveFor(reverse, 52, inches, false);
  wait(1, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 25, inches);
  Frontclamp.set(false);
  Drivetrain.driveFor(forward, 10, inches);
  Drivetrain.turnFor(right, 200, degrees);
  Drivetrain.driveFor(reverse, 130, inches, false);
  wait(2.5, sec);
  Frontclamp.set(true);
  wait(1, sec);
  Drivetrain.driveFor(forward, 100, inches, true);

}

void autonLeftSideWinPoint() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 20, inches);
  wait(0.3, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 20, inches);
  Frontclamp.set(false);
  Drivetrain.driveFor(forward, 10, inches, true);
  Drivetrain.setTurnVelocity(25, pct);
  Drivetrain.turnFor(right, 120, degrees);
  Drivetrain.driveFor(reverse, 170, inches, false);
  wait(3, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 150, inches);

}

void autonMiddle() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 100, inches, false);
  Frontclamp.set(false);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(2, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 100, inches, true);
}

void autonDefault() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 130, inches, false);
  wait(2.2, seconds);
  Frontclamp.set(true);
  Drivetrain.driveFor(forward, 110, inches, true);
}

void fortyLeft() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);


  Drivetrain.setDriveVelocity(150, rpm);
  Drivetrain.driveFor(reverse, 160, inches, false);
  Frontclamp.set(false);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(2.75, seconds);
  Frontclamp.set(true);
  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, sec);
  Claw.setBrake(vex::brakeType::hold);
  wait(0.5, sec);
  Drivetrain.turnFor(left, 86, deg);
  Drivetrain.driveFor(forward, 85, inches, false);
  wait(1.825, sec);
  Claw.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(right, 115, deg);
  Drivetrain.driveFor(forward, 120, inches);
}

void fortyRight() {
  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);


  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 110, inches, false);
  Frontclamp.set(false);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(2, seconds);
  Frontclamp.set(true);
  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, sec);
  Claw.setBrake(vex::brakeType::hold);
  wait(0.5, sec);
  Drivetrain.turnFor(right, 62, deg);
  Ddd.turnToHeading(40, deg, true);
  Drivetrain.driveFor(forward, 60, inches, false);
  wait(1.2, sec);
  Claw.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(left, 145, deg);
  Drivetrain.driveFor(forward, 90, inches);
}

void skills() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  Drivetrain.setTurnVelocity(25, pct);

  //Pick up mobile goal onto back
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, seconds);
  Frontclamp.set(false);
  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, seconds);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 20, inches, false);
  wait(0.8, seconds);
  Claw.setVelocity(50, pct);
  Claw.spinFor(reverse, 1, seconds);
  Drivetrain.driveFor(reverse, 15, inches, true);
  Claw.setBrake(vex::brakeType::hold);

  //Turn and get yellow mobile goal and clear rings
  Drivetrain.turnFor(left, 130, deg);
  Ddd.turnToHeading(-93.5, deg, true);
  wait(100, msec);
  Drivetrain.driveFor(reverse, 130, inches, false);
  wait(2, seconds);
  Frontclamp.set(true);
  wait(100, msec);
  wait(1.5, sec);
  turnRight(-175);
  Drivetrain.driveFor(reverse, 55, inches, true);

  //Stack mobile goal
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.5, seconds);
  turnLeft(-87.5);
  Drivetrain.driveFor(reverse, 15, inches, true);
  Claw.setBrake(vex::brakeType::hold);
  wait(100, msec);
  wait(0.1, seconds);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.4, sec);
  Lift.spinFor(forward, 0.8, sec);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 15, inches, true);

  //Take win point mobile goal
  turnLeft(-21);
  Drivetrain.driveFor(reverse, 70, inches, false);
  Lift.spinFor(reverse, 2, seconds);
  wait (0.15, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 10, inches, true);
  turnLeft(107);

  //Go to opposite bridge and stack
  Drivetrain.driveFor(reverse, 90, inches, true);
  Lift.spinFor(forward, 2, sec);
  Drivetrain.driveFor(reverse, 15, inches);
  turnRight(97);
  Drivetrain.driveFor(reverse, 10, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Lift.spinFor(forward, 0.8, sec);

  //Push big middle mobile goal back
  turnLeft(85);
  Drivetrain.driveFor(forward, 80, inches, false);
  Lift.spinFor(reverse, 2, seconds);

  //Turn and clamp last yellow mobile goal
  turnLeft(138);
  Drivetrain.driveFor(reverse, 50, inches, false);
  wait(1.2, sec);
  Frontclamp.set(true);
  wait(0.8, sec);

  //Align to stack mobile goal
  turnRight(52);
  Drivetrain.driveFor(reverse, 70, inches, true);
  Lift.spinFor(forward, 2.5, seconds);
  turnLeft(85);
  Drivetrain.driveFor(reverse, 30, inches, true);
  Lift.spinFor(reverse, 1.2, sec);
  Frontclamp.set(false);
  wait(0.2, sec);
  Lift.spinFor(forward, 0.8, sec);

  //Go back to score mobile goal on back
  Drivetrain.driveFor(forward, 100, inches, true);
  Drivetrain.stop();
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
    default: autonDefault(); break;
  }
}

void autonomous(void) {


  
  // pid = true;
  // vex::task PID(drivePID);
  // resetDriveSensors = true;
  // desiredValue = 5;

  // vex::task::sleep(1000);
  // resetDriveSensors = true;
  //pid = true;
  // vex::task PID(drivePID);
  // resetDriveSensors = true;
  // desiredValue = 0;

  //desiredValue = 3;

    // vex::task::sleep(1000);

    // desiredValue = 5;
  



  // Lift.setStopping(vex::brakeType::hold);
  // Claw.setBrake(vex::brakeType::hold);

  //1 is auton default
  //2 is auton middle
  //3 is left side win point
  //4 is right side win point
  //5 is skills
  //6 is 40 left
  //7 is 40 right
  //default is auton default
  runAuton(5);

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

  pid = false;
  Brain.Screen.setCursor(10, 10);

  //c1.Screen.print(10);

  while(true) {
    //c1.Screen.clearLine(3);

    Brain.Screen.print(DrivetrainInertial.rotation());

    //drive
    double turnImportance = 0.5;

    
    double fP = c1.Axis3.position(percent) * -1;
    //c1.Screen.print(fP);
    double tP = c1.Axis1.position(percent) * -1;

    double tV = tP * 0.12;
    double fV = fP * 0.12 * (1-(std::abs(tV)/12) * turnImportance);


    LeftDriveSmart.spin(forward, fV+tV, volt);
    RightDriveSmart.spin(forward, fV-tV, volt);

    //Lift
    Lift.setStopping(brakeType::hold);
    if (c1.ButtonUp.pressing()) Lift.spin(forward, 100, pct);
    else if (c1.ButtonDown.pressing()) Lift.spin(reverse, 100, pct);
    else Lift.stop();

    //Claw
    Claw.setBrake(brakeType::hold);
    if (c1.ButtonL1.pressing()) Claw.spin(reverse, 100, pct);
    else if (c1.ButtonL2.pressing()) Claw.spin(forward, 100, pct);
    else Claw.stop();

    //Front Clamp
    if (c1.ButtonR1.pressing()) Frontclamp.set(false);
    else if (c1.ButtonR2.pressing()) Frontclamp.set(true);  
    //c1.Screen.print(Frontclamp.value());


    wait(5, msec);
  }

  

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