#include <debug.h>

int main()
{
    SYSLOG_EMERG("%s(%d): This is an emerg message", __func__, __LINE__);
    SYSLOG_ALERT("%s(%d): This is an alert message", __func__, __LINE__);
    SYSLOG_CRIT("%s(%d): This is a crit message", __func__, __LINE__);
    SYSLOG_ERR("%s(%d): This is an err message", __func__, __LINE__);
    SYSLOG_WARNING("%s(%d): This is a warning message", __func__, __LINE__);
    SYSLOG_NOTICE("%s(%d): This is a notice message", __func__, __LINE__);
    SYSLOG_INFO("%s(%d): This is an info message", __func__, __LINE__);
    SYSLOG_DEBUG("%s(%d): This is a debug message", __func__, __LINE__);

    return 0;
}
