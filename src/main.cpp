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
  Drivetrain.setTurnVelocity(100, pct);
  Ddd.turnToRotation(-45, deg);
  Drivetrain.setDriveVelocity(200,rpm);
  Drivetrain.driveFor(reverse, 52, inches, false);
  wait(1, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 25, inches);
  Frontclamp.set(false);
  Drivetrain.driveFor(forward, 10, inches);
  Ddd.turnToRotation(35, deg);
  Drivetrain.driveFor(reverse, 130, inches, false);
  wait(2.5, sec);
  Frontclamp.set(true);
  wait(1, sec);
  Drivetrain.driveFor(forward, 115, inches, true);

}

void autonLeftSideWinPoint() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);  

  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 20, inches, false);
  wait(1.2, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 20, inches);
  Frontclamp.set(false);
  Drivetrain.driveFor(forward, 10, inches, true);
  Drivetrain.setTurnVelocity(25, pct);
  Ddd.turnToRotation(65, deg);
  Drivetrain.driveFor(reverse, 100, inches, false);
  wait(2, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 150, inches);

}

void autonMiddleLeft() {

  Claw.setBrake(vex::brakeType::hold);
  Lift.setStopping(vex::brakeType::hold);

  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, sec);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 115, inches, true);
  Claw.spinFor(forward, 0.3, sec);
  Claw.spinFor(reverse, 0.7, sec);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 95, inches);

}

void autonMiddleRight() {

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

  Claw.setBrake(vex::brakeType::hold);
  Lift.setStopping(vex::brakeType::hold);

  Claw.setVelocity(100, pct);
  Claw.spinFor(forward, 0.75, seconds);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(forward, 115, inches, true);
  Claw.spinFor(reverse, 0.7, seconds);
  wait(0.5, sec);
  Ddd.turnToRotation(-45, deg);
  Drivetrain.driveFor(reverse, 50, inches, false);
  wait(1.2, sec);
  Frontclamp.set(true);
  Ddd.turnToRotation(45, deg);
  Drivetrain.driveFor(reverse, 95, inches);

}

void fortyRight() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  Claw.setVelocity(100, pct);
  Drivetrain.setDriveVelocity(200, rpm);
  Drivetrain.driveFor(reverse, 105, inches, false);
  wait(1, sec);
  Claw.spinFor(forward, 0.75, seconds);
  wait(0.7, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Ddd.turnToRotation(48, deg);
  Drivetrain.driveFor(forward, 70, inches, false);
  wait(1.7, sec);
  Claw.spinFor(reverse, 0.7, seconds);
  Drivetrain.turnFor(left, 180, deg);
  Drivetrain.driveFor(forward, 70, inches);

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
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(left, 130, deg, true);
  Ddd.turnToHeading(-93.5, deg, true);
  Drivetrain.setTurnVelocity(25, pct);
  wait(100, msec);
  Drivetrain.driveFor(reverse, 130, inches, false);
  wait(2, seconds);
  Frontclamp.set(true);
  Lift.spinFor(forward, 250, msec);
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
  turnLeft(-20);
  Drivetrain.driveFor(reverse, 90, inches, false);
  Lift.spinFor(reverse, 2, seconds);
  wait (0.25, seconds);
  Frontclamp.set(true);
  Lift.spinFor(forward, 250, msec);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 10, inches, true);
  turnLeft(111);

  //Go to opposite bridge and stack
  Drivetrain.driveFor(reverse, 95, inches, true);
  Lift.spinFor(forward, 2, sec);
  Drivetrain.driveFor(reverse, 15, inches);
  turnRight(97);
  Drivetrain.driveFor(reverse, 25, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Lift.spinFor(forward, 0.8, sec);

  //Push big middle mobile goal back
  turnLeft(85);
  Drivetrain.driveFor(forward, 90, inches, false);
  Lift.spinFor(reverse, 2, seconds);

  //Turn and push last yellow mobile goal in zone
  turnLeft(172);
  Drivetrain.driveFor(reverse, 65, inches, true);
  turnRight(90);
  Drivetrain.driveFor(forward, 15, inches, true);
  Claw.spinFor(forward, 1.3, seconds);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.driveFor(reverse, 80, inches, true);
  Claw.spinFor(reverse, 1, sec);

  //Turn and push other win point mobile goal in zone
  Drivetrain.driveFor(forward, 10, inches, true);
  turnLeft(130);
  Drivetrain.driveFor(reverse, 30, inches, true);
  Frontclamp.set(true);
  Drivetrain.driveFor(forward, 10, inches, false);
  turnLeft(270);
  Drivetrain.driveFor(reverse, 100, inches, true);

  Drivetrain.stop();

}

