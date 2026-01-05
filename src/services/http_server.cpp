#include "http_server.h"
#include "global_state.h"
#include "control_page.h"

void config_http_server()
{
  server.enableCORS(true);

  // Serve the main control page
  server.on("/", HTTP_GET, []()
            {
    server.send(200, "text/html", getControlPage());
    greenOn = 1000; });
  server.on("/red", HTTP_GET, []()
            {
    server.send(200, "text/html", "done");
    redOn = 1000; });
  server.on("/green", HTTP_GET, []()
            {
    server.send(200, "text/html", "done");
    greenOn = 1000; });

  server.on("/auto", HTTP_GET, []()
            {
    autoMode = true;
    autoStep = 1;
    autoStepStart = millis();
    server.send(200, "text/plain", "Auto mode started"); });

  server.onNotFound([]()
                    { server.send(404, "text/plain", "Endpoint not found. Try / or /mobile"); });

  server.begin();
}