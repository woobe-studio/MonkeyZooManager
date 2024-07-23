#ifndef AREAMODIFY_H
#define AREAMODIFY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AreaModify; }
QT_END_NAMESPACE

class AreaModify : public QMainWindow
{
    Q_OBJECT

public:
    explicit AreaModify(QWidget* parent = nullptr);
    ~AreaModify();

signals:
    void goBack();

private slots:
    void on_DeleteButton_clicked();
    void on_GoTo_clicked();
    void on_GoBack_clicked();

private:
    Ui::AreaModify* ui;
};

#endif // AREAMODIFY_H
