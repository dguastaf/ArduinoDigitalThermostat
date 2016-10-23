#include "Log.h"
#include <Arduino.h>

#define ENABLE_DEBUG_LOG true
#define ENABLE_ERROR_LOG true

void Log::debug(String message) {
   if (ENABLE_DEBUG_LOG) {
      Serial.println(message);
   }
}

void Log::error(String message) {
   if (ENABLE_ERROR_LOG) {
      Serial.println(message);
   }
}
