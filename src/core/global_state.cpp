#include <WebServer.h>
#include <WebSocketsServer.h>
#include "global_state.h"

int redOn = 1000;
int greenOn = 1000;

// For predefined behaviours
bool autoMode = false;
uint8_t autoStep = 0;
unsigned long autoStepStart = 0;

const int PWM_FREQ = 1000;    // 1kHz
const int PWM_RESOLUTION = 8; // 8-bit (0-255)

WebServer server(80);
WebSocketsServer webSocket(81);

// Motor control variables
int currentSpeed = 0;
String currentDirection = "stop";
bool motorsEnabled = true;
unsigned long lastCommandTime = 0;
const unsigned long SAFETY_TIMEOUT = 5000;