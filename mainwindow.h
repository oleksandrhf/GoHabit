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
#include "dropmenu.h"


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
    void SetVisible();
    void AddToProgress(QProgressBar * pb, QLabel* W, QCheckBox * CB, int index);
    void setProgressbar(int index1, int index2, QProgressBar * pb);
    int GetIdHabit(int Id_user_habit);

private:
    Ui::MainWindow *ui_Main;
    auth_window ui_Auth;
    int arrayOfId[5];
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
    DropMenu DM;
    int user_counter;
    int correctHabitsCounter = 0;
    bool m_loginSuccesfull;
private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();
    void on_pushButton_clicked();
    void on_go_back();
    void on_pushButton_2_clicked();
    void on_menuButton_clicked();
    void menuTodayButton();
    void on_pushButton_3_clicked();
    void HideMenu();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void FillarrOfId();
    void on_habit_deleted(int i);
    void on_pushButton_11_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_19_clicked();
    void setsizeOfEverything();
    void on_logged_out();
    void blockCheckbox(bool state);
    void setStateOfCheckBox(int i, bool state);
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();

signals :
    void arrfilled();
};

#endif // MAINWINDOW_H
