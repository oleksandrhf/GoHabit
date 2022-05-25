#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth_window.h"
#include "reg_window.h"
#include "dataset.h"
#include "timecheck.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_Main(new Ui::MainWindow)
{
    user_counter = 0;
    m_loginSuccesfull = false;

    connect(&TC , SIGNAL(unblockCheck(id_user_Habit)),
            this, SLOT(on_checkboxblocked(id_user_Habit)));


    connect(&ah, SIGNAL(backed()),
            this, SLOT(on_go_back()));

    connect(&ah, SIGNAL(backed()),
            this, SLOT(on_go_back()));

    connect(&ui_Auth, SIGNAL(login_button_clicked()),
            this, SLOT(authorizeUser()));

    connect(&ui_Auth,SIGNAL(destroyed()),
            this, SLOT(show()));

    connect(&ui_Auth,SIGNAL(register_button_clicked()),
            this,SLOT(registerWindowShow()));

    connect(&ui_Reg,SIGNAL(register_button_clicked2()),
            this,SLOT(registerUser()));

    connect(&ui_Reg,SIGNAL(destroyed()),

            &ui_Auth, SLOT(show()));
    connect(&ui_menu,SIGNAL(menuTodayButton()),
           this, SLOT(show()));


    //Сигнали на спрацьовування кнопок

    if(!connectDB())
    {
        qDebug() << "Failed to connect DB";
    }

   ui_Main->setupUi(this);
   visibleCheck();

}

void MainWindow::SetCheckTime(int id, QDateTime T)
{

    QSqlQuery query;
    QString str_t;
    str_t               =   "UPDATE User_Habits SET check_time = ";
    str_t.append(T.toString());
    str_t.append(" WHERE ");
    str_t.append("id_habit = ");
    str_t.append(QString::number(id));
    query.exec(str_t);
}

void MainWindow::authorizeUser()
{
    Singleton* s1 = Singleton::getInstance();
    m_username          = ui_Auth.getLogin();
    m_userpass          = ui_Auth.getPass();   //зчитування з форми

    QString str_t       = " SELECT * "
                          " FROM Users "
                          " WHERE name = '%1'";

    QString username    = "";

    QString login       = "";

    QString userpass    = "";

    db_input    = str_t.arg(m_username);

    QSqlQuery query;

    QSqlRecord rec;

    query.exec(db_input);
    rec = query.record();
    query.next();
    user_counter   = query.value(rec.indexOf("id_user")).toInt();
    username    = query.value(rec.indexOf("name")).toString();
    userpass    = query.value(rec.indexOf("password")).toString();
    login       = query.value(rec.indexOf("email")).toString();  //зчитування з бази



    if(m_username != username || m_userpass != userpass)         //порівняння на правильність
    {
        qDebug() << "Password missmatch" << username << " " << userpass;
        m_loginSuccesfull = false;
    }
    else
    {
        s1->SetThisUserId(user_counter);
        QString s = QString::number(user_counter);
        m_loginSuccesfull = true;
        ui_Auth.close();
        ui_Reg.close();
        this->show();
    }
}

void MainWindow::registerWindowShow()
{
    ui_Auth.hide();
    ui_Reg.show();
}

void MainWindow::registerUser()
{
    if(ui_Reg.checkPass())
    {

        QSqlQuery query;
        QSqlRecord rec;
        QString str_t;
        rec = query.record();
        query.exec("SELECT COUNT(*) "
                   "FROM Users;");
        query.next();
        rec = query.record();
        user_counter = rec.value(0).toInt();
        qDebug() << user_counter;
        m_username          = ui_Reg.getName();
        m_userpass          = ui_Reg.getPass();    //зчитування даних з форми
        m_login             = ui_Reg.getLogin();
        user_counter++;
        str_t               =   "INSERT INTO Users(id_user, name, password, email)"
                                "VALUES(%1, '%2', '%3', '%4');";
        query.exec(str_t .arg(user_counter)
                   .arg(m_username)     //додавання нового кристувача в базу
                   .arg(m_userpass)
                   .arg(m_login));

        ui_Reg.hide();
        ui_Auth.show();

    }
    else
    {
        qDebug() << "Confirm password coorectly";
    }

}


void MainWindow::display() //показ вікна авторизації при вході
{
    ui_Auth.show();
}

bool MainWindow::connectDB()   // підключення бази даних до проекту
{
    mw_db = QSqlDatabase::addDatabase("QSQLITE");
    mw_db.setDatabaseName("./db_GoHabit.db");
    if(!mw_db.open())
    {
        qDebug() << "Cannot open database: " << mw_db.lastError();
        return false;
    }
    return true;
}

void MainWindow::wipeDB() //видалення бази
{
    mw_db.removeDatabase("./db_GoHabit.db");
}



void MainWindow::on_pushButton_clicked()
{
    TimeCheck T;

    this->close();
    ah.show();
}

void MainWindow::on_go_back()
{
    this->show();
    ah.hide();
    visibleCheck();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->show();

}

void MainWindow::showAllHabits()
{
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;
    int P;
    str_t = "SELECT id_habit "
            "FROM User_Habits"
            " WHERE id_user = ";
    str_t.append(QString::number(user_counter));
    str_t.append(";");
    query.exec(str_t);
     query.next();
    P = query.value(0).toInt();

}


