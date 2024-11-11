QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    functionsforclient.cpp \
    inputip_form.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationorauthorization.cpp \
    singletonclient.cpp

HEADERS += \
    functionsforclient.h \
    inputip_form.h \
    mainwindow.h \
    registrationorauthorization.h \
    singletonclient.h

FORMS += \
    inputip_form.ui \
    mainwindow.ui \
    registrationorauthorization.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
