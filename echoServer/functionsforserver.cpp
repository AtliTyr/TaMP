#include "functionsforserver.h"
#include <QDebug>

QByteArray parsing(QString data_from_client)
{
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();

    data_from_client_list.pop_front();

    try
    {
        if(nameOfFunc == "auth")
        {
            if(data_from_client_list.length() < 2)
                throw QString("not enough arguments!");
            return auth(data_from_client_list);
        }
        else if(nameOfFunc == "reg")
        {
            if(data_from_client_list.length() < 3)
                throw QString("not enough arguments!");
            return reg(data_from_client_list);
        }
        else if(nameOfFunc == "stat")
        {
            if(data_from_client_list.length() < 1)
                throw QString("not enough arguments!");
            return lookmystat(data_from_client_list);
        }
        else if(nameOfFunc == "check")
        {
            if(data_from_client_list.length() < 3)
                throw QString("not enough arguments!");
            return check(data_from_client_list);
        }
        else
        {
            throw QString("invalid command!");
        }
    } catch(QString& exp)
    {
        return exp.toUtf8();
    }

}

QByteArray auth(QStringList data_from_client_list)
{
    if(SingletonMyDB::getInstance()->Auth(data_from_client_list))
        return QString("auth+&"+data_from_client_list.at(0)).toUtf8();

    return QString("auth-").toUtf8();
}

QByteArray reg(QStringList data_from_client_list)
{
    if(SingletonMyDB::getInstance()->Register(data_from_client_list))
        return QString("reg+&" + data_from_client_list.at(0)).toUtf8();

    return QString("reg-").toUtf8();
}

QByteArray check(QStringList data_from_client_list)
{
    if(SingletonMyDB::getInstance()->Check(data_from_client_list))
        return QString("check+").toUtf8();

    return QString("check-").toUtf8();
}

QByteArray lookmystat(QStringList data_from_client_list)
{
    QStringList stats = SingletonMyDB::getInstance()->Statistics(data_from_client_list);
    return QString("stat&" + stats.join("&")).toUtf8();

    return QString("stat-").toUtf8();
}
