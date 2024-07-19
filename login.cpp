#include "login.h"
#include "ui_login.h" // This is the generated header file

#include <QMessageBox>

LoginForm::LoginForm(QWidget* parent)
    : QWidget(parent), ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    // Connect the login button's clicked signal to the appropriate slot
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &LoginForm::on_pushButtonLogin_clicked);
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
