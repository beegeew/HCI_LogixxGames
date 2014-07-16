#include <QtGui/QApplication>
#include "gamehub.h"
#include "mainscreen.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    int num = 0;

        QApplication a(argc, argv);
        gameHub w;

        w.show();

        num = a.exec();

    return num;
}
