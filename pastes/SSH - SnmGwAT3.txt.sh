#!/bin/bash
CPUTIME=$(ps -eo pcpu | awk 'NR>1' | awk '{tot=tot+$1} END {print tot}')
CPUCORES=$(cat /proc/cpuinfo | grep -c processor)
CPUTEMP=$(sensors | grep Core | awk -F: ' { print $2 } '| cut -c8-9 | tr "n" " " | awk '{tot=tot+$1} END {print tot}')
echo "
System Summary (collected `date`)

 - CPU Usage (average)       = `echo $CPUTIME / $CPUCORES | bc`%
 - CPU Temperature (average) = `echo $CPUTEMP / $CPUCORES | bc`c
 - Memory free (real)        = `free -m | head -n 2 | tail -n 1 | awk {'print $4'}` Mb
 - Memory free (cache)       = `free -m | head -n 3 | tail -n 1 | awk {'print $3'}` Mb
 - Swap in use               = `free -m | tail -n 1 | awk {'print $3'}` Mb
 - System Uptime             = `uptime`
 - Public IP                 = `curl -s http://ip.appspot.com`
 - Disk Space Used           = `df -h / | awk '{ a = $4 } END { print a }'`
 
" > /etc/motd