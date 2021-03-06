QT += widgets multimedia sql

TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    filesystem/addressbar.cpp \
    filesystem/addressbarbutton.cpp \
    filesystem/addressbarmenu.cpp \
    filesystem/filesystemtreeview.cpp \
    treeview.cpp \
    library/libraryfilterproxymodel.cpp \
    library/libraryitemdelegate.cpp \
    library/libraryorderdialog.cpp \
    library/libraryscrollbar.cpp \
    library/librarytreeview.cpp \
    circleprogressbar.cpp \
    tracksnotfoundmessagebox.cpp \
    quickstart.cpp \
    timelabel.cpp \
    columnutils.cpp \
    playbackmodewidget.cpp \
    playbackmodewidgetfactory.cpp \
    playlists/playlist.cpp \
    playlists/playlistheaderview.cpp \
    playlists/playlistmodel.cpp \
    playlists/tabbar.cpp \
    playlists/tabplaylist.cpp \
    dialogs/closeplaylistpopup.cpp \
    dialogs/colordialog.cpp \
    dialogs/customizeoptionsdialog.cpp \
    dialogs/customizethemedialog.cpp \
    dialogs/dragdropdialog.cpp \
    dialogs/playlistmanager.cpp \
    dialogs/reflector.cpp \
    dialogs/shortcutlineedit.cpp \
    dialogs/shortcutwidget.cpp \
    tageditor/albumcover.cpp \
    tageditor/tagconverter.cpp \
    tageditor/tageditor.cpp \
    tageditor/tageditortablewidget.cpp \
    pluginmanager.cpp \
    plugininfo.cpp \
    library/jumptowidget.cpp \
    volumeslider.cpp \
    playlists/playlistitemdelegate.cpp \
    playlists/starrating.cpp \
    playlists/stareditor.cpp

HEADERS += \
    mainwindow.h \
    filesystem/addressbar.h \
    filesystem/addressbarbutton.h \
    filesystem/addressbarmenu.h \
    filesystem/filesystemtreeview.h \
    treeview.h \
    library/extendedtabbar.h \
    library/extendedtabwidget.h \
    library/libraryfilterproxymodel.h \
    library/libraryitemdelegate.h \
    library/libraryorderdialog.h \
    library/libraryscrollbar.h \
    library/librarytreeview.h \
    circleprogressbar.h \
    tracksnotfoundmessagebox.h \
    quickstart.h \
    timelabel.h \
    columnutils.h \
    nofocusitemdelegate.h \
    playbackmodewidget.h \
    playbackmodewidgetfactory.h \
    playlists/playlist.h \
    playlists/playlistheaderview.h \
    playlists/playlistmodel.h \
    playlists/tabbar.h \
    playlists/tabplaylist.h \
    dialogs/closeplaylistpopup.h \
    dialogs/colordialog.h \
    dialogs/customizeoptionsdialog.h \
    dialogs/customizethemedialog.h \
    dialogs/dragdropdialog.h \
    dialogs/playlistmanager.h \
    dialogs/reflector.h \
    dialogs/shortcutlineedit.h \
    dialogs/shortcutwidget.h \
    tageditor/albumcover.h \
    tageditor/tagconverter.h \
    tageditor/tageditor.h \
    tageditor/tageditortablewidget.h \
    pluginmanager.h \
    plugininfo.h \
    library/jumptowidget.h \
    volumeslider.h \
    playlists/playlistitemdelegate.h \
    playlists/starrating.h \
    playlists/stareditor.h

FORMS += \
    mainwindow.ui \
    customizeoptionsdialog.ui \
    customizetheme.ui \
    dragdroppopup.ui \
    libraryorderdialog.ui \
    playlistmanager.ui \
    quickstart.ui \
    tagconverter.ui \
    tageditor.ui \
    closeplaylistpopup.ui

RESOURCES += \
    mmmmp.qrc

win32 {
    RC_FILE += config/mmmmp.rc
    OTHER_FILES += config/mmmmp.rc
}
unix {
    CONFIG += c++11
    QMAKE_CXXFLAGS += -std=c++11
}
macx {
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.8
}

