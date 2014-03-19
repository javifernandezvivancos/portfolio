# -------------------------------------------------
# Project created by QtCreator 2010-02-23T18:42:48
# -------------------------------------------------
TARGET = QFotoPaint
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    imagenes.cpp \
    dialognueva.cpp \
    brillocontraste.cpp \
    suavizados.cpp \
    video.cpp \
    rotaravideo.cpp \
    mediaponderada.cpp \
    acercade.cpp \
    mediadevideo.cpp \
    pincharestirar.cpp \
    capturardecamara.cpp \
    capturardevideo.cpp \
    histograma.cpp \
    histograma2d.cpp \
    matizsaturacionluminosidad.cpp \
    ecualizacionhistograma.cpp \
    inpaint.cpp \
    ajustelinealhist.cpp \
    perfilado.cpp \
    transicionvideo.cpp \
    minimamaximadevideo.cpp \
    detecciondefondo.cpp \
    transformacionamalla.cpp \
    informacion.cpp \
    bajorrelieve.cpp
HEADERS += mainwindow.h \
    imagenes.h \
    dialognueva.h \
    brillocontraste.h \
    suavizados.h \
    video.h \
    rotaravideo.h \
    mediaponderada.h \
    acercade.h \
    mediadevideo.h \
    pincharestirar.h \
    capturardecamara.h \
    capturardevideo.h \
    histograma.h \
    histograma2d.h \
    matizsaturacionluminosidad.h \
    ecualizacionhistograma.h \
    inpaint.h \
    ajustelinealhist.h \
    perfilado.h \
    transicionvideo.h \
    minimamaximadevideo.h \
    detecciondefondo.h \
    transformacionamalla.h \
    informacion.h \
    bajorrelieve.h
FORMS += mainwindow.ui \
    dialognueva.ui \
    brillocontraste.ui \
    suavizados.ui \
    rotaravideo.ui \
    mediaponderada.ui \
    acercade.ui \
    mediadevideo.ui \
    pincharestirar.ui \
    capturardecamara.ui \
    capturardevideo.ui \
    histograma.ui \
    histograma2d.ui \
    matizsaturacionluminosidad.ui \
    ecualizacionhistograma.ui \
    inpaint.ui \
    ajustelinealhist.ui \
    perfilado.ui \
    transicionvideo.ui \
    minimamaximadevideo.ui \
    detecciondefondo.ui \
    transformacionamalla.ui \
    informacion.ui \
    bajorrelieve.ui
INCLUDEPATH += "D:\ProgramasXP\OpenCV2.0\include\opencv"
LIBS += -L"D:\ProgramasXP\OpenCV2.0\lib" \
    -lcv200 \
    -lcxcore200 \
    -lhighgui200
RESOURCES += recursos.qrc
