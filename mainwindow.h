#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "auth_window.h"
#include <QtSql/QtSql>
#include "reg_window.h"
#include "addhabit.h"
#include "menu.h"
#include <QDateTime>
#include <QLabel>
#include <QProgressBar>
#include <QCheckBox>
#include "timecheck.h"
#include "dataset.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void display();
    bool connectDB();
    void wipeDB();
    void SetCheckTime(int id, QDateTime T);
    void showAllHabits();
    void visibleCheck();
    void SetVisible(bool v1, bool v2, bool v3, bool v4, bool v5);
    void AddToProgress(QProgressBar * pb, QLabel* W, QCheckBox * CB, int index);
    void setProgressbar(int index1, int index2, QProgressBar * pb);
    int GetIdHabit(int Id_user_habit);

private:
    Ui::MainWindow *ui_Main;
    auth_window ui_Auth;
    menu M;
    reg_window ui_Reg;
    menu ui_menu;
    AddHabit ah;
    QString m_username;
    QString m_userpass;
    QString m_login;
    QString db_input;
    QSqlDatabase mw_db;
    QDateTime DT;
    TimeCheck TC;
    int user_counter;
    bool m_loginSuccesfull;
private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();
    void on_pushButton_clicked();
    void on_go_back();
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_checkBox_2_stateChanged(int arg1);
    void on_checkBox_3_stateChanged(int arg1);
    void on_checkBox_4_stateChanged(int arg1);
    void on_checkBox_5_stateChanged(int arg1);
    void on_menuButton_clicked();
    void menuTodayButton();


};

#endif // MAINWINDOW_H
