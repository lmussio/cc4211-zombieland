#!/bin/bash
echo "* * * * * echo \"\$(date): \$(od -An -N2 -i /dev/random)\" >> /tmp/log.txt" > crontask
crontab crontask
rm crontask
cron -f
