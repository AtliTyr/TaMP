#ifndef REGISTRATIONORAUTHORIZATION_H
#define REGISTRATIONORAUTHORIZATION_H

#include <QMainWindow>
#include <QStringList>
#include <QMessageBox>

#include "functionsforclient.h"
#include "singletonclient.h"

namespace Ui {
class RegistrationOrAuthorization;
}

class RegistrationOrAuthorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistrationOrAuthorization(QWidget *parent = nullptr);
    ~RegistrationOrAuthorization();
    QStringList getInfo() const;
    void RegistrationFailed();
    void AuthorizationFailed();
    void RegistrationSuccessed();
    void AuthorizationSuccessed();
    void AlreadyAuthorized();

    void invalidEmail();
    void invalidLogin();

private slots:
    void on_HaveAccount_clicked();

    void on_Auth_clicked();

    void on_Reg_clicked();

signals:
    void infoSent();
    void toNextForm();
    void success();
private:
    QStringList info;
    Ui::RegistrationOrAuthorization *ui;
    bool req;

};

#endif // REGISTRATIONORAUTHORIZATION_H
