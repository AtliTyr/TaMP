#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "registrationorauthorization.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ChatBox->setVisible(false);

    connect(SingletonClient::getInstance(),
            &SingletonClient::StatOrCheckResp,
            this,
            &updateChatbox);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ConnectToChat_triggered()
{
    //ui->ConnectToChat->setEnabled(false);
    //ipform->tryClose();
    ui->ConnectToChat->setEnabled(true);
    ui->LeaveChat->setEnabled(false);

    auto ipform = new InputIP_form();
    ipform->setAttribute(Qt::WA_DeleteOnClose);
    ipform->show();

    connect(ipform,
            &InputIP_form::connectionEstablished,
            this,
            &MainWindow::RoA);

    /*connect(ipform, &InputIP_form::applying, this,
            [=](){
                this->ipApplied();
            });
    */
    /*connect(SingletonClient::getInstance(),
            &SingletonClient::connSignal,
            this,
            [=](){
                this->ipform->displayCongratulationMessage();
            });
    connect(SingletonClient::getInstance(),
            &SingletonClient::connErrorSignal,
            this,
            [=](){this->ipform->displayErrorMessage();});

    connect(ipform, &InputIP_form::connectionEstablished,
            this, [=](){this->RoA();});
    */
}

void MainWindow::on_stat_clicked()
{
    auto log = SingletonClient::getInstance()->getLogin();
    QStringList req;
    req.push_back("stat");
    req.push_back(log);

    SingletonClient::getInstance()->sendToServer(req);
}

void MainWindow::RoA()
{
    //ui->LeaveChat->setEnabled(true);
    qDebug() << "call";
    auto roaform = new RegistrationOrAuthorization();
    roaform->setAttribute(Qt::WA_DeleteOnClose);
    roaform->show();

    connect(roaform,
            &RegistrationOrAuthorization::success,
            this,
            [=]() {
                this->ui->ConnectToChat->setEnabled(false);
                this->ui->LeaveChat->setEnabled(true);
                this->turnOnChatbox();
                }
            );
}

void MainWindow::on_LeaveChat_triggered()
{
    clearChatbox();
    turnOffChatbox();

    SingletonClient::getInstance()->closeConnection();

    ui->ConnectToChat->setEnabled(true);
    ui->LeaveChat->setEnabled(false);
}
void MainWindow::on_check_clicked()
{
    auto requestArgs = new QWidget();

    auto main_layout = new QFormLayout(requestArgs);
    requestArgs->setLayout(main_layout);

    auto horiz_label_layout = new QHBoxLayout();
    main_layout->setLayout(0, QFormLayout::LabelRole, horiz_label_layout);

    auto vert_variant_layout = new QVBoxLayout();
    auto variantLabel = new QLabel(requestArgs);
    variantLabel->setText("Вариант");
    auto variantEdit = new QLineEdit(requestArgs);
    vert_variant_layout->addWidget(variantLabel);
    vert_variant_layout->addWidget(variantEdit);

    auto vert_task_num_layout = new QVBoxLayout();
    auto task_numberLabel = new QLabel(requestArgs);
    task_numberLabel->setText("Номер задачи");
    auto task_numberEdit = new QLineEdit(requestArgs);
    vert_task_num_layout->addWidget(task_numberLabel);
    vert_task_num_layout->addWidget(task_numberEdit);

    auto vert_answer_layout = new QVBoxLayout();
    auto answerLabel = new QLabel(requestArgs);
    answerLabel->setText("Ответ");
    auto answerEdit = new QLineEdit(requestArgs);
    vert_answer_layout->addWidget(answerLabel);
    vert_answer_layout->addWidget(answerEdit);

    horiz_label_layout->addLayout(vert_task_num_layout, 1);
    horiz_label_layout->addLayout(vert_variant_layout, 1);
    horiz_label_layout->addLayout(vert_answer_layout, 1);

    auto checkButton = new QPushButton(requestArgs);
    checkButton->setText("Проверить");

    main_layout->addRow(checkButton);

    connect(checkButton,
            &QPushButton::clicked,
            requestArgs,
            [=]() {
                QString serverRequest = QString("check&" +
                                                task_numberEdit->text() +
                                                "&" +
                                                variantEdit->text() +
                                                "&" +
                                                answerEdit->text()
                                                );

                SingletonClient::getInstance()->sendToServer(serverRequest.split("&"));

                ui->textArea->setText(ui->
                                      textArea->
                                      toPlainText().append(
                                      QString(SingletonClient::getInstance()->getLogin() +
                                              ": " +
                                              serverRequest.append("\n") ) ));
                requestArgs->close();
            }
    );

    requestArgs->setAttribute(Qt::WA_DeleteOnClose);
    requestArgs->show();
}

void MainWindow::updateChatbox()
{
    ui->textArea->setText(ui->textArea->toPlainText().
        append("server: " +
                SingletonClient::getInstance()->getLatestServerAnswer().
                                                                          join("&").
                                                                          append("\n")));
}

void MainWindow::turnOffChatbox()
{
    ui->ChatBox->setVisible(false);
}

void MainWindow::turnOnChatbox()
{
    ui->ChatBox->setVisible(true);
}

void MainWindow::clearChatbox()
{
    ui->textArea->clear();
}

