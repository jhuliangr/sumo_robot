#include "global_state.h"
#include "motor_controller.h"
#include "websocket_handler.h"

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
  if (type == WStype_TEXT)
  {
    String msg = (char *)payload;

    if (msg == "stop")
    {
      autoMode = false;
      autoStep = 0;
      currentDirection = "stop";
      stopMotors();
    }

    if (msg.startsWith("left") || msg.startsWith("right") || msg.startsWith("backward") || msg.startsWith("forward"))
    {
      int separatorIndex = msg.indexOf(":");
      String direction = msg.substring(0, separatorIndex);
      int speed = msg.substring(separatorIndex + 1).toInt();
      controlMotors(direction, speed);
      currentSpeed = speed;
      currentDirection = direction;
      lastCommandTime = millis();
    }
  }
}

void setup_websocket()
{
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}