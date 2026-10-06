
#include "gmeteora.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GMeteORA window;
    window.show();

    return app.exec();
}