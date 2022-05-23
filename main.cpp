#include "mainwindow.h"
#include <QApplication>
#include "reg_window.h"
#include "auth_window.h"
#include "addhabit.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(!w.connectDB())
        exit(1);

    w.display();

    return a.exec();
}
