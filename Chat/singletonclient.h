#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>
#include <QMainWindow>
#include <QApplication>

#include "inputip_form.h"
//#include "registrationorauthorization.h"
#include "functionsforclient.h"
#include "mainwindow.h"

//Улучшенная реализация
class SingletonClient;

class SingletonDestroyerClient
{
private:
    SingletonClient * p_instance;
public:
    ~SingletonDestroyerClient() {
        delete p_instance;
    }
    void initialize(SingletonClient * p){p_instance = p;};
};

class SingletonClient: public QObject
{
    Q_OBJECT
    private:
        static SingletonClient * p_instance;
        static SingletonDestroyerClient destroyer;
        QTcpSocket* socket;
        QStringList latestServerAnswer;

        QString login;
        //QString conn_address;
        //QString conn_port;
    protected:
        SingletonClient()
        {
            this->socket = new QTcpSocket();
            connect(socket, &QTcpSocket::connected, this, &SingletonClient::onConnected);
            connect(socket, &QTcpSocket::readyRead, this, &SingletonClient::onReadyRead);
            connect(socket, &QTcpSocket::disconnected, this, &SingletonClient::onDisconnected);
            connect(socket, &QTcpSocket::errorOccurred, this, &SingletonClient::onError);

            qDebug() << "Singletone constructor..." << socket;
        }
        SingletonClient(const SingletonClient& ) = delete;
        SingletonClient& operator = (SingletonClient &) = delete;
        ~SingletonClient(){}
        friend class SingletonDestroyerClient;

        void MainwindowForm();
    public:
        static SingletonClient* getInstance()
        {
            if (!p_instance)
            {
                p_instance = new SingletonClient();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        void tryConnection(QString);
        void sendToServer(QStringList);
        void closeConnection();

        QStringList getLatestServerAnswer() const;

        QString getLogin() const;

    private slots:
        void onConnected();
        void onReadyRead();
        void onDisconnected();
        void onError();
    signals:
        void connSignal();
        void connErrorSignal();
        void RegResp();
        void AuthResp();
        void StatOrCheckResp();
};
#endif
