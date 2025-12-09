#ifndef GLOBAL_STATE_H
#define GLOBAL_STATE_H

#include <WebServer.h>
#include <WebSocketsServer.h>

#define AIN1 27
#define AIN2 14
#define BIN1 33
#define BIN2 25
#define PWMA 12
#define PWMB 32
#define STBY 13
#define RED_LED 0
#define GREEN_LED 4

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