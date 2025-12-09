#include "global_state.h"
#include "motor_controller.h"
#include "predefined_behaviours.h"

void runRightAttackSequence()
{
  if (!autoMode)
    return;

  switch (autoStep)
  {

  case 1:
    controlMotors("right", 200);
    if (millis() - autoStepStart >= 500)
    {
      autoStep++;
      autoStepStart = millis();
    }
    break;

  case 2:
    controlMotors("forward", 200);
    if (millis() - autoStepStart >= 400)
    {
      autoStep++;
      autoStepStart = millis();
    }
    break;

  case 3:
    controlMotors("left", 200);
    if (millis() - autoStepStart >= 500)
    {
      autoStep++;
      autoStepStart = millis();
    }
    break;

  case 4:
    controlMotors("forward", 200);
    if (millis() - autoStepStart >= 800)
    {
      autoStep++;
      autoStepStart = millis();
    }
    break;

  case 5:
    controlMotors("left", 200);
    if (millis() - autoStepStart >= 500)
    {
      autoStep++;
      autoStepStart = millis();
    }
    break;

  case 6:
    controlMotors("forward", 255);
    if (millis() - autoStepStart >= 5000)
    {
      autoStep++;
    }
    break;

  case 7:
    stopMotors();
    autoMode = false;
    break;
  }
}

void loop_predefined_behaviours()
{
  if (autoMode)
    runRightAttackSequence();
}