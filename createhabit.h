#ifndef CREATEHABIT_H
#define CREATEHABIT_H

#include <QWidget>
#include <QtSql/QtSql>

namespace Ui {
class CreateHabit;
}

class CreateHabit : public QWidget
{
    Q_OBJECT

public:
    explicit CreateHabit(QWidget *parent = nullptr);
    ~CreateHabit();
    bool connectDB();
    QSqlDatabase db;
signals:
    void new_habit_added();
    void back_clicked();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_2_clicked();

private:
    Ui::CreateHabit *ui;
};

#endif // CREATEHABIT_H
