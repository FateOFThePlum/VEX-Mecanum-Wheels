#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller1 = controller(primary);
motor Motor1 = motor(PORT1, ratio18_1, false);

motor Motor2 = motor(PORT2, ratio18_1, false);

motor Motor3 = motor(PORT3, ratio18_1, false);

motor Motor4 = motor(PORT4, ratio18_1, false);




// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration
float X1, X2, Y1, OVER;

void omni(){
  X1 = Controller1.Axis4.position();
  Y1 = Controller1.Axis3.position();
  X2 = Controller1.Axis1.position();
  X2 = X2*0.75; // Allows For Higher Turning Speed

  Motor1.setVelocity((OVER * (Y1 + X1 + X2)), percent);
  Motor2.setVelocity((OVER * (Y1 - X1 - X2)), percent);
  Motor3.setVelocity((OVER * (Y1 + X1 - X2)), percent);
  Motor4.setVelocity((OVER * (Y1 - X1 + X2)), percent);
  // Break
  if (Y1 + X1 + X2 > 100.0) {
    OVER = 100.0 / (Y1 + X1 + X2);
  } else if (-100.0 > Y1 + X1 + X2) {
    OVER = 100.0 / (Y1 + X1 + X2);
  
  } else if (Y1 - X1 - X2 > 100.0) {
    OVER = 100.0 / (Y1 - X1 - X2);
  } else if (-100.0 > Y1 - X1 - X2) {
    OVER = 100.0 / (Y1 - X1 - X2);

  } else if (Y1 + X1 - X2 > 100.0) {
    // Break
    OVER = 100.0 / (Y1 + X1 - X2);
  } else if (-100.0 > Y1 + X1 - X2) {
    // Break
    OVER = 100.0 / (Y1 + X1 - X2);
  
  }
   else if (Y1 - X1 + X2 > 100.0) {
      OVER = 100.0 / (Y1 - X1 + X2);
    } else if (-100.0 > Y1 - X1 + X2) {
      OVER = 100.0 / (Y1 - X1 + X2);
    
    } else {
      OVER = 1.0; //Won't Affect Wheel Speed At All
    }
  } 



int whenStarted1() {
  Motor1.spin(forward); //Setting Up Variables and Motors
  Motor2.spin(forward);
  Motor3.spin(forward);
  Motor4.spin(forward);
  OVER = 1.0;

  while (true) {
    omni();
    wait(5, msec);
  }
}




int main() {
  // set default print color to black
  printf("\033[30m");
  whenStarted1(); //Start Main Loop
}
