#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{

    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}


void menu::on_menuToday_clicked()
{
   emit menuTodayButton();
    this->hide();
}


void menu::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu::on_backAchieve_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void menu::on_backNotificat_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void menu::on_backSettings_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void menu::on_menuButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

