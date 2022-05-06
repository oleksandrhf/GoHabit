/********************************************************************************
** Form generated from reading UI file 'auth_window.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_WINDOW_H
#define UI_AUTH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth_window
{
public:
    QPushButton *login_PushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *register_pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *auth_window)
    {
        if (auth_window->objectName().isEmpty())
            auth_window->setObjectName(QString::fromUtf8("auth_window"));
        auth_window->resize(279, 532);
        login_PushButton = new QPushButton(auth_window);
        login_PushButton->setObjectName(QString::fromUtf8("login_PushButton"));
        login_PushButton->setGeometry(QRect(10, 350, 93, 29));
        lineEdit = new QLineEdit(auth_window);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 200, 113, 26));
        lineEdit_2 = new QLineEdit(auth_window);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 270, 113, 26));
        register_pushButton_2 = new QPushButton(auth_window);
        register_pushButton_2->setObjectName(QString::fromUtf8("register_pushButton_2"));
        register_pushButton_2->setGeometry(QRect(140, 350, 93, 29));
        label = new QLabel(auth_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 170, 63, 20));
        label_2 = new QLabel(auth_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 240, 63, 20));

        retranslateUi(auth_window);

        QMetaObject::connectSlotsByName(auth_window);
    } // setupUi

    void retranslateUi(QWidget *auth_window)
    {
        auth_window->setWindowTitle(QCoreApplication::translate("auth_window", "Form", nullptr));
        login_PushButton->setText(QCoreApplication::translate("auth_window", "sign in", nullptr));
        register_pushButton_2->setText(QCoreApplication::translate("auth_window", "sign up", nullptr));
        label->setText(QCoreApplication::translate("auth_window", "login", nullptr));
        label_2->setText(QCoreApplication::translate("auth_window", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class auth_window: public Ui_auth_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_WINDOW_H
