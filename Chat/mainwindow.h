#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inputip_form.h"

#include <QFormLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "singletonclient.h"
#include "functionsforclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void turnOffChatbox();
    void turnOnChatbox();
    void clearChatbox();

    void successfulConnection();
private slots:
    void on_ConnectToChat_triggered();

    void on_stat_clicked();

    void on_check_clicked();

    void RoA();

    void on_LeaveChat_triggered();

    void updateChatbox();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
