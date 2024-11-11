/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ConnectToChat;
    QAction *LeaveChat;
    QWidget *centralwidget;
    QGroupBox *ChatBox;
    QPushButton *stat;
    QPushButton *check;
    QTextEdit *textArea;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(813, 614);
        ConnectToChat = new QAction(MainWindow);
        ConnectToChat->setObjectName("ConnectToChat");
        LeaveChat = new QAction(MainWindow);
        LeaveChat->setObjectName("LeaveChat");
        LeaveChat->setEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ChatBox = new QGroupBox(centralwidget);
        ChatBox->setObjectName("ChatBox");
        ChatBox->setGeometry(QRect(20, 10, 771, 541));
        stat = new QPushButton(ChatBox);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(20, 40, 151, 41));
        check = new QPushButton(ChatBox);
        check->setObjectName("check");
        check->setGeometry(QRect(300, 40, 151, 41));
        textArea = new QTextEdit(ChatBox);
        textArea->setObjectName("textArea");
        textArea->setGeometry(QRect(20, 100, 431, 401));
        textArea->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 813, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(ConnectToChat);
        menu->addAction(LeaveChat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Chat", nullptr));
        ConnectToChat->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\272 \321\207\320\260\321\202\321\203", nullptr));
        LeaveChat->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \321\207\320\260\321\202\320\260", nullptr));
        ChatBox->setTitle(QString());
        stat->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\321\217\320\275\321\203\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        check->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
