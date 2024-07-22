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

    // Validate username and password
    if (!isValidUsername(username)) {
        QMessageBox::warning(this, "Register", "Username does not meet requirements.");
        return;
    }

    if (!isValidPassword(password)) {
        QMessageBox::warning(this, "Register", "Password does not meet requirements.");
        return;
    }

    if (CheckTakenData(username.toStdString(), password.toStdString())) {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Register", "Register successful!", QMessageBox::Ok, this);

        connect(msgBox, &QMessageBox::buttonClicked, [this, msgBox](QAbstractButton*) {
            ui->lineEditUsername->setText("");
            ui->lineEditPassword->setText("");
            emit RegisterSuccessful();
            msgBox->deleteLater();
            });

        msgBox->exec();
    }
    else {
        QMessageBox::warning(this, "Register", "Invalid username or password.");
    }
}

bool RegisterForm::isValidUsername(const QString& username)
{
    // Example validation: username must be between 3 and 15 characters
    // You can add more validation rules here
    return !username.isEmpty() && username.length() >= 3 && username.length() <= 15;
}

bool RegisterForm::isValidPassword(const QString& password)
{
    // Password must be at least 6 characters long
    if (password.length() < 6)
        return false;

    bool hasDigit = false;
    bool hasSymbol = false;

    // Check for at least one digit and one special symbol
    for (const QChar& ch : password) {
        if (ch.isDigit()) {
            hasDigit = true;
        }
        else if (!ch.isLetterOrNumber()) {  // This checks for special characters
            hasSymbol = true;
        }

        // Early exit if both conditions are met
        if (hasDigit && hasSymbol) {
            return true;
        }
    }

    return false;
}

bool RegisterForm::CheckTakenData(const std::string& login, const std::string& password)
{
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::User* usr = new Monkey::User;
    usr->setUsername(login);
    usr->setPassword(password);
    authorizationDaemon->addUser(usr);
    return (bool)authorizationDaemon->login(login, password);
}