#include "addhabit.h"
#include "ui_addhabit.h"
#include "dataset.h"


AddHabit::AddHabit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabit)
{
    connect(&mainW, SIGNAL(butt_clicked()),
            this, SLOT(OpenWindow()));
    ui->setupUi(this);
}

AddHabit::~AddHabit()
{
    delete ui;
}

void AddHabit::OpenWindow()
{
    this->show();
    mainW.hide();
}




bool AddHabit::connectDB()   // підключення бази даних до проекту
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

void AddHabit::addHabit()
{
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;
    rec = query.record();
    query.exec("SELECT COUNT(*) "
               "FROM User_habits;");
 //   query.next();
    rec = query.record();
    habit_counter = rec.value(0).toInt();
    habit_counter++;
    query.exec("SELECT COUNT(*) "
               "FROM Users;");


                rec = query.record();
    str_t               =   "INSERT INTO User_habits(id_user_habit, id_user, id_habit)"
                            "VALUES(%1, %2, '%3');";
    query.exec(str_t .arg(habit_counter)
               .arg(5)     //додавання нового кристувача в базу
               .arg(5));

  //  ui_Reg.hide();
  //  ui_Auth.show();
}
