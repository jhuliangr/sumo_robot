#include "predefined_behaviours.h"
#include "websocket_handler.h"
#include "motor_controller.h"
#include "led_controller.h"
#include "esp32_config.h"
#include "global_state.h"
#include "http_server.h"
#include "wifi_config.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  config_esp32();
  setup_access_point();
  setup_websocket();
  config_http_server();
  stopMotors();
}

void loop()
{
  led_loop();
  webSocket.loop();
  server.handleClient();
  loop_predefined_behaviours();
  safety_stop();
}