void MainWindow::SetVisible(bool v1, bool v2, bool v3, bool v4, bool v5)
{
    ui_Main->groupBox->setVisible(v1);
    ui_Main->groupBox_2->setVisible(v2);
    ui_Main->groupBox_3->setVisible(v3);
    ui_Main->groupBox_4->setVisible(v4);
    ui_Main->groupBox_5->setVisible(v5);
}


 void MainWindow::AddToProgress(QProgressBar * pb, QLabel* W, QCheckBox * CB,  int index)
 {
     QSqlQuery query;
     QSqlRecord rec;
     QString str_t;
     int P, P2;
     QString nameHabit;
     P = GetIdHabit(index);
     str_t = "SELECT name_habit "
             "FROM Habits "
             "WHERE id_habit = ";
     str_t.append(QString::number(P));
     str_t.append(";");
     query.exec(str_t);
     query.next();
     nameHabit = query.value(0).toString();
     str_t = "SELECT id_user_habit "
             "FROM User_Habits "
             "WHERE id_habit = ";
     str_t.append(QString::number(P));
     str_t.append(";");
     query.exec(str_t);
     query.next();
     P2 = query.value(0).toInt();
     W->setText(nameHabit);
     setProgressbar(P, P2, pb);
 }

 void MainWindow::visibleCheck()
 {
     QSqlQuery query;
     QSqlRecord rec;
     QString str_t;
     int P;
     str_t = "SELECT MAX(id_user_habit) "
             "FROM User_Habits";
     query.exec(str_t);
      query.next();
     P = query.value(0).toInt();
     switch (P)
     {
     case 0:
         SetVisible(false, false, false, false, false);
         break;
     case 1:
         SetVisible(true, false, false, false, false);
         AddToProgress(ui_Main->progressBar,  ui_Main->label_2, ui_Main->checkBox , 1);

         break;
     case 2:
         SetVisible(true, true, false, false, false);
         AddToProgress(ui_Main->progressBar,ui_Main->label_2, ui_Main->checkBox, 1);
         AddToProgress(ui_Main->progressBar_2, ui_Main->label_3, ui_Main->checkBox_2, 2);
         break;
     case 3:
         SetVisible(true, true, true, false, false);
         AddToProgress(ui_Main->progressBar, ui_Main->label_2, ui_Main->checkBox, 1);
         AddToProgress(ui_Main->progressBar_2, ui_Main->label_3, ui_Main->checkBox_2, 2);
         AddToProgress(ui_Main->progressBar_3, ui_Main->label_4, ui_Main->checkBox_3, 3);
         break;
     case 4:
         SetVisible(true, true, true, true, false);
         AddToProgress(ui_Main->progressBar, ui_Main->label_2, ui_Main->checkBox, 1);
         AddToProgress(ui_Main->progressBar_2, ui_Main->label_3, ui_Main->checkBox_2, 2);
         AddToProgress(ui_Main->progressBar_3, ui_Main->label_4, ui_Main->checkBox_3, 3);
         AddToProgress(ui_Main->progressBar_4, ui_Main->label_5, ui_Main->checkBox_4, 4);
         break;
     case 5:
         SetVisible(true, true, true, true, true);
         AddToProgress(ui_Main->progressBar, ui_Main->label_2, ui_Main->checkBox, 1);
         AddToProgress(ui_Main->progressBar_2, ui_Main->label_3, ui_Main->checkBox_2, 2);
         AddToProgress(ui_Main->progressBar_3, ui_Main->label_4, ui_Main->checkBox_3, 3);
         AddToProgress(ui_Main->progressBar_4, ui_Main->label_5, ui_Main->checkBox_4, 4);
         AddToProgress(ui_Main->progressBar_5, ui_Main->label_6, ui_Main->checkBox_5, 5);
         break;
     default:
         break;
     }
 }


 void MainWindow::setProgressbar(int id_habit, int user_habit, QProgressBar * pb)
 {
     QSqlQuery query1, query2;
     QString str_t;
     int P1, P2;
     QString nameHabit;
     str_t = "SELECT how_long "
             "FROM Habits "
             "WHERE id_habit = ";
     str_t.append(QString::number(id_habit));
     str_t.append(";");
     query1.exec(str_t);
     query1.next();
     P1 = query1.value(0).toInt();
     pb->setMaximum(P1);
     str_t = "SELECT progression "
             "FROM User_Habits "
             "WHERE id_user_habit = ";
     str_t.append(QString::number(user_habit));
     str_t.append(";");
     query2.exec(str_t);
     query2.next();
     P2 = query2.value(0).toInt();
     pb->setValue(P2);
 }

int MainWindow::GetIdHabit(int Id_user_habit)
{
    QSqlQuery query;
    QString str_t;
    str_t = "SELECT id_habit "
            "FROM User_Habits "
            "WHERE id_user_habit = ";
    str_t.append(QString::number(Id_user_habit));
    str_t.append(";");
    query.exec(str_t);
    query.next();
    return query.value(0).toInt();
}



void MainWindow::on_checkBox_stateChanged(int arg1)
{
    TC.DateCheck(1, ui_Main->checkBox->isChecked());
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    TC.DateCheck(2, ui_Main->checkBox_2->isChecked());
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    TC.DateCheck(3, ui_Main->checkBox_3->isChecked());
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    TC.DateCheck(4, ui_Main->checkBox_4->isChecked());
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    TC.DateCheck(5, ui_Main->checkBox_5->isChecked());
}


void MainWindow::on_menuButton_clicked()
{
    this->hide();
ui_menu.show();
}
void MainWindow::menuTodayButton()
{
     ui_menu.hide();
    this->show();
}


