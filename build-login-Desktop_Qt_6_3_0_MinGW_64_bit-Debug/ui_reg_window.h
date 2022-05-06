/********************************************************************************
** Form generated from reading UI file 'reg_window.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_WINDOW_H
#define UI_REG_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg_window
{
public:
    QLineEdit *nameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmLineEdit;
    QPushButton *registerPushButton;
    QLineEdit *LoginlineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *reg_window)
    {
        if (reg_window->objectName().isEmpty())
            reg_window->setObjectName(QString::fromUtf8("reg_window"));
        reg_window->resize(291, 549);
        nameLineEdit = new QLineEdit(reg_window);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(80, 170, 113, 26));
        passwordLineEdit = new QLineEdit(reg_window);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(80, 240, 113, 26));
        confirmLineEdit = new QLineEdit(reg_window);
        confirmLineEdit->setObjectName(QString::fromUtf8("confirmLineEdit"));
        confirmLineEdit->setGeometry(QRect(80, 310, 113, 26));
        registerPushButton = new QPushButton(reg_window);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setGeometry(QRect(90, 380, 93, 29));
        LoginlineEdit = new QLineEdit(reg_window);
        LoginlineEdit->setObjectName(QString::fromUtf8("LoginlineEdit"));
        LoginlineEdit->setGeometry(QRect(80, 110, 113, 26));
        label = new QLabel(reg_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 80, 63, 20));
        label_2 = new QLabel(reg_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 150, 63, 20));
        label_3 = new QLabel(reg_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 210, 63, 20));
        label_4 = new QLabel(reg_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 290, 121, 20));

        retranslateUi(reg_window);

        QMetaObject::connectSlotsByName(reg_window);
    } // setupUi

    void retranslateUi(QWidget *reg_window)
    {
        reg_window->setWindowTitle(QCoreApplication::translate("reg_window", "Form", nullptr));
        registerPushButton->setText(QCoreApplication::translate("reg_window", "register", nullptr));
        label->setText(QCoreApplication::translate("reg_window", "nickname", nullptr));
        label_2->setText(QCoreApplication::translate("reg_window", "login", nullptr));
        label_3->setText(QCoreApplication::translate("reg_window", "password", nullptr));
        label_4->setText(QCoreApplication::translate("reg_window", "confirm password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg_window: public Ui_reg_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_WINDOW_H
