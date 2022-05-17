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
    connect(&M, SIGNAL(Today_clicked()),
            this, SLOT(todayClicked()));

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
            &ui_Auth, SLOT(show()));//Сигнали на спрацьовування кнопок
    if(ui_Main->checkBox->isChecked())
    {
        QDateTime T;
        DT = T.currentDateTime();
    }
    if(!connectDB())
    {
        qDebug() << "Failed to connect DB";
    }
   ui_Main->setupUi(this);

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
}

void MainWindow::todayClicked()
{
    this->show();
    M.hide();
}




void MainWindow::on_pushButton_2_clicked()
{
    M.show();
    this->hide();
}

