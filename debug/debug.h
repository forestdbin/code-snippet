#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <syslog.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef DEBUG

#ifndef DEFAULT_FACILITY
#define DEFAULT_FACILITY LOG_LOCAL7
#endif

#define SYSLOG(level, ...)  syslog(DEFAULT_FACILITY | level, __VA_ARGS__)

#define SYSLOG_EMERG(...)   SYSLOG(LOG_EMERG,   __VA_ARGS__)
#define SYSLOG_ALERT(...)   SYSLOG(LOG_ALERT,   __VA_ARGS__)
#define SYSLOG_CRIT(...)    SYSLOG(LOG_CRIT,    __VA_ARGS__)
#define SYSLOG_ERR(...)     SYSLOG(LOG_ERR,     __VA_ARGS__)
#define SYSLOG_WARNING(...) SYSLOG(LOG_WARNING, __VA_ARGS__)
#define SYSLOG_NOTICE(...)  SYSLOG(LOG_NOTICE,  __VA_ARGS__)
#define SYSLOG_INFO(...)    SYSLOG(LOG_INFO,    __VA_ARGS__)
#define SYSLOG_DEBUG(...)   SYSLOG(LOG_DEBUG,   __VA_ARGS__)

#else

#define SYSLOG_EMERG(...)
#define SYSLOG_ALERT(...)
#define SYSLOG_CRIT(...)
#define SYSLOG_ERR(...)
#define SYSLOG_WARNING(...)
#define SYSLOG_NOTICE(...)
#define SYSLOG_INFO(...)
#define SYSLOG_DEBUG(...)

#endif

#ifdef __cplusplus
}
#endif

#endif // _DEBUG_H_
