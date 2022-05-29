#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

menu::~menu()
{
    delete ui;
}

bool menu::connectDB()   // підключення бази даних до проекту
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./db_GoHabit.db");
    if(!db.open())
    {
        qDebug() << "Cannot open database: " << db.lastError();
        return false;
    }
    return true;
}

void menu::on_menuToday_clicked()
{
   emit menuTodayButton();
    this->hide();
}


void menu::on_pushButton_clicked()
{

    int* arrOfId;
    Singleton* s1 = Singleton::getInstance();
    arrOfId = s1->getarrOfId();
    ui->stackedWidget->setCurrentIndex(1);
    if(*arrOfId != 0)
    {
        ui->label_22->setText("1");
        ui->label_23->hide();
        ui->label_11->hide();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Achievements");
        msgBox.setText("You create First Habit!\n");
        msgBox.exec();

    }

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


void menu::on_pushButton_8_clicked()
{
    emit logged_out();
}
