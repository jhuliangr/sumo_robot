#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <WiFi.h>

void controlMotors(String direction, int speed);
void stopMotors();
void safety_stop();

#endif