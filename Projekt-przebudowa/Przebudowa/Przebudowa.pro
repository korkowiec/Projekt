TEMPLATE = app
CONFIG += console c++21
CONFIG -= app_bundle
CONFIG -= qt




INCLUDEPATH += "C:/SFML-2.5.1/include"

        LIBS += -L"C:/SFML-2.5.1/lib"
        CONFIG(debug, debug|release){
            LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        } else {
            LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
        }


SOURCES += \
    Szachy/GlobalVariabies/GlobalFunctions.cpp \
    Szachy/GlobalVariabies/Variables.cpp \
    \
    Szachy/HelpClass/FrameAnimation.cpp \
    Szachy/HelpClass/RenderWindow.cpp \
    Szachy/HelpClass/RotateAnimation.cpp \
    Szachy/HelpClass/Slider.cpp \
    Szachy/HelpClass/Text.cpp \
    \
    Szachy/SpecialClass/Chessman.cpp \
    \
    \
    Szachy/Windows/BasicGame/BasicGame.cpp \
    Szachy/Windows/BasicGame/Console.cpp \
    \
    Szachy/Windows/Menu/Menu.cpp \
    \
    Szachy/Windows/PlaySandbox/PlaySandbox.cpp \
    \
    Szachy/Windows/SandboxChessboard/SandboxChessboard.cpp \
    \
    Szachy/Windows/SandboxChessman/SandboxChessman.cpp \
    \
    Szachy/Chess.cpp \
    main.cpp


HEADERS += \
    Szachy/GlobalVariabies/GlobalFunctions.h \
    Szachy/GlobalVariabies/Variables.h \
    \
    Szachy/HelpClass/Button.h \
    Szachy/HelpClass/FrameAnimation.h \
    Szachy/HelpClass/RenderWindow.h \
    Szachy/HelpClass/RotateAnimation.h \
    Szachy/HelpClass/Slider.h \
    Szachy/HelpClass/Text.h \
    \
    Szachy/SpecialClass/Chessman.h \
    \
    \
    Szachy/Windows/BasicGame/BasicGame.h \
    Szachy/Windows/BasicGame/Console.h \
    \
    Szachy/Windows/Menu/Menu.h \
    \
    Szachy/Windows/PlaySandbox/PlaySandbox.h \
    \
    Szachy/Windows/SandboxChessboard/SandboxChessboard.h \
    \
    Szachy/Windows/SandboxChessman/SandboxChessman.h \
    \
    Szachy/Chess.h \







