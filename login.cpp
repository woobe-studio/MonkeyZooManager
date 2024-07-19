#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QTimer>

#include "../src/monkey.hpp"

LoginForm::LoginForm(QWidget* parent)
    : QWidget(parent), ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    connect(this, &LoginForm::loginSuccessful, this, &LoginForm::handleLoginSuccessful);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (CheckTakenData(username.toStdString(), password.toStdString())) {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Login", "Login successful!", QMessageBox::Ok, this);

        connect(msgBox, &QMessageBox::buttonClicked, [this, msgBox](QAbstractButton*) {
            emit loginSuccessful();
            msgBox->deleteLater();
            });

        msgBox->exec();
    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}

void LoginForm::handleLoginSuccessful()
{
    this->close();
}

bool LoginForm::CheckTakenData(const std::string& login, const std::string& password)
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    return (bool)authorizationDaemon->login(login, password);
}