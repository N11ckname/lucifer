#include "log.h"

namespace logging {

  void log_console_header(String name)
  {
    log_backend("name", "timelog_us", "severity", "msg");
  }

}