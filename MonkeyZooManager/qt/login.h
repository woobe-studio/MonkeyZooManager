#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginForm; }
QT_END_NAMESPACE

class LoginForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget* parent = nullptr);
    ~LoginForm();

signals:
    void loginSuccessful();

private slots:
    void on_pushButtonLogin_clicked();
    bool CheckTakenData(const std::string& login, const std::string& password);

private:
    Ui::LoginForm* ui;
};

#endif // LOGIN_H
