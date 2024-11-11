#include "registrationorauthorization.h"
#include "ui_registrationorauthorization.h"

RegistrationOrAuthorization::RegistrationOrAuthorization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegistrationOrAuthorization)
{
    ui->setupUi(this);

    ui->RegBox->setVisible(false);
}

RegistrationOrAuthorization::~RegistrationOrAuthorization()
{
    delete ui;
}
void RegistrationOrAuthorization::on_HaveAccount_clicked()
{
    bool ch = (ui->HaveAccount->isChecked()) ? true : false;
    ui->RegBox->setVisible(!ch);
    ui->AuthBox->setVisible(ch);
}

void RegistrationOrAuthorization::on_Auth_clicked()
{
    if(!isValidLogin(ui->AuthLoginL->text()))
    {
        invalidLogin();
        return;
    }

    if(!(SingletonClient::getInstance()->getLogin() == ""))
    {
        AlreadyAuthorized();
        this->close();
        return;
    }

    ui->Auth->setEnabled(false);

    info.clear();
    info.push_back(QString("auth"));
    info.push_back(ui->AuthLoginL->text());
    info.push_back(ui->AuthPasswordL->text());

    // Get instance , check if client is already authorized and send request to server if not
    // if client is authorized
    // display message
    // closeform
    // connect - signal from singletonclient with slot in regorauth to get resp from server
    // if reg - true
    // RegistrationSuccessed()
    // close form
    // if reg - false
    // RegistrationFailed
    // enable button reg

    tmp_a = true;

    SingletonClient::getInstance()->sendToServer(info);
    connect(SingletonClient::getInstance(),
            &SingletonClient::AuthResp,
            this,
            [=](){
                if(tmp_a == true)
                {
                    if(SingletonClient::getInstance()->getLatestServerAnswer().at(1) == "+")
                    {
                        AuthorizationSuccessed();
                        emit success();
                        this->close();
                    }
                    else
                    {
                        AuthorizationFailed();
                        ui->Auth->setEnabled(true);
                    }
                    tmp_a = false;
                }
            });
}

void RegistrationOrAuthorization::on_Reg_clicked()
{
    if(!isValidLogin(ui->RegLoginL->text()))
    {
        invalidLogin();
        return;
    }
    if(!isValidEmail(ui->RegEmailL->text()))
    {
        invalidEmail();
        return;
    }

    if(!(SingletonClient::getInstance()->getLogin() == ""))
    {
        AlreadyAuthorized();
        this->close();
        return;
    }

    ui->Reg->setEnabled(false);

    info.clear();
    info.push_back(QString("reg"));
    info.push_back(ui->RegLoginL->text());
    info.push_back(ui->RegPasswordL->text());
    info.push_back(ui->RegEmailL->text());

    // Get instance and send request to server
    // connect - signal from singletonclient with slot in regorauth to get resp from server
    // if reg - true
    // RegistrationSuccessed()
    // close form
    // if reg - false
    // RegistrationFailed
    // enable button reg
    tmp_r = true;
    SingletonClient::getInstance()->sendToServer(info);
    connect(SingletonClient::getInstance(),
            &SingletonClient::RegResp,
            this,
            [=](){
                if(tmp_r == true)
                {
                    if(SingletonClient::getInstance()->getLatestServerAnswer().at(1) == QString("+"))
                    {
                        RegistrationSuccessed();
                        emit success();
                        this->close();
                    }
                    else
                    {
                        RegistrationFailed();
                        ui->Reg->setEnabled(true);
                    }
                    tmp_r = false;
                }
            });
}

QStringList RegistrationOrAuthorization::getInfo() const
{
    return info;
}

void RegistrationOrAuthorization::RegistrationFailed()
{
        auto msg = new QMessageBox();
        msg->setAttribute(Qt::WA_DeleteOnClose);
        msg->setText("Registration failed");
        msg->exec();
}

void RegistrationOrAuthorization::AuthorizationFailed()
{
        auto msg = new QMessageBox();
        msg->setAttribute(Qt::WA_DeleteOnClose);
        msg->setText("Authorization failed");
        msg->exec();
}

void RegistrationOrAuthorization::RegistrationSuccessed()
{
        auto msg = new QMessageBox();
        msg->setAttribute(Qt::WA_DeleteOnClose);
        msg->setText("Registration successed");
        msg->exec();
}

void RegistrationOrAuthorization::AuthorizationSuccessed()
{
        auto msg = new QMessageBox();
        msg->setAttribute(Qt::WA_DeleteOnClose);
        msg->setText("Authorization successed");
        msg->exec();
}

void RegistrationOrAuthorization::AlreadyAuthorized()
{
    QMessageBox alrAuth;
    alrAuth.setText("You are already authorized!");
    alrAuth.exec();
}

void RegistrationOrAuthorization::invalidEmail()
{
    QMessageBox invEmail;
    invEmail.setText("You entered incorrect email!");
    invEmail.exec();
}

void RegistrationOrAuthorization::invalidLogin()
{
    QMessageBox invLogin;
    invLogin.setText("You entered incorrect login!");
    invLogin.exec();
}