TRANSLATIONS = translations/m4p_ar.ts \
    translations/m4p_de.ts \
    translations/m4p_en.ts \
    translations/m4p_es.ts \
    translations/m4p_fr.ts \
    translations/m4p_it.ts \
    translations/m4p_ja.ts \
    translations/m4p_kr.ts \
    translations/m4p_pt.ts \
    translations/m4p_ru.ts \
    translations/m4p_th.ts \
    translations/m4p_vn.ts \
    translations/m4p_zh.ts

CONFIG(debug, debug|release) {
    win32: LIBS += -L$$PWD/../../lib/debug/ -ltag -L$$OUT_PWD/../MiamCore/debug/ -lMiamCore -L$$OUT_PWD/../MiamUniqueLibrary/debug/ -lMiamUniqueLibrary
    win32: QMAKE_POST_LINK += $${QMAKE_COPY} $$shell_path($$PWD/mmmmp.ico) $$shell_path($$OUT_PWD/debug/)
    OBJECTS_DIR = debug/.obj
    MOC_DIR = debug/.moc
    RCC_DIR = debug/.rcc
    UI_DIR = $$PWD
}

CONFIG(release, debug|release) {
    win32: LIBS += -L$$PWD/../../lib/release/ -ltag -L$$OUT_PWD/../MiamCore/release/ -lMiamCore -L$$OUT_PWD/../MiamUniqueLibrary/release/ -lMiamUniqueLibrary
    win32: QMAKE_POST_LINK += $${QMAKE_COPY} $$shell_path($$PWD/mmmmp.ico) $$shell_path($$OUT_PWD/release/)
    OBJECTS_DIR = release/.obj
    MOC_DIR = release/.moc
    RCC_DIR = release/.rcc
    UI_DIR = $$PWD
}
unix:!macx {
    LIBS += -ltag -L$$OUT_PWD/../MiamCore/ -lMiamCore -L$$OUT_PWD/../MiamUniqueLibrary/ -lMiamUniqueLibrary
}
macx {
    LIBS += -L$$PWD/../../lib/ -ltag -L$$OUT_PWD/../MiamCore/ -lMiamCore -L$$OUT_PWD/../MiamUniqueLibrary/ -lMiamUniqueLibrary
    ICON = $$PWD/mmmmp.icns
    QMAKE_INFO_PLIST = $$PWD/../../packaging/osx/Info.plist
    #1 create Framework directory
    #2 copy third party library: TagLib
    #3 copy own libs
    #4 execute macdeploy to create a nice bundle
    QMAKE_POST_LINK += $${QMAKE_MKDIR} $$shell_path($$OUT_PWD/MiamPlayer.app/Contents/Frameworks/) && \
      $${QMAKE_COPY} $$shell_path($$PWD/../../lib/libtag.dylib) $$shell_path($$OUT_PWD/MiamPlayer.app/Contents/Frameworks/) && \
      $${QMAKE_COPY} $$shell_path($$OUT_PWD/../MiamCore/libMiamCore.1.dylib) $$shell_path($$OUT_PWD/MiamPlayer.app/Contents/Frameworks/) && \
      $${QMAKE_COPY} $$shell_path($$OUT_PWD/../MiamUniqueLibrary/libMiamUniqueLibrary.1.dylib) $$shell_path($$OUT_PWD/MiamPlayer.app/Contents/Frameworks/) && \
      $${QMAKESPEC}/../../bin/macdeployqt $$OUT_PWD/MiamPlayer.app
}

INCLUDEPATH += $$PWD/../MiamCore
INCLUDEPATH += $$PWD/dialogs $$PWD/filesystem $$PWD/library $$PWD/playlists $$PWD/tageditor
INCLUDEPATH += $$PWD/../MiamUniqueLibrary

DEPENDPATH += $$PWD/../MiamCore
DEPENDPATH += $$PWD/dialogs $$PWD/filesystem $$PWD/library $$PWD/playlists $$PWD/tageditor
DEPENDPATH += $$PWD/../MiamUniqueLibrary
