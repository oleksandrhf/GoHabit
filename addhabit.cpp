#include "addhabit.h"
#include "ui_addhabit.h"
#include "dataset.h"




AddHabit::AddHabit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabit)
{
    connect(&c_habit, SIGNAL(back_clicked()),
            this, SLOT(on_back_clicked()));

    connect(&c_habit, SIGNAL(back_clicked()),
            this, SLOT(showHabitsInCombobox()));

    connect(&c_habit, SIGNAL(new_habit_added()),
            this, SLOT(on_habit_created()));

    ui->setupUi(this);
}

AddHabit::~AddHabit()
{
    delete ui;
}

void AddHabit::showHabitsInCombobox()
{
   ui->Add_habit_comboBox->clear();
   Singleton* s1 = Singleton::getInstance();
   connectDB();
   QSqlQuery query1;
   QSqlQuery query2;

   QSqlRecord rec1;
   QSqlRecord rec2;
   QString str_t;
   rec1 = query1.record();
   str_t = "SELECT name_habit "
           "FROM Habits"
           " WHERE id_user = 0"
           " OR id_user = ";
   str_t.append(QString::number(s1->GetThisUserId()));
   str_t.append(";");
   query1.exec(str_t);
   str_t = "SELECT COUNT(*) "
           "FROM Habits"
           " WHERE id_user = 0"
           " OR id_user = ";
   str_t.append(QString::number(s1->GetThisUserId()));
   str_t.append(";");
   query2.exec(str_t);
   query2.next();
   rec2 = query2.record();
   int max_id = query2.value(0).toInt();

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
    fillarrOfIndex();
    Singleton* s1 = Singleton::getInstance();
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;
    int i = s1->GetThisUserId();
    rec = query.record();
    query.exec("SELECT MAX(id_user_habit) "
               "FROM User_Habits;");
    query.next();
    rec = query.record();
    habit_counter = rec.value(0).toInt();
    habit_counter++;
    query.exec("SELECT COUNT(*) "
               "FROM User_Habits;");
                rec = query.record();


    str_t               =   "INSERT INTO User_Habits(id_user_habit, id_user, id_habit, progression, days, time, check_time)"
                            "VALUES(%1, %2, %3, %4, '%5', '%6', %7);";
    query.exec(str_t
               .arg(habit_counter)
               .arg(s1->GetThisUserId())
               .arg(arrayOfIndex[ui->Add_habit_comboBox->currentIndex() - 1])
               .arg(0)
               .arg(det_days())
               .arg(ui->timeEdit->time().toString())
               .arg(0));

}


void AddHabit::fillarrOfIndex()
{
    Singleton* s1 = Singleton::getInstance();
    QSqlQuery query;
    QString str_t;
    int t;
    for(int i = 0; i < 15 ;i++)
    {
        arrayOfIndex[i] = 0;
    }
    str_t = "SELECT id_habit "
            "FROM Habits "
            "WHERE id_user = ";
    str_t.append(QString::number(s1->GetThisUserId()));
    str_t.append(" OR id_user = 0");
    str_t.append(";");
    query.exec(str_t);
    for (int i = 0; i < 15 ;i++ )
    {
        query.next();
        t = query.value(0).toInt();
        arrayOfIndex[i] = t;
    }
}

int AddHabit::getIdOfCombobox(int i)
{
    return 0;
}


void AddHabit::on_habit_created()
{

    this->show();
    ui->Add_habit_comboBox->clear();
    showHabitsInCombobox();
    fillarrOfIndex();
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



void AddHabit::on_pushButton_4_clicked()
{
    emit backed();
}


void AddHabit::on_add_button_clicked()
{
    connectDB();
    addHabit();
    emit backed();
}


void AddHabit::on_pushButton_2_clicked()
{
    emit backed();
}


void AddHabit::on_Add_habit_button_clicked()
{
    connectDB();
    addHabit();
    emit backed();
}

