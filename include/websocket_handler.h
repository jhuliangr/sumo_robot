#ifndef WEBSOCKET_HANDLER_H
#define WEBSOCKET_HANDLER_H

#include <WebSockets.h>

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length);
void setup_websocket();

#endif