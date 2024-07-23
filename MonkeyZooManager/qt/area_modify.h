#ifndef AREAMODIFY_H
#define AREAMODIFY_H

#include <QMainWindow>

#include "../src/monkey.hpp"

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
    void on_TypeComboBox_currentIndexChanged(const QString& text);

private:
    Ui::AreaModify* ui;
    void settingValues(Monkey::Zoo* zoo);
};

#endif // AREAMODIFY_H
