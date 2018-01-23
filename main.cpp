#include "quadraticequationcalcmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuadraticEquationCalcMainWindow w;
    w.show();

    return a.exec();
}
