
#include "timecheck.h"


TimeCheck::TimeCheck()
{

}

void TimeCheck::AddToProgress(bool value, int id_Habit)
{
    if(value)
    {
        QDateTime curr;
        QSqlQuery query;
        QSqlRecord rec;
        QString str_t;
        int P;
        str_t = "SELECT progression "
                "FROM User_Habits"
                    " WHERE id_user_habit = ";
        str_t.append(QString::number(id_Habit));
        str_t.append(";");
        query.exec(str_t);
        query.next();
        P = query.value(0).toInt();
        P++;
        str_t               =   "UPDATE User_Habits SET progression = ";
        str_t.append(QString::number(P));
        str_t.append(" WHERE ");
        str_t.append("id_user_habit = ");
        str_t.append(QString::number(id_Habit));
        query.exec(str_t);
    }
}


void TimeCheck::DateCheck(int id_user_Habit, bool value)
{
    QDateTime dcurrDateTime;
    QDateTime currDateTime, curr;
    currDateTime = dcurrDateTime.currentDateTime();
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;
    int checkTime;
    int time;
    str_t = "SELECT check_time "
            "FROM User_Habits"
            " WHERE id_user_habit = ";
    str_t.append(QString::number(id_user_Habit));
    str_t.append(";");
    query.exec(str_t);
    query.next();
    checkTime = query.value(0).toInt();
    if(currDateTime.toSecsSinceEpoch() - checkTime > 86400 || checkTime == 0)
    {
        AddToProgress(value, id_user_Habit);
    }
    if(value)
    {
        time = currDateTime.currentSecsSinceEpoch();
        str_t               =   "UPDATE User_Habits SET check_time = ";
        str_t.append(QString::number(time));
        str_t.append(" WHERE ");
        str_t.append("id_user_habit = ");
        str_t.append(QString::number(id_user_Habit));
        str_t.append(";");
        query.exec(str_t);
    }
}

