QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    associationinteraction.cpp \
    contact.cpp \
    controllercontact.cpp \
    controllerinteraction.cpp \
    controllertodo.cpp \
    creercontact.cpp \
    gestionbd.cpp \
    gestioncontacts.cpp \
    gestionnaireinteraction.cpp \
    gestiontodo.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    pagecontact.cpp \
    todo.cpp \
    widgetaddinteraction.cpp \
    widgetaddtodo.cpp \
    widgetinteractionpage.cpp \
    widgetlistescontacts.cpp \
    widgetmodifycontact.cpp

HEADERS += \
    associationinteraction.h \
    contact.h \
    controllercontact.h \
    controllerinteraction.h \
    controllertodo.h \
    creercontact.h \
    gestionbd.h \
    gestioncontacts.h \
    gestionnaireinteraction.h \
    gestiontodo.h \
    interaction.h \
    mainwindow.h \
    pagecontact.h \
    sdateauto.h \
    todo.h \
    widgetaddinteraction.h \
    widgetaddtodo.h \
    widgetinteractionpage.h \
    widgetlistescontacts.h \
    widgetmodifycontact.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    creercontact.ui \
    mainwindow.ui \
    pagecontact.ui \
    widgetaddinteraction.ui \
    widgetaddtodo.ui \
    widgetinteractionpage.ui \
    widgetlistescontacts.ui \
    widgetmodifycontact.ui

RESOURCES += \
    Ressources_QT.qrc

DISTFILES += \
    Ressources/ajouter-interaction.png \
    Ressources/interaction.png \
    Ressources/tache.png

TRANSLATIONS += CDAA_Project_en.ts \


