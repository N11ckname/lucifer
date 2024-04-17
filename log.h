
#ifndef LOGGING_H_
#define LOGGING_H_

#include <arduino.h>
#include <stdio.h>

namespace logging
{
  template<typename First>
  void log_backend(First first) {
      Serial.print(first);
      Serial.print("\n");
  }

  template<typename First, typename ...Rest>
  void log_backend(First first, Rest ...rest) {
      Serial.print(first);
      Serial.print(",");
      log_backend(rest...); // Call recursively for the rest of the arguments
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


  void log_msg_header(const char * source)
  {
    log_backend("msg", "timelog_us", "source", "severity", "payload");
  }

  template <typename ...Args>
  void log_msg(const char * source, Args ...args)
  {
    log_backend("msg     ", "timelog_us", args...);

    log_backend(name, micros(), args...);
  }


      msg, timelog_us, source, severity, payload 

}

#endif /* LOGGING_H_ */
