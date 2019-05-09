# config rsyslog to filter local7's logs

```bash
$ cat /etc/rsyslog.d/debug.conf
local7.* -/var/log/debug.log
&~

# service rsyslog restart
# systemctl restart rsyslog.service

$ cat /etc/rsyslog.conf
$IncludeConfig /etc/rsyslog.d/*.conf
*.emerg :omusrmsg:*

$ cat /etc/systemd/journald.conf
ForwardToWall=no
```
