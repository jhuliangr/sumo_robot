#include "esp32-hal-gpio.h"
#include "global_state.h"
#include "esp32_config.h"

void config_esp32()
{
  // Initialize motor control pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);

  // initialize leds
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Initialize PWM pins (standard analogWrite for ESP32)
  // ESP32 will use ledc behind the scenes automatically
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);

  // Enable the driver (take out of standby)
  digitalWrite(STBY, HIGH);
}