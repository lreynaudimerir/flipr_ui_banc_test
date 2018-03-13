#include "mainwindow.h"
#include <QApplication>

#include "c_flipr.h"
#include "c_flipr_data_saver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


