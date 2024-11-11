#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QPair>
#include <QRegularExpression>

#include "registrationorauthorization.h"

QStringList parsing(QString msg);

bool isValidEmail(const QString &email);

bool isValidLogin(const QString &login);

bool validateIpAndPort(const QString& ipPort);

#endif // FUNCTIONSFORCLIENT_H
