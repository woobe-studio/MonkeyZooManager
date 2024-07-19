#include "login.h"
#include <QVBoxLayout>
#include <QMessageBox>

LoginForm::LoginForm(QWidget* parent)
    : QWidget(parent), ui(nullptr)
{
    // Initialize widgets
    labelTitle = new QLabel("Login", this);
    labelLogo = new QLabel(this);
    lineEditUsername = new QLineEdit(this);
    lineEditPassword = new QLineEdit(this);
    pushButtonLogin = new QPushButton("Login", this);

    // Set up the layout (basic example, adjust as needed)
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(labelLogo);
    layout->addWidget(labelTitle);
    layout->addWidget(lineEditUsername);
    layout->addWidget(lineEditPassword);
    layout->addWidget(pushButtonLogin);
    setLayout(layout);

    // Set properties for widgets
    lineEditUsername->setPlaceholderText("Username");
    lineEditPassword->setPlaceholderText("Password");
    lineEditPassword->setEchoMode(QLineEdit::Password);

    // Connect the login button's clicked signal to the appropriate slot
    connect(pushButtonLogin, &QPushButton::clicked, this, &LoginForm::on_pushButtonLogin_clicked);
}

LoginForm::~LoginForm()
{
    // No need to delete UI elements, as Qt handles it
}

void LoginForm::on_pushButtonLogin_clicked()
{
    QString username = lineEditUsername->text();
    QString password = lineEditPassword->text();

    // Perform login logic here
    if (username == "admin" && password == "password") {
        QMessageBox::information(this, "Login", "Login successful!");
    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}
