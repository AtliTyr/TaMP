#include "functionsforclient.h"

QStringList parsing(QString msg)
{
    QStringList comp = msg.split("&");
    if(comp.at(0) == "Hello, World!!! I am echo server!")
        return QStringList{"Hello, World!!! I am echo server!"};

    QString arg = comp.at(0);

    if(arg.at(arg.length() - 1) == QString("+"))
    {
        comp.insert(1, QString('+'));
        arg.truncate(arg.length() - 1);
        comp.removeAt(0);
        comp.push_front(arg);
    }
    else if(arg.at(arg.length() - 1) == QString("-"))
    {
        comp.insert(1, QString('-'));
        arg.truncate(arg.length() - 1);
        comp.removeAt(0);
        comp.push_front(arg);
    }

    /*switch(char(arg.at(arg.length() - 1)))
    {
    case '+':
        comp.insert(1, '+');
        arg.truncate(arg.length() - 1);
        break;
    case '-':
        comp.insert(1, '-');
        arg.truncate(arg.length() - 1);
        break;
    default:
        break;
    }*/

    return comp;
}

bool isValidEmail(const QString &email)
{
    // Регулярное выражение для проверки email
    QRegularExpression emailPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    // Проверяем, соответствует ли email регулярному выражению
    return emailPattern.match(email).hasMatch();
}

bool isValidLogin(const QString &login)
{
    QRegularExpression loginPattern(R"(^[a-zA-Z0-9_-]{3,16}$)");

    return loginPattern.match(login).hasMatch();
}

bool validateIpAndPort(const QString &ipPort)
{
    QRegularExpression ipRegex(R"((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.("
                                 "25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.("
                                 "25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.("
                                 "25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?))");

    // Разделяем строку на IP и порт
    QStringList parts = ipPort.split(':');
    if (parts.size() != 2) {
        return false;
    }

    QString ip = parts[0];
    bool portConversionOk;
    int port = parts[1].toInt(&portConversionOk);

    // Проверка диапазона порта (от 0 до 65535)
    bool isPortValid = portConversionOk && (port >= 0 && port <= 65535);

    // Проверка IP-адреса
    bool isIpValid = ipRegex.match(ip).hasMatch();

    if (!isIpValid) {
        return false;
    }

    if (!isPortValid) {
        return false;
    }

    return true;
}
