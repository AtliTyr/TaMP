#!/bin/bash
service mysql start
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED WITH 'mysql_native_password' BY '12345';"
sleep 2

cd /app
./echoServer
# Keep