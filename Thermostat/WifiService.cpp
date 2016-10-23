#include <WiFi101.h>

#include "WifiService.h"
#include "Secrets.h"
#include "Log.h"
  
boolean isShieldPresent() {
  return WiFi.status() != WL_NO_SHIELD;
}
  
boolean WiFiService::connectToWifi() {
  if (!isShieldPresent()) {
    Log::error("Couldn't find WiFi shield");
    return false;
  }

  String connectingStr = "Connecting to " + SSID;
  Log::debug(connectingStr);
  
  int status = WiFi.begin(SSID, WIFI_PASSWORD);
  boolean isConnected = status == WL_CONNECTED;

  if (isConnected) {
   Log::debug("Connected to WiFi");
  } else {
   Log::error("Failed to connect to WiFi");
  }
  return isConnected;
}
