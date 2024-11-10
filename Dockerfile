# Используем официальный образ Ubuntu в качестве базового
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем необходимые зависимости
RUN apt-get update && apt-get install -y build-essential

RUN apt-get install -y qt5-qmake qtbase5-dev

RUN apt-get install -y mysql-server unixodbc odbcinst libqt5sql5-odbc

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем все файлы из текущей директории в контейнер
#COPY . .

COPY ./*.cpp .
COPY ./*.h .
COPY ./echoServer* .
COPY ./dockerConf .

# Установка .deb пакета
RUN apt-get install -y ./mysql-connector-odbc_9.1.0-1ubuntu22.04_amd64.deb
# Удаление .deb пакета после установки
RUN rm ./mysql-connector-odbc_9.1.0-1ubuntu22.04_amd64.deb

RUN myodbc-installer -s -a -c2 -n "TestDSN" -t "DRIVER=MySQL ODBC 9.1 Unicode Driver;SERVER=localhost;UID=root;PWD=12345"

RUN usermod -d /var/lib/mysql/ mysql

RUN chmod +x /app/entrypoint.sh

# Конфигурируем проект на основе .pro файла
RUN qmake echoServer.pro
RUN make

EXPOSE 33333

# Указываем команду, которая будет выполнена при запуске контейнера

ENTRYPOINT ["/app/entrypoint.sh"]
#CMD ["tail", "-f", "/dev/null"]