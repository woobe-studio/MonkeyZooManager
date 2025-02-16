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
    void custom_init();
    int currentAreaIndex;
    std::string currentAreaImage;

signals:
    void goBack();

private slots:
    void on_DeleteButton_clicked();
    void on_EditButton_clicked();
    void on_CreateButton_clicked();
    void on_GoBack_clicked();
    void on_TypeComboBox_currentIndexChanged(const QString& text);

private:
    Ui::AreaModify* ui;
    void settingValues(Monkey::Zoo* zoo);
    void setAreaImage(const std::string& icon_name);
};

#endif // AREAMODIFY_H
