#ifndef ADDHABIT_H
#define ADDHABIT_H

#include <QWidget>

#include <QString>

#include <QtSql/QtSql>

#include "dataset.h"
#include "mainwindow.h"




namespace Ui {
class AddHabit;
}

class AddHabit : public QWidget
{
    Q_OBJECT

public:
    explicit AddHabit(QWidget *parent = nullptr);
    ~AddHabit();
    bool connectDB();
    void wipeDB();
    void addHabit();

private:
    Ui::AddHabit *ui;
    MainWindow mainW;
    QString habit_name;
    QString m_userpass;
    QString m_login;
    QString db_input;
    QSqlDatabase db;
    int habit_counter;
private slots:
    void OpenWindow();
};

#endif // ADDHABIT_H
