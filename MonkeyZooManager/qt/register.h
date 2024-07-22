#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterForm; }
QT_END_NAMESPACE

class RegisterForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget* parent = nullptr);
    ~RegisterForm();

signals:
    void RegisterSuccessful();
    void goBack();

private slots:
    void on_pushButtonGoBack_clicked();
    void on_pushButtonRegister_clicked();
    bool CheckTakenData(const std::string& login, const std::string& password);

private:
    Ui::RegisterForm* ui;
};

#endif // REGISTERFORM_H
