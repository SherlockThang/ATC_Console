#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T19:35:12
#
#-------------------------------------------------

QT       += core gui positioning

VPATH += ./custom \
    ./dialog \
    ./display \
    ./flight \
    ./main \
    ./nav \
    ./settings \
    ./ui \
    ./utils

INCLUDEPATH += ./custom \
    ./dialog \
    ./display \
    ./flight \
    ./main \
    ./nav \
    ./settings \
    ./ui \
    ./utils

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATCConsole
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    atcdialog.cpp \
    dialogmainmenu.cpp \
    dialogsectorsetup.cpp \
    dialogtextconsole.cpp \
    atclineedit.cpp \
    atcbuttons.cpp \
    atcconsolecommands.cpp \
    atcsituationaldisplay.cpp \
    atcairspacefix.cpp \
    atcairspacesector.cpp \
    atcairspace.cpp \
    atcconst.cpp \
    atcnavfix.cpp \
    atcbeaconvor.cpp \
    atcbeaconndb.cpp \
    atcairport.cpp \
    atcrunway.cpp \
    atcrunwayextendedcentreline.cpp \
    atcabstractbeacon.cpp \
    atcabstractfix.cpp \
    atcabstractprocedure.cpp \
    atcproceduresid.cpp \
    atcprocedurestar.cpp \
    atcabstractproceduresymbol.cpp \
    atcproceduresidsymbol.cpp \
    atcprocedurestarsymbol.cpp \
    atcabstractairway.cpp \
    atcairwaylow.cpp \
    atcairwayhigh.cpp \
    atcabstractsector.cpp \
    atcsectorartcclow.cpp \
    atcsectorartcchigh.cpp \
    atcsectorartcc.cpp \
    dialogsettings.cpp \
    dialogcolorpicker.cpp \
    atcsettings.cpp \
    atcsettingstableview.cpp \
    atccompany.cpp \
    atccompanyfactory.cpp \
    atcaircrafttype.cpp \
    atcaircrafttypefactory.cpp \
    atcpaths.cpp \
    atcroute.cpp \
    atcroutefactory.cpp \
    atcflightplan.cpp \
    atcflightplanfactory.cpp \
    atcflightnumberfactory.cpp \
    atcmath.cpp \
    atcflight.cpp \
    atcflightfactory.cpp \
    dialogflight.cpp \
    dialogflightcreator.cpp \
    atcsimulation.cpp \
    atcflighttag.cpp \
    atctagrect.cpp \
    dialogaltitude.cpp \
    dialogspeed.cpp \
    dialogheading.cpp \
    dialogroute.cpp \
    dialoghandoff.cpp

HEADERS  += mainwindow.h \
    atcdialog.h \
    atcmousehandler.h \
    dialogmainmenu.h \
    dialogsectorsetup.h \
    dialogtextconsole.h \
    atclineedit.h \
    atcbuttons.h \
    atcconsolecommands.h \
    atcsituationaldisplay.h \
    atcflags.h \
    atcairspacefix.h \
    atcairspacesector.h \
    atcairspace.h \
    atcconst.h \
    atcnavfix.h \
    atcbeaconvor.h \
    atcbeaconndb.h \
    atcairport.h \
    atcrunway.h \
    atcrunwayextendedcentreline.h \
    atcabstractbeacon.h \
    atcabstractfix.h \
    atcabstractprocedure.h \
    atcproceduresid.h \
    atcprocedurestar.h \
    atcabstractproceduresymbol.h \
    atcproceduresidsymbol.h \
    atcprocedurestarsymbol.h \
    atcabstractairway.h \
    atcairwaylow.h \
    atcairwayhigh.h \
    atcabstractsector.h \
    atcsectorartcclow.h \
    atcsectorartcchigh.h \
    atcsectorartcc.h \
    dialogsettings.h \
    dialogcolorpicker.h \
    atcsettings.h \
    atcsettingstableview.h \
    atccompany.h \
    atccompanyfactory.h \
    atcaircrafttype.h \
    atcaircrafttypefactory.h \
    atcpaths.h \
    atcroute.h \
    atcroutefactory.h \
    atcflightplan.h \
    atcflightplanfactory.h \
    atcflightnumberfactory.h \
    atcmath.h \
    atcflight.h \
    atcflightfactory.h \
    dialogflight.h \
    dialogflightcreator.h \
    atcsimulation.h \
    atcflighttag.h \
    atctagrect.h \
    dialogaltitude.h \
    dialogspeed.h \
    dialogheading.h \
    dialogroute.h \
    dialoghandoff.h

FORMS    += mainwindow.ui \
    atcdialog.ui \
    dialogmainmenu.ui \
    dialogsectorsetup.ui \
    dialogtextconsole.ui \
    dialogsettings.ui \
    dialogflight.ui \
    dialogflightcreator.ui \
    dialogaltitude.ui \
    dialogspeed.ui \
    dialogheading.ui \
    dialogroute.ui \
    dialoghandoff.ui

DISTFILES += \
    resources/acft_cursor.png
