/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ruishanliang                                              */
/*    Created:      11/16/2023, 3:39:31 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
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

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

void autonomous(void) {
  motor_group left = motor_group(leftfrontop, leftfront, leftback);
  motor_group right = motor_group(rightfrontop, rightfront, rightback);
  catapult.spin(fwd, -12, volt);
  wait(20, sec);
  catapult.stop();
  left.stop();
  right.stop();
  left.spin(fwd, 7, volt);
  wait(0.55, sec);
  left.stop();
  right.spin(fwd, 7, volt);
  wait(0.4, sec);
  right.stop();
  catapult.spin(fwd, -5, volt);
  left.spin(fwd, 12, volt);
  right.spin(fwd, 12, volt);
  wait(0.75, sec);
  left.stop();
  right.stop();
  catapult.stop();
  wait(0.5, sec);
  right.spin(fwd, 7, volt);
  wait(0.55, sec);
  right.stop();
  wait(0.5, sec);
  for (int i = 0; i < 2; i++) 
  {
    left.spin(fwd, 10, volt);
    right.spin(fwd, 10, volt);
    wait(0.4, sec);
    left.spin(directionType::rev, 9, volt);
    right.spin(directionType::rev, 9, volt);
    wait(0.3, sec);
  }
  left.stop();
  right.stop();
  wait(0.4, sec);
  right.spin(fwd, 6, volt);
  wait(0.1, sec);
  right.stop();
  wait(0.2, sec);
  left.spin(fwd, 9.5, volt);
  right.spin(fwd, 9.5, volt);
  wait(0.2, sec);
  left.stop();
  right.stop();
  wait(0.3, sec);
  left.spin(fwd, 7, volt);
  wait(0.4, sec);
  left.stop();
  left.spin(fwd, 9, volt);
  right.spin(fwd, 9, volt);
  wait(0.1, sec);
  left.stop();
  right.stop();
  wait(0.3, sec);
  left.spin(fwd, 7, volt);
  wait(0.7, sec);
  left.stop();
  left.spin(fwd, 8.5, volt);
  right.spin(fwd, 8.5, volt);
  wait(0.6, sec);
  left.spin(directionType::rev, 8.5, volt);
  right.spin(directionType::rev, 8.5, volt);
  wait(0.6, sec);
  left.stop();
  right.stop();


  // left.spin(fwd, 9, volt);
  // right.spin(fwd, 9, volt);
  // wait(0.25, sec);
  // left.stop();
  // right.stop();
  // left.spin(fwd, 7, volt);
  // wait(0.3, sec);
  // left.stop();
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
  // User control code here, inside the loop
  while (1) {
    setdrive(Controller.Axis3.value(), Controller.Axis2.value());
    setcatapult();
    setwings();
    setintake();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
    wait(100, msec);
  }
}
