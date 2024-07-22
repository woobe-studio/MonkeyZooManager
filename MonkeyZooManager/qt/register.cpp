#include "register.h"
#include "ui_register.h"

#include <QMessageBox>
#include <QTimer>

#include "../src/monkey.hpp"

RegisterForm::RegisterForm(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    setMinimumSize(360, 640);
    resize(360, 640);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_pushButtonGoBack_clicked() {
    emit goBack();
}

void RegisterForm::on_pushButtonRegister_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (CheckTakenData(username.toStdString(), password.toStdString())) {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Login", "Login successful!", QMessageBox::Ok, this);

        connect(msgBox, &QMessageBox::buttonClicked, [this, msgBox](QAbstractButton*) {
            ui->lineEditUsername->setText("");
            ui->lineEditPassword->setText("");
            emit RegisterSuccessful();
            msgBox->deleteLater();
            });

        msgBox->exec();
    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}

bool RegisterForm::CheckTakenData(const std::string& login, const std::string& password)
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    return (bool)authorizationDaemon->login(login, password);
}