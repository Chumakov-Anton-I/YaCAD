/* The entry point */

#include "DrawingWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DrawingWidget window;
    window.showMaximized();

    return app.exec();
}
