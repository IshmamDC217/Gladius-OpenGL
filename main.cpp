#include "swordwidgets.h"
#include <QApplication>
#include <QVBoxLayout>
#include "swordwindow.h"

int main(int argc, char *argv[])
    {
    // create the application
    QApplication app(argc, argv);
    // create a master widget
        swordwindow *window = new swordwindow(NULL);

    // resizes window
    window->resize(900, 500);

    // shows label
    window->show();

    // start it running
    app.exec();
    //	delete controller;
    delete window;

    // return to caller
    return 0;
    }
