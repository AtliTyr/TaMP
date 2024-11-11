/********************************************************************************
** Form generated from reading UI file 'registrationorauthorization.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONORAUTHORIZATION_H
#define UI_REGISTRATIONORAUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationOrAuthorization
{
public:
    QWidget *centralwidget;
    QRadioButton *HaveAccount;
    QGroupBox *RegBox;
    QPushButton *Reg;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *RegLoginL;
    QLineEdit *RegPasswordL;
    QLineEdit *RegEmailL;
    QLabel *RegPassword;
    QLabel *RegEmail;
    QLabel *RegLogin;
    QGroupBox *AuthBox;
    QLabel *AuthPassword;
    QLabel *AuthLogin;
    QPushButton *Auth;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *AuthLoginL;
    QLineEdit *AuthPasswordL;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistrationOrAuthorization)
    {
        if (RegistrationOrAuthorization->objectName().isEmpty())
            RegistrationOrAuthorization->setObjectName("RegistrationOrAuthorization");
        RegistrationOrAuthorization->setEnabled(true);
        RegistrationOrAuthorization->resize(800, 343);
        centralwidget = new QWidget(RegistrationOrAuthorization);
        centralwidget->setObjectName("centralwidget");
        HaveAccount = new QRadioButton(centralwidget);
        HaveAccount->setObjectName("HaveAccount");
        HaveAccount->setGeometry(QRect(300, 10, 161, 24));
        HaveAccount->setChecked(true);
        RegBox = new QGroupBox(centralwidget);
        RegBox->setObjectName("RegBox");
        RegBox->setGeometry(QRect(400, 50, 331, 241));
        Reg = new QPushButton(RegBox);
        Reg->setObjectName("Reg");
        Reg->setGeometry(QRect(100, 140, 211, 41));
        verticalLayoutWidget = new QWidget(RegBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 20, 211, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RegLoginL = new QLineEdit(verticalLayoutWidget);
        RegLoginL->setObjectName("RegLoginL");

        verticalLayout->addWidget(RegLoginL);

        RegPasswordL = new QLineEdit(verticalLayoutWidget);
        RegPasswordL->setObjectName("RegPasswordL");

        verticalLayout->addWidget(RegPasswordL);

        RegEmailL = new QLineEdit(verticalLayoutWidget);
        RegEmailL->setObjectName("RegEmailL");

        verticalLayout->addWidget(RegEmailL);

        RegPassword = new QLabel(RegBox);
        RegPassword->setObjectName("RegPassword");
        RegPassword->setGeometry(QRect(10, 70, 63, 20));
        RegEmail = new QLabel(RegBox);
        RegEmail->setObjectName("RegEmail");
        RegEmail->setGeometry(QRect(10, 110, 63, 20));
        RegLogin = new QLabel(RegBox);
        RegLogin->setObjectName("RegLogin");
        RegLogin->setGeometry(QRect(10, 30, 63, 20));
        AuthBox = new QGroupBox(centralwidget);
        AuthBox->setObjectName("AuthBox");
        AuthBox->setGeometry(QRect(60, 50, 301, 161));
        AuthPassword = new QLabel(AuthBox);
        AuthPassword->setObjectName("AuthPassword");
        AuthPassword->setGeometry(QRect(10, 80, 63, 20));
        AuthLogin = new QLabel(AuthBox);
        AuthLogin->setObjectName("AuthLogin");
        AuthLogin->setGeometry(QRect(10, 30, 63, 20));
        Auth = new QPushButton(AuthBox);
        Auth->setObjectName("Auth");
        Auth->setGeometry(QRect(80, 110, 211, 41));
        verticalLayoutWidget_2 = new QWidget(AuthBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(80, 20, 209, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AuthLoginL = new QLineEdit(verticalLayoutWidget_2);
        AuthLoginL->setObjectName("AuthLoginL");

        verticalLayout_2->addWidget(AuthLoginL);

        AuthPasswordL = new QLineEdit(verticalLayoutWidget_2);
        AuthPasswordL->setObjectName("AuthPasswordL");

        verticalLayout_2->addWidget(AuthPasswordL);

        RegistrationOrAuthorization->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegistrationOrAuthorization);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        RegistrationOrAuthorization->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistrationOrAuthorization);
        statusbar->setObjectName("statusbar");
        RegistrationOrAuthorization->setStatusBar(statusbar);

        retranslateUi(RegistrationOrAuthorization);

        QMetaObject::connectSlotsByName(RegistrationOrAuthorization);
    } // setupUi

    void retranslateUi(QMainWindow *RegistrationOrAuthorization)
    {
        RegistrationOrAuthorization->setWindowTitle(QCoreApplication::translate("RegistrationOrAuthorization", "MainWindow", nullptr));
        HaveAccount->setText(QCoreApplication::translate("RegistrationOrAuthorization", "\320\243 \320\262\320\260\321\201 \320\265\321\201\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202?", nullptr));
        RegBox->setTitle(QString());
        Reg->setText(QCoreApplication::translate("RegistrationOrAuthorization", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        RegPassword->setText(QCoreApplication::translate("RegistrationOrAuthorization", "Password", nullptr));
        RegEmail->setText(QCoreApplication::translate("RegistrationOrAuthorization", "Email", nullptr));
        RegLogin->setText(QCoreApplication::translate("RegistrationOrAuthorization", "Login", nullptr));
        AuthBox->setTitle(QString());
        AuthPassword->setText(QCoreApplication::translate("RegistrationOrAuthorization", "Password", nullptr));
        AuthLogin->setText(QCoreApplication::translate("RegistrationOrAuthorization", "Login", nullptr));
        Auth->setText(QCoreApplication::translate("RegistrationOrAuthorization", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationOrAuthorization: public Ui_RegistrationOrAuthorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONORAUTHORIZATION_H
