#ifndef INPUTIP_FORM_H
#define INPUTIP_FORM_H

#include <QMainWindow>
#include <QPushButton>
#include "singletonclient.h"

namespace Ui {
class InputIP_form;
}

class InputIP_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputIP_form(QWidget *parent = nullptr);
    ~InputIP_form();
    QString getIPAddressInput() const;
    void displayErrorMessage();
    void displayCongratulationMessage();

private slots:
    void on_closeIPform_clicked();
    void on_ApplyIPAddress_clicked();

private:
    Ui::InputIP_form *ui;
signals:
    void applying();
    void connectionEstablished();
};

#endif // INPUTIP_FORM_H
