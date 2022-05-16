#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
signals:
    void menuTodayButton();
private slots:

    void on_menuToday_clicked();

private:
    Ui::menu *ui;






};

#endif // MENU_H
