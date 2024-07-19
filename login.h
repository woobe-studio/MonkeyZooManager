#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginForm; }
QT_END_NAMESPACE

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget* parent = nullptr);
    ~LoginForm();

signals:
    void loginSuccessful();

private slots:
    void on_pushButtonLogin_clicked();
    void handleLoginSuccessful();

private:
    Ui::LoginForm* ui;
};

#endif // LOGIN_H