void skillsBalance() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  Drivetrain.setTurnVelocity(25, pct);

  //Pick up mobile goal onto back
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
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(left, 135, deg, true);
  Ddd.turnToHeading(-93.5, deg, true);
  Drivetrain.setTurnVelocity(25, pct);
  wait(100, msec);
  Drivetrain.driveFor(reverse, 95, inches, false);
  wait(2, seconds);
  Frontclamp.set(true);
  Lift.spinFor(forward, 500, msec);
  wait(100, msec);  
  turnRight(-136);
  Claw.spinFor(forward, 1.3, sec);
  Drivetrain.driveFor(reverse, 60, inches, false);

  //Stack mobile goal
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.5, seconds);
  turnLeft(-85);
  Drivetrain.driveFor(reverse, 10, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.4, sec);
  Lift.spinFor(forward, 0.8, sec);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 15, inches, true);
  Lift.spinFor(reverse, 0.4, sec);

  //Stack other mobile goal
  turnLeft(16);
  Drivetrain.driveFor(reverse, 70, inches, false);
  Lift.spinFor(reverse, 1.65, sec);
  Frontclamp.set(true);
  Lift.spinFor(forward, 0.5, sec);

  turnLeft(101.5);
  Drivetrain.driveFor(forward, 60, inches, false);
  Claw.spinFor(forward, 0.5, sec);
  Claw.setBrake(vex::brakeType::hold);
  wait(0.75, sec);
  Claw.spinFor(reverse, 1, sec);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.driveFor(reverse, 30, inches, true);
  turnLeft(170);
  Drivetrain.driveFor(reverse, 87.5, inches, false);
  Lift.spinFor(forward, 2.5, seconds);
  wait(0.5, sec);
  turnLeft(261);
  Drivetrain.driveFor(reverse, 17, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.4, sec);
  Lift.spinFor(forward, 0.8, sec);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 15, inches, true);

  //turnRight(180);
  turnLeft(360);
  Drivetrain.driveFor(forward, 30, inches, false);//35 //reverse
  Lift.spinFor(reverse, 2, sec);
  turnLeft(420);//97.5 //turnRight
  Drivetrain.driveFor(reverse, 120, inches, false);
  wait(0.6, sec);
  Frontclamp.set(true);
  Lift.spinFor(forward, 2.5, sec);

  //Align
  wait(0.5, sec);
  turnRight(5);
  Ddd.turnToHeading(0, deg);
  Claw.setVelocity(50, pct);
  Claw.spinFor(reverse, 0.5, sec);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.driveFor(reverse, 20, inches, false);
  Lift.spinFor(reverse, 3, sec);
  Drivetrain.setDriveVelocity(75, pct);
  Lift.spinFor(reverse, 1, sec);
  Drivetrain.driveFor(reverse, 50, inches, false);
  wait(0.3, sec);
  Lift.spinFor(forward, 1, sec);
  Lift.setStopping(vex::brakeType::hold);
  Drivetrain.setDriveVelocity(30, pct);

  while(DrivetrainInertial.pitch() >= 9.5)
  {
    Drivetrain.drive(reverse);
  }
  Drivetrain.driveFor(forward, 10, inches);

  Drivetrain.stop();

}

