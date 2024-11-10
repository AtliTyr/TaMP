#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>

#include "functionsforserver.h"
#include "mydb.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
        QCoreApplication::quit();
    } else {
        qDebug() << "server is started";
    }
	
    SingletonMyDB::getInstance();
}

void MyTcpServer::slotNewConnection(){

    QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    clients.push_back(mTcpSocket);

    connect(mTcpSocket,
            &QTcpSocket::readyRead,
            this,
            [=]() {
                auto it = std::find(clients.begin(), clients.end(), mTcpSocket);
                this->slotServerRead(*it);
            } );
    connect(mTcpSocket,
            &QTcpSocket::disconnected,
            this,
            [=]() {
                auto it = std::find(clients.begin(), clients.end(), mTcpSocket);
                this->slotClientDisconnected(*it);
            } );
}

void MyTcpServer::slotServerRead(QTcpSocket* sock){
    QString res = "";

    if(sock->bytesAvailable()>0)
    {
        QByteArray array = sock->readAll();
        qDebug()<<array<<"\n";
        array.chop(2);
        res.append(array);
    }

    /*while(sock->bytesAvailable()>0)
    {
        QByteArray array = sock->readAll();
        qDebug()<<array<<"\n";
        if(array=="\x01")
        {
            sock->write(res.toUtf8());
            res = "";
        }
        else
        {
            res.append(array);
        }
    }*/

    res = parsing(res);


    res.append("\r\n");
    sock->write(res.toUtf8());

}

void MyTcpServer::slotClientDisconnected(QTcpSocket* sock){
    sock->close();
    clients.erase(std::find(clients.begin(), clients.end(), sock));
}
