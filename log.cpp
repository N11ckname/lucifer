#include "log.h"

namespace logging {

  void log_console_header(const char * name)
  {
    log_backend("name", "timelog_us", "severity", "msg");
  }

}