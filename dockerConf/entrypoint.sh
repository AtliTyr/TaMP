#!/bin/bash
service mysql start
sleep 2
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED WITH 'mysql_native_password' BY '12345';"

cd /app
./echoServer
# Keep