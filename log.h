
#ifndef LOG_H
#define LOG_H

#include <Arduino.h>
#include <stdio.h>

// #define LOGGING_ENABLE

namespace logging
{
  enum class severity : uint8_t
  {
    INFO,
    WARNING,
    ERROR,
    FATAL
  };

  template<typename First>
  void log_backend(First first) {
// #ifdef LOGGING_ENABLE
      Serial.print(first);
      Serial.print("\n");
// #endif
  }

  template<typename First, typename ...Rest>
  void log_backend(First first, Rest ...rest) {
// #ifdef LOGGING_ENABLE
      Serial.print(first);
      Serial.print(",");
      log_backend(rest...); // Call recursively for the rest of the arguments
// #endif
  }

  template <typename ...Args>
  void log_header(const char * name, Args ...args)
  {
    log_backend(name, "timelog_us", args...);
  }

  template <typename ...Args>
  void log(const char * name, Args ...args)
  {
    log_backend(name, micros(), args...);
  }

  void log_console_header(const char * name);

  template <typename Arg>
  void log_console(const char * name, severity s, Arg arg)
  {
    log_backend(name, "timelog_us", static_cast<int>(s), arg);
  }
}

#endif /* LOG_H */
