#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

namespace Ui {
    class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget* parent = nullptr);
    ~LoginForm();

private slots:
    void on_pushButtonLogin_clicked();

private:
    Ui::LoginForm* ui;
    QLabel* labelTitle;
    QLabel* labelLogo;
    QLineEdit* lineEditUsername;
    QLineEdit* lineEditPassword;
    QPushButton* pushButtonLogin;
};

#endif // LOGIN_H
