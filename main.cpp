#include <QCoreApplication>
#include "mytcpserver.h"
#include "mydb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer myserv;


    return a.exec();
}
