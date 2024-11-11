#include "singletonclient.h"
#include <QPushButton>
#include <QTimer>
#include <QThread>
//#include "functionsforclient.h"



QStringList SingletonClient::getLatestServerAnswer() const
{
    return latestServerAnswer;
}

QString SingletonClient::getLogin() const
{
    return login;
}

void SingletonClient::MainwindowForm()
{
    //auto mainform = new MainWindow();
    //mainform->setAttribute(Qt::WA_DeleteOnClose);
    //mainform->show();
}

void SingletonClient::sendToServer(QStringList info)
{
    QString req = QString(info.join("&") + "\r\n");
    qDebug() << req;
    socket->write(req.toUtf8());
}

void SingletonClient::closeConnection()
{
    this->socket->abort();
}

void SingletonClient::tryConnection(QString input)
{
    this->socket->abort();
    //QString ipAdd = form->getIPAddressInput();
    qDebug() << "trying connection...(" + input + ")";

    QStringList params;

    params = input.split(":");

    this->socket->connectToHost(params.at(0), params.at(1).toInt());
}

void SingletonClient::onReadyRead() {
    // Read the response from the server
    QByteArray response = socket->readAll();
    response.chop(2);
    qDebug() << "Received from server:" << response;

    latestServerAnswer = parsing(response);
    //qDebug() << latestServerAnswer.at(0);
    if(latestServerAnswer.at(0) == "reg")
    {
        if(latestServerAnswer.at(1) == "+")
            login = latestServerAnswer.at(2);
        emit RegResp();
    }
    else if(latestServerAnswer.at(0) == "auth")
    {
        if(latestServerAnswer.at(1) == "+")
            login = latestServerAnswer.at(2);
        emit AuthResp();
    }
    else if(latestServerAnswer.at(0) == "check" || latestServerAnswer.at(0) == "stat")
        emit StatOrCheckResp();
}
void SingletonClient::onConnected()
{
    qDebug() << "connected!";

    /*
    QString temp = socket->peerAddress().toString();
    conn_address = temp;

    temp = QString::number(socket->peerPort());
    conn_port = temp;
    */

    emit connSignal();
}

void SingletonClient::onDisconnected() {
    qDebug() << "Disconnected from server.";
    login = "";
    socket->close();
}

void SingletonClient::onError()
{
    qDebug() << "Error";
    emit connErrorSignal();
    //mainform->ipform_displayErrorMessage();
}

SingletonClient* SingletonClient::p_instance;
SingletonDestroyerClient SingletonClient::destroyer;
