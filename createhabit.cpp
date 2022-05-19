#include "createhabit.h"
#include "ui_createhabit.h"
#include "dataset.h"
#include <QString>

CreateHabit::CreateHabit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateHabit)
{
    ui->setupUi(this);
}

CreateHabit::~CreateHabit()
{
    delete ui;
}

bool CreateHabit::connectDB()   // підключення бази даних до проекту
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

void CreateHabit::on_pushButton_clicked()
{
    connectDB();
    Singleton* s1 = Singleton::getInstance();
    int habit_counter;
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;
    query.exec("SELECT COUNT(*) "
               "FROM Habits;");
    query.next();
    rec = query.record();
    habit_counter = rec.value(0).toInt();
    habit_counter++;
    s1->SetHabitId(habit_counter);
    str_t               =   "INSERT INTO Habits(id_habit, name_habit, how_long, custom_habit, description)"
                            "VALUES(%1, '%2', %3, %4, '%5');";
    query.exec(str_t
               .arg(habit_counter)
               .arg(ui->lineEdit->text())     //додавання нового кристувача в базу
               .arg(ui->horizontalSlider->value())
               .arg(1)
               .arg(ui->textEdit->toPlainText()));
    emit new_habit_added();
}


void CreateHabit::on_horizontalSlider_valueChanged(int value)
{
    QString s = QString::number(ui->horizontalSlider->value());
    ui->label_2->setText("number of days - " + s);
}


void CreateHabit::on_pushButton_2_clicked()
{
    emit back_clicked();
}

