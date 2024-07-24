#ifndef SPACEMODIFY_H
#define SPACEMODIFY_H

#include <QMainWindow>

#include "../src/monkey.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class SpaceModify; }
QT_END_NAMESPACE

class SpaceModify : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpaceModify(QWidget* parent = nullptr);
    ~SpaceModify();
    void custom_init();
    int currentAreaIndex;
    int currentMonkeyIndex;
    std::string currentAreaImage;

signals:
    void goBack();

private slots:
    void on_DeleteButton_clicked();
    void on_EditButton_clicked();
    void on_CreateButton_clicked();
    void on_GoBack_clicked();
    void on_TypeComboBox_currentIndexChanged(const QString& text);
    void on_RarityComboBox_currentIndexChanged(const QString& text);

private:
    Ui::SpaceModify* ui;
    void settingValues(Monkey::Zoo* zoo);
    void setAreaImage(const std::string& icon_name);
};

#endif // SPACEMODIFY_H
