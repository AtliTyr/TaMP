#include "inputip_form.h"
#include "ui_inputip_form.h"

#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

InputIP_form::InputIP_form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InputIP_form)
{
    ui->setupUi(this);
}

InputIP_form::~InputIP_form()
{
    qDebug() << "#destr";
    delete ui;
}

QString InputIP_form::getIPAddressInput() const
{
    return ui->IPAddressInput->text();
}

void InputIP_form::on_closeIPform_clicked()
{
    this->close();
}

void InputIP_form::on_ApplyIPAddress_clicked()
{
    ui->ApplyIPAddress->setEnabled(false);

    QString temp;
    temp = ui->IPAddressInput->text();

    if(temp == "")
        temp = "127.0.0.1:33333";

    if(!validateIpAndPort(temp))
    {
        displayErrorMessage();
        return;
    }

    // Get instance and set connection
    //
    //
    // if connection - true
    // display congratulation message
    // emit signal
    // close form
    // if connection - false
    // display error message
    // keep form open
    // enable apply button
    SingletonClient::getInstance()->tryConnection(temp);

    tmp = true;
    connect(SingletonClient::getInstance(),
            &SingletonClient::connSignal,
            this,
            [=](){
                if(tmp == true)
                {
                    this->displayCongratulationMessage();
                }
                tmp = false;
            });
    connect(SingletonClient::getInstance(),
            &SingletonClient::connErrorSignal,
            this,
            [=]() {
                if(tmp == true)
                {
                    this->displayErrorMessage();
                }
                tmp = false;
            });
}

void InputIP_form::displayErrorMessage()
{
        QMessageBox* errorMsg = new QMessageBox(this);
        errorMsg->setText("ERROR!\nCHECK IF YOU ENTERED ADDRESS CORRECTLY!");
        errorMsg->setStyleSheet("color: rgb(255, 0, 0)");

        errorMsg->exec();

        ui->ApplyIPAddress->setEnabled(true);
}

void InputIP_form::displayCongratulationMessage()
{
        QMessageBox* congrMsg = new QMessageBox(this);
        congrMsg->setText("!!!!!!!!!!!CONGRATULATIONS!!!!!!!!!!!");

        congrMsg->exec();

        emit connectionEstablished();

        this->close();
}



