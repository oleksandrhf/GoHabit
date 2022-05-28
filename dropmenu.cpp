#include "dropmenu.h"
#include "ui_dropmenu.h"

DropMenu::DropMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropMenu)
{
    ui->setupUi(this);
}

DropMenu::~DropMenu()
{
    delete ui;
}
