/********************************************************************************
** Form generated from reading UI file 'inputip_form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTIP_FORM_H
#define UI_INPUTIP_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputIP_form
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *IPAddressInput;
    QPushButton *ApplyIPAddress;
    QPushButton *closeIPform;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InputIP_form)
    {
        if (InputIP_form->objectName().isEmpty())
            InputIP_form->setObjectName("InputIP_form");
        InputIP_form->resize(268, 201);
        centralwidget = new QWidget(InputIP_form);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 60, 160, 85));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        IPAddressInput = new QLineEdit(verticalLayoutWidget);
        IPAddressInput->setObjectName("IPAddressInput");

        verticalLayout->addWidget(IPAddressInput);

        ApplyIPAddress = new QPushButton(verticalLayoutWidget);
        ApplyIPAddress->setObjectName("ApplyIPAddress");
        ApplyIPAddress->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(ApplyIPAddress);

        closeIPform = new QPushButton(centralwidget);
        closeIPform->setObjectName("closeIPform");
        closeIPform->setGeometry(QRect(240, 10, 20, 20));
        closeIPform->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(true);
        closeIPform->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 61, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 30, 231, 20));
        InputIP_form->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InputIP_form);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 268, 26));
        InputIP_form->setMenuBar(menubar);
        statusbar = new QStatusBar(InputIP_form);
        statusbar->setObjectName("statusbar");
        InputIP_form->setStatusBar(statusbar);

        retranslateUi(InputIP_form);

        QMetaObject::connectSlotsByName(InputIP_form);
    } // setupUi

    void retranslateUi(QMainWindow *InputIP_form)
    {
        InputIP_form->setWindowTitle(QCoreApplication::translate("InputIP_form", "MainWindow", nullptr));
        IPAddressInput->setPlaceholderText(QCoreApplication::translate("InputIP_form", "127.0.0.1:33333", nullptr));
        ApplyIPAddress->setText(QCoreApplication::translate("InputIP_form", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        closeIPform->setText(QCoreApplication::translate("InputIP_form", "X", nullptr));
        label->setText(QCoreApplication::translate("InputIP_form", "Warning!", nullptr));
        label_2->setText(QCoreApplication::translate("InputIP_form", " Leave empty for \"127.0.0.1:33333\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputIP_form: public Ui_InputIP_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTIP_FORM_H
