#include <WiFi.h>
#include "wifi_controller.h"

void setup_access_point()
{
  WiFi.mode(WIFI_AP);
  bool apStarted = WiFi.softAP("Jhulian's robot", "13791379");
}