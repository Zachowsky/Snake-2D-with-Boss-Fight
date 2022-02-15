QT       += core gui
QT       += multimedia \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boards.cpp \
    game.cpp \
    gameover.cpp \
    keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    setoptions.cpp

HEADERS += \
    boards.h \
    game.h \
    gameover.h \
    keyboard.h \
    mainwindow.h \
    setoptions.h

FORMS += \
    boards.ui \
    gameover.ui \
    mainwindow.ui \
    setoptions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH +=
RESOURCES += \
    Resource.qrc

DISTFILES += \
    img/black.jpg \
    img/board1.jpg \
    img/board2.jpg \
    img/board3.jpg \
    img/board4.jpg \
    img/board5.jpg \
    img/boss.png \
    img/boss1.png \
    img/boss2.png \
    img/boss3.png \
    img/boss4.png \
    img/brick.png \
    img/button.jpg \
    img/button_hover.png \
    img/button_pressed.png \
    img/fireball.png \
    img/food.png \
    img/fruit2.png \
    img/fruit3.png \
    img/grass.jpg \
    img/headDown.png \
    img/headLeft.png \
    img/headRight.png \
    img/headUp.png \
    img/menu.png \
    sound/back.mp3 \
    sound/background.mp3 \
    sound/boss_sound.mp3 \
    sound/crash.mp3 \
    sound/down.mp3 \
    sound/eat.mp3 \
    sound/explosion.mp3 \
    sound/fireball.mp3 \
    sound/hover.mp3 \
    sound/left.mp3 \
    sound/pick.mp3 \
    sound/right.mp3 \
    sound/up.mp3