void combinedSkills() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  Drivetrain.setTurnVelocity(25, pct);

  //Pick up mobile goal onto back
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
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(left, 135, deg, true);
  Ddd.turnToHeading(-93.5, deg, true);
  Drivetrain.setTurnVelocity(25, pct);
  wait(100, msec);
  Drivetrain.driveFor(reverse, 95, inches, false);
  wait(2, seconds);
  Frontclamp.set(true);
  Lift.spinFor(forward, 500, msec);
  wait(100, msec);  
  turnRight(-136);
  Drivetrain.driveFor(reverse, 65, inches, false);

  //Stack mobile goal
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.5, seconds);
  turnLeft(-85);
  Drivetrain.driveFor(reverse, 10, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.4, sec);
  Lift.spinFor(forward, 0.8, sec);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 15, inches, true);
  Lift.spinFor(reverse, 0.4, sec);

  //Take win point mobile goal
  turnLeft(-22);
  Drivetrain.driveFor(reverse, 87, inches, false);
  Lift.spinFor(reverse, 2, seconds);
  wait (0.25, seconds);
  Frontclamp.set(true);
  Lift.spinFor(forward, 0.8, sec);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 15, inches, true);
  turnLeft(111);

  //Go to opposite bridge and stack
  Drivetrain.driveFor(reverse, 90, inches, true);
  Lift.spinFor(forward, 2, sec);
  Drivetrain.driveFor(reverse, 15, inches);
  turnRight(97);
  Drivetrain.driveFor(reverse, 25, inches, true);
  Lift.spinFor(reverse, 1.2, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Lift.spinFor(forward, 0.8, sec);

  //Push big middle mobile goal back
  turnLeft(83.2);
  Drivetrain.driveFor(forward, 90, inches, false);
  Lift.spinFor(reverse, 2, seconds);

  //Turn and push last yellow mobile goal in zone
  turnLeft(172);
  Drivetrain.driveFor(reverse, 56.25, inches, true);
  turnRight(90);
  Drivetrain.driveFor(forward, 15, inches, true);
  Claw.spinFor(forward, 1.3, seconds);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.driveFor(reverse, 80, inches, true);
  Claw.spinFor(reverse, 1, sec);

  //Turn and push other win point mobile goal in zone
  Drivetrain.driveFor(forward, 10, inches, true);
  turnLeft(130);
  Drivetrain.driveFor(reverse, 36.8, inches, true);
  Frontclamp.set(true);
  Drivetrain.driveFor(forward, 10, inches, false);
  turnLeft(270);
  Drivetrain.driveFor(reverse, 90, inches, true);
  Drivetrain.stop();

}

void balance() {

  //Frontclamp.set(false);
  Claw.setVelocity(50, pct);
  Claw.spinFor(reverse, 0.1, sec);
  Claw.setBrake(vex::brakeType::hold);
  Lift.setVelocity(100, pct);
  Lift.spinFor(reverse, 0.5, sec);
  Drivetrain.setDriveVelocity(75, pct);
  Drivetrain.driveFor(reverse, 70, inches, false);
  wait(0.7, sec);
  Frontclamp.set(true);
  Lift.spinFor(forward, 0.8, sec);
  Lift.setStopping(vex::brakeType::hold);
  wait(2, sec);
  Drivetrain.setDriveVelocity(30, pct);

  while(DrivetrainInertial.pitch() >= 9.5)
  {
    if (c1.ButtonX.pressing())
    {
      Drivetrain.stop();
      break;
    }
    Drivetrain.drive(reverse);
  }
  Drivetrain.driveFor(forward, 13, inches);

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
    case 2: autonMiddleLeft(); break;
    case 3: autonMiddleRight(); break;
    case 4: autonLeftSideWinPoint(); break;
    case 5: autonRightSideWinAndMiddle(); break;
    case 6: fortyLeft(); break;
    case 7: fortyRight(); break;
    case 8: skills(); break;
    case 9: combinedSkills(); break;
    case 10: skillsBalance(); break;
    default: autonDefault(); break;
  }
}

void autonomous(void) {

  //1 is auton default
  //2 is auton middle left
  //3 is auton middle right
  //4 is left side win point
  //5 is right side win point
  //6 is 40 left
  //7 is 40 right
  //8 is skills
  //9 is combined skills
  //10 is skillsBalance
  //default is auton default

  runAuton(9);

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

    //Park
    if (c1.ButtonA.pressing() && c1.ButtonB.pressing())
      balance();

    if (c1.ButtonX.pressing())
      Drivetrain.stop();


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