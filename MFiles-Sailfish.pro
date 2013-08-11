# The name of your app
TARGET = MFiles-Sailfish

# C++ sources
SOURCES += main.cpp

# C++ headers
HEADERS +=

# QML files and folders
qml.files = *.qml common pages cover main.qml

# The .desktop file
desktop.files = MFiles-Sailfish.desktop

# Please do not modify the following line.
include(sailfishapplication/sailfishapplication.pri)

OTHER_FILES = \
    rpm/MFiles-Sailfish.yaml \
    rpm/MFiles-Sailfish.spec \
    pages/LogIn.qml
