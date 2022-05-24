
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createhabit.cpp \
    addhabit.cpp \
    auth_window.cpp \
    dataset.cpp \
    main.cpp \
    menu.cpp \
    mainwindow.cpp \
    reg_window.cpp \
    timecheck.cpp

HEADERS += \
    menu.h \
    createhabit.h \
    addhabit.h \
    auth_window.h \
    dataset.h \
    mainwindow.h \
    reg_window.h \
    timecheck.h

FORMS += \
    menu.ui \
    createhabit.ui \
    addhabit.ui \
    auth_window.ui \
    mainwindow.ui \
    reg_window.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
