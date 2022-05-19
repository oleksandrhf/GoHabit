#ifndef ADDHABIT_H
#define ADDHABIT_H

#include <QWidget>

#include <QString>

#include <QtSql/QtSql>

#include "dataset.h"

#include "QComboBox"

#include "createhabit.h"




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
    void showHabitsInCombobox();
    QString det_days();
    void GetIdHabit();
private:
    Ui::AddHabit *ui;
    CreateHabit c_habit;
    QString habit_name;
    QComboBox List_habits_comboBox;
    QString db_input;
    QSqlDatabase db;
    int habit_counter;
    int thisUserId;
    int thisHabitId;
signals:
    void backed();
private slots:
    void on_pushButton_clicked();
    void on_habit_created();
    void on_back_clicked();
    void on_Add_habit_button_clicked();
    void on_pushButton_4_clicked();
};

#endif // ADDHABIT_H
