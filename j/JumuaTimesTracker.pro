QT +=  quick
QT += qml



TEMPLATE = app



CONFIG += c++11

Q_DIR = $$[QT_INSTALL_QML]
QML_DIR_WIN = $$replace(Q_DIR, "/", "")
QMAKE_POST_LINK += $$escape_expand(\n) $$QMAKE_COPY_DIR "$$QML_DIR_WIN\QtGraphicalEffects" "$$DESTDIR_WIN\QtGraphicalEffects"
QMAKE_POST_LINK += $$escape_expand(\n) $$QMAKE_COPY_DIR "$$QML_DIR_WIN\QtQuick" "$$DESTDIR_WIN\QtQuick"
QMAKE_POST_LINK += $$escape_expand(\n) $$QMAKE_COPY_DIR "$$ QML_DIR_WIN\QtQuick.2" "$$DESTDIR_WIN\QtQuick.2"


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        datahtmlwebsitefilter.cpp \
        getdatafilters.cpp \
        main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    JumuaTimesTracker_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    datahtmlwebsitefilter.h \
    getdatafilters.h \
    include/curl/curl.h \
    include/curl/curlver.h \
    include/curl/easy.h \
    include/curl/header.h \
    include/curl/mprintf.h \
    include/curl/multi.h \
    include/curl/options.h \
    include/curl/stdcheaders.h \
    include/curl/system.h \
    include/curl/typecheck-gcc.h \
    include/curl/urlapi.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/lib/ -llibcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/lib/ -llibcurld
else:unix: LIBS += -L$$PWD/libraries/lib/ -llibcurl

INCLUDEPATH += $$PWD/libraries/include
DEPENDPATH += $$PWD/libraries/include
