TEMPLATE = app
CONFIG += console c++21
CONFIG -= app_bundle
CONFIG -= qt




INCLUDEPATH += "C:/SFML-2.5.1-sources/SFML-2.5.1/include"
DEPENDPATH += "C:/SFML-2.5.1-sources/SFML-2.5.1/include"


LIBS += -L"C:/Biblioteka/LIBS"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}




SOURCES += \
    Szachy/Dane_poczatkowe/Funkcje.cpp \
    Szachy/Dane_poczatkowe/daneliczbowe.cpp \
    Szachy/Dane_poczatkowe/Zdarzenia.cpp \
    Szachy/Dane_poczatkowe/Zmienne.cpp \
    Szachy/Dane_poczatkowe/Struktury_danych.cpp \
    \
    Szachy/Okna/Okno_startowe/okno_startowe.cpp \
    \
    Szachy/Okna/Gra/Plansza.cpp \
    Szachy/Okna/Gra/figura.cpp \
    Szachy/Okna/Gra/interfejs.cpp \
    \
    Szachy/Okna/Piaskownica/piaskownica.cpp \
    \
    Szachy/Klasy_pomocnice/suwak.cpp \
    Szachy/Klasy_pomocnice/tekst.cpp \
    Szachy/Klasy_pomocnice/przycisk.cpp \
    Szachy/Klasy_pomocnice/animacja.cpp \
    Szachy/Klasy_pomocnice/animacja_plynna.cpp \
    \
    szachy.cpp \
    main.cpp


HEADERS += \
    Szachy/Dane_poczatkowe/daneliczbowe.h \
    Szachy/Dane_poczatkowe/Struktury_danych.h \
    Szachy/Dane_poczatkowe/Zdarzenia.h \
    Szachy/Dane_poczatkowe/Zmienne.h \
    Szachy/Dane_poczatkowe/funkcje.h \
    \
    Szachy/Okna/Okno_startowe/okno_startowe.h \
    \
    Szachy/Okna/Gra/interfejs.h \
    Szachy/Okna/Gra/figura.h \
    Szachy/Okna/Gra/Plansza.h \
    \
    Szachy/Okna/Piaskownica/piaskownica.h \
    \
    Szachy/Klasy_pomocnice/przycisk.h \
    Szachy/Klasy_pomocnice/suwak.h \
    Szachy/Klasy_pomocnice/tekst.h \
    Szachy/Klasy_pomocnice/animacja.h \
    Szachy/Klasy_pomocnice/animacja_plynna.h \
    \
    szachy.h \
    stb_image_write.h
