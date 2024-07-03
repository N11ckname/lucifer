
#ifndef LOG_H
#define LOG_H

#include <Arduino.h>
#include <stdio.h>

#define LOGGING_ENABLE

namespace logging
{
  enum class severity
  {
    INFO = 0,
    WARNING,
    ERROR,
    FATAL
  };

  template<typename First>
  void log_backend(First first) {
#ifdef LOGGING_ENABLE
      Serial.print(first);
      Serial.print("\n");
#endif()
  }

  template<typename First, typename ...Rest>
  void log_backend(First first, Rest ...rest) {
#ifdef LOGGING_ENABLE
      // log_backend(first);
      Serial.print(first);
      Serial.print(",");
      log_backend(rest...); // Call recursively for the rest of the arguments
#endif()
  }

  template <typename N, typename ...Args>
  void log_header(N name, Args ...args)
  {
    log_backend(name, "timelog_us", args...);
  }

  template <typename N, typename ...Args>
  void log(N name, Args ...args)
  {
    log_backend(name, micros(), args...);
  }

  template <typename N>
  void log_console_header(N name)
  {
    log_backend(name, "timelog_us", "severity", "msg");
  }

  template <typename N, typename Arg>
  void log_console(N name, severity s, Arg arg)
  {
    log_backend(name, micros(), static_cast<int>(s), arg);
  }
}

#endif /* LOG_H */
