
using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial DrivetrainInertial;
extern smartdrive Ddd;
extern drivetrain Drivetrain;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern motor_group Lift;
extern motor Claw;
extern motor Clamp;
extern digital_out Frontclamp;
extern controller c1;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

//for temperature rumbling
void rumbleController (int rumbling);