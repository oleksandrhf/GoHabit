#ifndef DROPMENU_H
#define DROPMENU_H

#include <QWidget>

namespace Ui {
class DropMenu;
}

class DropMenu : public QWidget
{
    Q_OBJECT

public:
    explicit DropMenu(QWidget *parent = nullptr);
    ~DropMenu();

private:
    Ui::DropMenu *ui;
};

#endif // DROPMENU_H
