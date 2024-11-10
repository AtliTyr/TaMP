#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QByteArray>
#include <QString>
#include <QStringList>
#include "mydb.h"

QByteArray parsing(QString);
QByteArray auth(QStringList);
QByteArray reg(QStringList);
QByteArray lookmystat(QStringList);
QByteArray lookallstat(QStringList);
QByteArray check(QStringList);


#endif // FUNCTIONSFORSERVER_H
