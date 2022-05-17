#ifndef TIMECHECK_H
#define TIMECHECK_H

#include <QDateTime>
#include <QtSql/QtSql>

class TimeCheck
{
private:
    QDate currDate();
    int currDayOfWeek;
public:
    TimeCheck();
    void SetcurrDate();
    QDate GetcurrDate();
    void AddToProgress(bool value, int id_Habit);
    void DateChecker(int id_Habit, bool value);

};

#endif // TIMECHECK_H
