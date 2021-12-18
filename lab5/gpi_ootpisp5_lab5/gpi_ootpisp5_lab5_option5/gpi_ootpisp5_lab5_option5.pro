QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gpi_employeeform.cpp \
    gpi_employeepaydayform.cpp \
    gpi_monthjobform.cpp \
    gpi_paymentform.cpp \
    main.cpp \
    gpi_mainwindow.cpp

HEADERS += \
    gpi_employeeform.hpp \
    gpi_employeepaydayform.hpp \
    gpi_mainwindow.hpp \
    gpi_monthjobform.hpp \
    gpi_paymentform.hpp

FORMS += \
    gpi_employeeform.ui \
    gpi_employeepaydayform.ui \
    gpi_mainwindow.ui \
    gpi_monthjobform.ui \
    gpi_paymentform.ui

RESOURCES += \
    gpi_resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
