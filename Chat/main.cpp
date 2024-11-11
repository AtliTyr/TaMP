#include "mainwindow.h"
//#include "RegistrationOrAuthorization.h"
#include "singletonclient.h"
#include <QApplication>
#include <QDebug>


using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //SingletonClient::getInstance();

    return a.exec();
}
