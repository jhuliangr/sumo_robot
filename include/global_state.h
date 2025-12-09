#ifndef GLOBAL_STATE_H
#define GLOBAL_STATE_H

#include <WebServer.h>
#include <WebSocketsServer.h>

extern int redOn;
extern int greenOn;

extern bool autoMode;
extern uint8_t autoStep;
extern unsigned long autoStepStart;

extern const int PWM_FREQ;    // 1kHz
extern const int PWM_RESOLUTION; // 8-bit (0-255)

extern WebServer server;
extern WebSocketsServer webSocket;

extern int currentSpeed;
extern String currentDirection;
extern bool motorsEnabled;
extern unsigned long lastCommandTime;
extern const unsigned long SAFETY_TIMEOUT;

#endif