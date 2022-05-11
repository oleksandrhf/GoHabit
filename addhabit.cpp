#include "addhabit.h"
#include "ui_addhabit.h"
#include "dataset.h"




AddHabit::AddHabit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabit)
{
    connect(&c_habit, SIGNAL(back_clicked()),
            this, SLOT(on_back_clicked()));

    connect(&c_habit, SIGNAL(new_habit_added()),
            this, SLOT(on_habit_created())); //підключення до кнопок

    ui->setupUi(this);
    showHabitsInCombobox();
}

AddHabit::~AddHabit()
{
    delete ui;
}

void AddHabit::showHabitsInCombobox()
{
   connectDB();
   QSqlQuery query1;
   QSqlQuery query2;

   QSqlRecord rec1;
   QSqlRecord rec2;
   QString str_t;
   rec1 = query1.record();
   query1.exec("SELECT name_habit "
              "FROM Habits;");

   query2.exec("SELECT COUNT(*) "
               "FROM Habits;");
   query2.next();
   rec2 = query2.record();
   int max_id = rec2.value(0).toInt();

   for(int i = 0; i < max_id + 1; i++)
   {
        QString habit_name = query1.value(rec1.indexOf("name_habit")).toString();
        rec1 = query1.record();
        ui->Add_habit_comboBox->addItem(habit_name);
        query1.next();
    }
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

QString AddHabit::det_days()
{
    QString s = " ";
    ui->checkBox->isChecked()   ? s.append("1"):s.append("0");
    ui->checkBox_2->isChecked() ? s.append("1"):s.append("0");
    ui->checkBox_3->isChecked() ? s.append("1"):s.append("0");
    ui->checkBox_4->isChecked() ? s.append("1"):s.append("0");
    ui->checkBox_5->isChecked() ? s.append("1"):s.append("0");
    ui->checkBox_6->isChecked() ? s.append("1"):s.append("0");
    ui->checkBox_7->isChecked() ? s.append("1"):s.append("0");
    return s;
}


void AddHabit::addHabit()
{
    Singleton* s1 = Singleton::getInstance();
    thisUserId = s1->GetThisUserId();


    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;

    rec = query.record();
    query.exec("SELECT COUNT(*) "
               "FROM User_Habits;");
    query.next();
    rec = query.record();
    habit_counter = rec.value(0).toInt();
    habit_counter++;
    query.exec("SELECT COUNT(*) "
               "FROM User_Habits;");
                rec = query.record();
    str_t               =   "INSERT INTO User_Habits(id_user_habit, id_user, id_habit, days, time)"
                            "VALUES(%1, %2, %3, '%4', '%5');";
    query.exec(str_t
               .arg(habit_counter)
               .arg(thisUserId)
               .arg(ui->Add_habit_comboBox->currentIndex() - 1)
               .arg(det_days())
               .arg(ui->timeEdit->time().toString()));
}



void AddHabit::on_habit_created()
{
    this->show();
    ui->Add_habit_comboBox->clear();
    showHabitsInCombobox();
    c_habit.hide();
}

void AddHabit::on_back_clicked()
{
    this->show();
    c_habit.hide();
}


void AddHabit::on_pushButton_clicked()
{
    c_habit.show();
    this->hide();
}





void AddHabit::on_Add_habit_button_clicked()
{
    connectDB();
    addHabit();
    emit backed();
}


void AddHabit::on_pushButton_4_clicked()
{
    emit backed();
}

