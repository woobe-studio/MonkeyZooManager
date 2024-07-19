#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

LoginForm::LoginForm(QWidget* parent)
    : QWidget(parent), ui(new Ui::LoginForm)
{
    ui->setupUi(this);

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // Perform login logic here
    if (username == "admin" && password == "password") {
        QMessageBox::information(this, "Login", "Login successful!");
    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}
