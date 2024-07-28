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
    ui->lineEditUsername->setText("");
    ui->lineEditPassword->setText("");
    ui->lineEditConfirmPassword->setText("");
    emit goBack();
}

void RegisterForm::on_pushButtonRegister_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString second_password = ui->lineEditConfirmPassword->text();

    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    // Validate username and password
    if (authorizationDaemon->doesUsernameExist(username.toStdString())) {
        QMessageBox::warning(this, "Register", "This username already exists.");
        return;
    }

    if (!isValidUsername(username)) {
        QMessageBox::warning(this, "Register", "Username does not meet requirements.");
        return;
    }

    if (!isValidPassword(password)) {
        QMessageBox::warning(this, "Register", "Password does not meet requirements.");
        return;
    }

    if (password != second_password) {
        QMessageBox::warning(this, "Register", "Passwords do not match.");
        return;
    }

    Monkey::User* usr = new Monkey::User;
    usr->setUsername(username.toStdString());
    usr->setPassword(password.toStdString());
    Monkey::Zoo* zoo = new Monkey::Zoo;
    zoo->setZooName("Local Zoo");
    usr->setZoo(zoo);
    authorizationDaemon->addUser(usr);
    Monkey::SerializationDaemon* serDeamon = Monkey::SerializationDaemon::getInstance();
    serDeamon->addZoo(zoo);
    serDeamon->save();
    QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Register", "Register successful!", QMessageBox::Ok, this);
    ui->lineEditUsername->setText("");
    ui->lineEditPassword->setText("");
    ui->lineEditConfirmPassword->setText("");

    msgBox->exec();
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
