#include <Arduino.h>
#include "global_state.h"
#include "motor_controller.h"
#include "esp32_config.h"

void controlMotors(String direction, int speed)
{
  if (!motorsEnabled)
    return;

  // Ensure speed is within valid range
  speed = constrain(speed, 0, 255);

  if (direction == "stop")
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }
  if (direction == "forward" || direction == "left" || direction == "right")
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
  if (direction == "left")
  {
    analogWrite(PWMA, speed * 0.5);
    analogWrite(PWMB, speed);
  }
  else if (direction == "right")
  {
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed * 0.5);
  }
  else if (direction == "backward")
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
  }
  else
  {
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
  }
}

void stopMotors()
{
  redOn = 1000;
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void safety_stop()
{
  if (motorsEnabled && millis() - lastCommandTime > SAFETY_TIMEOUT && currentDirection != "stop")
  {
    stopMotors();
    currentDirection = "stop";
    currentSpeed = 0;
  }
}
