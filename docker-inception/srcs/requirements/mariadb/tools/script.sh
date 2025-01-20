# !/bin/sh

eval "echo \"$(cat /tmp/init.sql)\"" > /tmp/init.sql

mysqld_safe --init-file=/tmp/init.sql