#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth_window.h"
#include "reg_window.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_Main(new Ui::MainWindow)
{
    user_counter = 0;
    m_loginSuccesfull = false;
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
    if(!connectDB())
    {
        qDebug() << "Failed to connect DB";
    }

    QSqlQuery query;

   query.exec("CREATE TABLE userlist ( "
              "number INTEGER PRIMARY KEY NOT NULL,"
              "name VARCHAR(20), "
              "pass VARCHAR(12), "
              "login VARCHAR(12));");     //створення таблиці
   ui_Main->setupUi(this);
}

void MainWindow::authorizeUser()
{

    m_username          = ui_Auth.getLogin();
    m_userpass          = ui_Auth.getPass();   //зчитування з форми

    QString str_t       = " SELECT * "
                          " FROM userlist "
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
    user_counter   = query.value(rec.indexOf("number")).toInt();
    username    = query.value(rec.indexOf("name")).toString();
    userpass    = query.value(rec.indexOf("pass")).toString();
    login       = query.value(rec.indexOf("login")).toString();  //зчитування з бази
    if(m_username != username || m_userpass != userpass)         //порівняння на правильність
    {
        qDebug() << "Password missmatch" << username << " " << userpass;
        m_loginSuccesfull = false;
    }
    else
    {
        m_loginSuccesfull = true;
        ui_Auth.close();
        ui_Reg.close();
        this->show();
        ui_Main->label->setText("welcome " + login);
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
                   "FROM userlist;");
        query.next();
        rec = query.record();
        user_counter = rec.value(0).toInt();
        qDebug() << user_counter;
        m_username          = ui_Reg.getName();
        m_userpass          = ui_Reg.getPass();    //зчитування даних з форми
        m_login             = ui_Reg.getLogin();
        user_counter++;
        str_t               =   "INSERT INTO userlist(number, name, pass, login)"
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
