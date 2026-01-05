#include "led_controller.h"
#include <esp32-hal-gpio.h>
#include "global_state.h"
#include "esp32_config.h"

void turn_on(int led_port)
{
  digitalWrite(led_port, HIGH);
}

void turn_off(int led_port)
{
  digitalWrite(led_port, LOW);
}

void leds_behaviour()
{
  if (greenOn != 0 || redOn != 0)
  {
    if (greenOn == 1000)
    {
      turn_on(GREEN_LED);
    }
    if (redOn == 1000)
    {
      turn_on(RED_LED);
    }
    greenOn == 0 ? greenOn : greenOn--;
    redOn == 0 ? redOn : redOn--;
  }
}

void led_loop()
{
  leds_behaviour();
  if (greenOn == 0)
  {
    turn_off(GREEN_LED);
  }
  if (redOn == 0)
  {
    turn_off(RED_LED);
  }
}