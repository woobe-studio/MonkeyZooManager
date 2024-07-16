#include "login.h"
#include <QMessageBox>
#include <QPixmap> // Include QPixmap for loading the icon image

LoginForm::LoginForm(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    // Set application icon
    QPixmap pixmap(":/images/app_icon.png"); // Replace with your actual icon path
    this->setWindowIcon(QIcon(pixmap));

    // Connect the login button click signal to the slot
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

    // For demonstration purposes, let's assume valid credentials are:
    // Username: admin, Password: password
    if (username == "admin" && password == "password") {
        QMessageBox::information(this, "Login", "Login successful!");
    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password!");
    }
}
