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

/*
 * With new speed 
 * multiply distance value by about 0.611
 * multiply turn value by about 0.66
 */

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  LeftDriveSmart.setStopping(brakeType::brake);
  RightDriveSmart.setStopping(brakeType::brake);

  DrivetrainInertial.setHeading(0, deg);


}

void inertialGyro(double d, bool b) {

  Ddd.turnToHeading(d, degrees, b);
  
  while (Ddd.isTurning()) {
    if (Ddd.heading() + 1 == d || Ddd.heading()-1 == d)
      Ddd.stop();
  }

}

void autonRightSideWinAndMiddle() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  // LeftDriveSmart.spinFor(reverse, 1.05, seconds); (if shit goes wrong)
  Frontclamp.set(false);
  Drivetrain.setTurnVelocity(100, pct);
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
  Drivetrain.setTurnVelocity(100, pct);
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
  Drivetrain.driveFor(reverse, 175, inches, false);
  Frontclamp.set(false);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  wait(3, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 160, inches, true);
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


  Drivetrain.setDriveVelocity(200, rpm);
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
  Drivetrain.turnFor(right, 86, deg);
  Drivetrain.driveFor(forward, 85, inches, false);
  wait(1.825, sec);
  Claw.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(left, 130, deg);
  Drivetrain.driveFor(forward, 120, inches);
}

void skills() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  //Get mobile goal on back and turn
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, seconds);
  Frontclamp.set(false);
  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, seconds);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 20, inches, false);
  wait(0.8, seconds);
  Claw.setVelocity(50, pct);
  Claw.spinFor(reverse, 1, seconds);//0.75
  Drivetrain.driveFor(reverse, 15, inches, true);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(left, 130, deg);//193.5 //130
  inertialGyro(-93.5, true);
  wait(100, msec);
  
  //Get yellow mobile goal and stack
  Drivetrain.driveFor(reverse, 80, inches, false);//120
  wait(2, seconds);
  Frontclamp.set(true);
  wait(100, msec);
  Drivetrain.turnFor(left, 80, degrees, true);//90
  inertialGyro(-135, true);
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.2, seconds);
  wait(100, msec);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.driveFor(reverse, 62.5, inches, true);//82.5
  inertialGyro(-90, true);
  Drivetrain.driveFor(reverse, 10, inches, true);
  wait(0.5, seconds);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Lift.spinFor(forward, 0.8, sec);
  Drivetrain.driveFor(forward, 7.5, inches, false);
  Lift.spinFor(forward, 0.4, seconds);//0.4
  

  //Take win point mobile goal and stack on opposite bridge
  wait(1, sec);
  Lift.spinFor(reverse, 2, seconds);
  wait(1, sec);
  inertialGyro(-3, true); //Drivetrain.turnFor(right, 120, degrees);//191 //127
  Drivetrain.stop();
  wait(1, sec);
  Drivetrain.driveFor(reverse, 58, inches, false);//95
  Frontclamp.set(false);
  wait (1.75, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 10, inches, true);
  inertialGyro(110, true); //Drivetrain.turnFor(right, 180, degrees);//297.5
  Drivetrain.stop();
  Drivetrain.driveFor(reverse, 110, inches, false); //180
  wait(1.4, sec);//2
  Lift.spinFor(forward, 2, seconds);
  wait(2, sec);
  inertialGyro(-90, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Lift.spinFor(forward, 0.8, sec);
  Drivetrain.driveFor(forward, 7.5, inches, false);
  Lift.spinFor(forward, 0.4, seconds);//0.4
  Drivetrain.driveFor(forward, 10, inches, false);
  Lift.spinFor(reverse, 2, seconds);
  Drivetrain.driveFor(forward, 68, inches); //110

  //140
  Drivetrain.turnFor(right, 33, deg);//102
  Lift.spinFor(reverse, 2, sec);
  Frontclamp.set(false);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 74, inches, false);//120
  wait(2, sec);
  Frontclamp.set(true);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 104, inches, true);//170
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

  //c1.Screen.print(10);

  while(true) {
    //c1.Screen.clearLine(3);

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