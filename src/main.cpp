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


}

void autonRightSideWinAndMiddle() {

  Lift.setStopping(vex::brakeType::hold);
  Claw.setBrake(vex::brakeType::hold);

  // LeftDriveSmart.spinFor(reverse, 1.05, seconds); (if shit goes wrong)
  Frontclamp.set(false);
  Drivetrain.setTurnVelocity(200, rpm);
  Drivetrain.turnFor(right, 97.5, deg);
  Drivetrain.setDriveVelocity(200,rpm);
  Drivetrain.driveFor(reverse, 52, inches, false);
  wait(1, sec);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 25, inches);
  Frontclamp.set(false);
  Drivetrain.driveFor(forward, 10, inches);
  Drivetrain.turnFor(left, 200, degrees);
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
  Drivetrain.turnFor(left, 120, degrees);
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
  Drivetrain.turnFor(right, 86, deg);
  Drivetrain.driveFor(forward, 85, inches, false);
  wait(1.825, sec);
  Claw.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(left, 115, deg);
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
  Drivetrain.turnFor(left, 86, deg);
  Drivetrain.driveFor(forward, 85, inches, false);
  wait(1.825, sec);
  Claw.spinFor(reverse, 1.3, sec);
  Drivetrain.turnFor(right, 130, deg);
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
  Drivetrain.driveFor(reverse, 17.5, inches, true);
  Claw.setBrake(vex::brakeType::hold);
  Drivetrain.setTurnVelocity(100, pct);
  Drivetrain.turnFor(right, 193.5, deg);//197.5 //190
  
  //Get yellow mobile goal and stack
  Drivetrain.stop();
  Drivetrain.driveFor(reverse, 120, inches, false);
  wait(2.5, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.turnFor(right, 90, degrees);//92.5
  Drivetrain.stop();
  wait(100, msec);
  Drivetrain.driveFor(reverse, 82.5, inches, false);
  //wait(0.1, sec);
  Lift.setVelocity(100, pct);
  Lift.spinFor(forward, 2.2, seconds);
  RightDriveSmart.setVelocity(100, pct);
  RightDriveSmart.spinFor(forward, 0.5, seconds);
  wait(0.5, seconds);
  Lift.spinFor(reverse, 0.8, seconds);
  Frontclamp.set(false);
  wait(.8, sec);
  Drivetrain.driveFor(forward, 10, inches, false);
  Lift.spinFor(forward, 0.4, sec);
  wait(0.2, sec);
  Drivetrain.driveFor(forward, 10, inches, false);
  Lift.spinFor(forward, 0.4, seconds);//0.4
  

  //Take win point mobile goal and stack on opposite bridge
  wait(1, sec);
  Drivetrain.turnFor(left, 191, degrees);//200
  Drivetrain.stop();
  wait(1, sec);
  Lift.spinFor(reverse, 2, seconds);
  Drivetrain.driveFor(reverse, 95, inches, false);
  Frontclamp.set(false);
  wait (2, seconds);
  Frontclamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 10, inches, true);
  Drivetrain.turnFor(left, 297.5, degrees);//300 //292.5
  Drivetrain.stop();
  Drivetrain.driveFor(reverse, 180, inches, false); //160
  wait(1.4, sec);//2
  Lift.spinFor(forward, 2, seconds);
  wait(2, sec);
  LeftDriveSmart.spinFor(forward, 0.5, seconds);
  wait(0.5, seconds);
  Lift.spinFor(reverse, 0.6, seconds);
  Frontclamp.set(false);
  wait(1, sec);
  Drivetrain.driveFor(forward, 10, inches, false);
  Lift.spinFor(forward, 0.4, sec);
  wait(0.4, sec);
  Drivetrain.driveFor(forward, 10, inches, true);
  //Drivetrain.turnFor(right, 10, degrees);
  Lift.spinFor(forward, 0.6, seconds);
  Drivetrain.turnFor(right, 30, degrees);//
  Drivetrain.driveFor(forward, 110, inches); //90

  //140
  Drivetrain.turnFor(left, 102.5, deg);
  Lift.spinFor(reverse, 2, sec);
  Frontclamp.set(false);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 120, inches, false);
  wait(2, sec);
  Frontclamp.set(true);
  wait(0.8, sec);
  Drivetrain.driveFor(forward, 170, inches, true);
  Drivetrain.stop();
}


//constants to modify in the future
double kP = 0.12;
double kI = 0.12; //0.12
double kD = 0.12; //0.12

double turnkP = 1;
double turnkI = 1;
double turnkD = 1;

int error; //position - desired value
int prevError = 0; //position 20 ms ago
int derivative; //error - prevError;
int totalError = 0; //totalError = totalError + error;

int turnError;
int turnPrevError = 0;
int turnDerivative;
int turnTotalError = 0;

bool resetDriveSensors = false;


//centimeters / 7pi * 360
double desiredValue = 0;
double desiredTurnValue = 0;


int drivePID() {

  while (pid) {


    if (resetDriveSensors) {
      resetDriveSensors = false;

      LeftDriveSmart.setPosition(0, degrees);
      RightDriveSmart.setPosition(0, degrees);
    }

    int leftMotorPosition = LeftDriveSmart.position(degrees) ;
    int rightMotorPosition = RightDriveSmart.position(degrees) ;

    int avgPos = (leftMotorPosition + rightMotorPosition)/2;

    desiredValue *= (360/(4 * 3.14159));

    //Potential
    error = avgPos - desiredValue;

    //Derivative
    derivative = error - prevError;

    //Integral 
    totalError += error;

    //Turn Potential
    //turnError = DrivetrainInertial.heading() - desiredTurnValue;

    //Derivative
    turnDerivative = turnError - turnPrevError;

    //Integral
    turnTotalError += turnError;

    double motorPower = error * kP + derivative * kD + totalError * kI;
    c1.Screen.clearLine(3);
    c1.Screen.print(error);

    double turnMotorPower = turnError * kP + turnDerivative * kD + turnTotalError * kI * 0;

    LeftDriveSmart.spin(forward, motorPower + turnMotorPower, volt);
    RightDriveSmart.spin(forward, motorPower - turnMotorPower, volt);



    prevError = error;
    turnPrevError = turnError;

    vex::task::sleep(2000);
  }


  return 1;
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
  pid = true;
  vex::task PID(drivePID);
  resetDriveSensors = true;
  desiredValue = 0;

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