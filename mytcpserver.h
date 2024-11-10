#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>

/*!
 * \brief The MyTcpServer class
 *
 * Цели: \n
 * 1) Создание TCP сервера \n
 * 2) Обработка запросов на подключение \n
 * 3) Обработка текстовых запросов
 */

class MyTcpServer : public QObject
{
    Q_OBJECT
public:

    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    /*!
     * \brief slotNewConnection
     *
     * Обработка новых подключений. \n
     * 1) Срабатывает при попытке подключиться к серверу \n
     * 2) Добавляет в список открытых подключений новое соединение
     */
    void slotNewConnection();

    /*!
     * \brief slotClientDisconnected
     *
     * Обработка отключения клиента от сервера \n
     * 1) Срабатывает при откючении пользователя от сервера \n
     * 2) Стирает память о подключении из списка открытых подключений
     */
    void slotClientDisconnected(QTcpSocket*);

    /*!
     * \brief slotServerRead
     *
     * Обработка входящих сообщений \n
     * 1) Срабатывает при отправке клиентом сообщения на сервер \n
     * 2) Вызывает функцию парсинга для текста входящего запроса
     */
    void slotServerRead(QTcpSocket*);
private:
    QTcpServer * mTcpServer;
    QList<QTcpSocket*> clients;
};
#endif // MYTCPSERVER_H






