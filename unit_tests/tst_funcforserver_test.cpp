#include <QtTest>
#include "../echoServer/functionsforserver.h"
#include "../echoServer/mytcpserver.h"
// add necessary includes here

class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void test_parsing();
    void test_connection();
};

FuncForServer_Test::FuncForServer_Test()
{
}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::test_parsing()
{
    // Тест parsing с неверной командой
    // Ожидается invalid command!
    QVERIFY2(parsing("ewqeewqewq").toStdString() == "invalid command!", "parsing(\"ewqeewqewq\") != invalid command!");

    // reg ожидается с 3 аргументами
    // Тест parsing с командой reg с недостаточным числом аргументов
    // Ожидается not enough arguments!
    QVERIFY2(parsing("reg&1").toStdString() == "not enough arguments!", "parsing(\"reg&1\") != not enough arguments!");
    QVERIFY2(parsing("reg&1&2").toStdString() == "not enough arguments!", "parsing(\"reg&1&2\") != not enough arguments!");
    QVERIFY2(parsing("reg").toStdString() == "not enough arguments!", "parsing(\"reg\") != not enough arguments!");

    // auth ожидается с 2 аргументами
    // Тест parsing с командой auth с недостаточным числом аргументов
    // Ожидается not enough arguments!
    QVERIFY2(parsing("auth").toStdString() == "not enough arguments!", "parsing(\"auth\") != not enough arguments!");
    QVERIFY2(parsing("auth&1").toStdString() == "not enough arguments!", "parsing(\"auth&1\") != not enough arguments!");

    // stat ожидается с 1 аргументом
    // Тест parsing с командой stat с недостаточным числом аргументов
    // Ожидается not enough arguments!
    QVERIFY2(parsing("stat").toStdString() == "not enough arguments!", "parsing(\"stat\") != not enough arguments!");

    // check ожидается 3 аргументами
    // Тест parsing с командой check с недостаточным числом аргументов
    // Ожидается not enough arguments!
    QVERIFY2(parsing("check").toStdString() == "not enough arguments!", "parsing(\"check\") != not enough arguments!");
    QVERIFY2(parsing("check&1").toStdString() == "not enough arguments!", "parsing(\"check&1\") != not enough arguments!");
    QVERIFY2(parsing("check&1&2").toStdString() == "not enough arguments!", "parsing(\"check&1&2\") != not enough arguments!");
}

void FuncForServer_Test::test_connection()
{
    MyTcpServer testServer;

    QTcpSocket* testClient = new QTcpSocket();;

    // Адрес, на котором стоит сервер
    QString address1 = "127.0.0.1";
    // Некоторый случайный адрес
    QString address2 = "192.169.1.243";

    // Порт, который прослушивает адрес
    quint16 port1 = 33333;
    // Случайный порт
    quint16 port2 = 14567;

    // Подключение к адресу с верным адресом и портом
    // Ожидание -> Успех
    testClient->connectToHost(address1, port1);
    QVERIFY2(testClient->waitForConnected(2000) == true, "Unsuccessful connection to server(127.0.0.1:33333) \n"
                                                           "through address(127.0.0.1:33333)");
    testClient->abort();
    // Подключение к адресу с верным адресом и случайным портом
    // Ожидание -> Ошибка
    testClient->connectToHost(address1, port2);
    QVERIFY2(testClient->waitForConnected(2000) != true, "Successful connection to server(127.0.0.1:33333) \n"
                                                           "through address(127.0.0.1:14567)");
    testClient->abort();
    // Подключение к адресу с случайным адресом и верным портом
    // Ожидание -> Ошибка
    testClient->connectToHost(address2, port1);
    QVERIFY2(testClient->waitForConnected(2000) != true, "Successful connection to server(127.0.0.1:33333) \n"
                                                           "through address(192.169.1.243:33333)");
    testClient->abort();
    // Подключение к адресу с случайным адресом и случайным портом
    // Ожидание -> Ошибка
    testClient->connectToHost(address2, port2);
    QVERIFY2(testClient->waitForConnected(2000) != true, "Successful connection to server(127.0.0.1:33333) \n"
                                                           "through address(192.169.1.243:14567)");
    testClient->abort();

    delete testClient;
}

QTEST_APPLESS_MAIN(FuncForServer_Test)
#include "tst_funcforserver_test.moc"
