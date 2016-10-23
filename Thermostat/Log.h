#ifndef LOG_H
#define LOG_H
#include <Arduino.h>

class Log {
public:
   static void debug(String);
   static void error(String);
};

#endif