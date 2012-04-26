/**
 * @file main.cpp
 * @author Peter Šlosár <xslosa00@stud.fit.vutbr.cz>
 * @author Pavel Slabý <xslaby00@stud.fit.vutbr.cz>
 * @author Martin Slezáček <xsleza18@stud.fit.vutbr.cz>
 *
 * 3. projekt do predmetu IVS - kalkulačka. Vstupný bod programu, zobrazuje hlavné okno.
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
