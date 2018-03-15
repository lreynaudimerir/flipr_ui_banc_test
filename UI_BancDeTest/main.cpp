#include "mainwindow.h"
#include <QApplication>

#include "c_flipr.h"
#include "c_flipr_data_saver.h"
#include "c_flipr_data_byte_reader.h"


int test_functions();



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    test_functions();

    return a.exec();
}

int test_functions()
{

    string data_t = "0x00 0x00 0x03 0xe3 0x02 0x00 0x06 0x76 0xec 0x18 0xc3 0x31 0x0a 0xf1 0xcc 0x99 0x6d 0x5b";
    QByteArray trame_test = QByteArray::fromStdString(data_t);


    //flipr tested
    c_flipr* current_f = new c_flipr();

    //functions_need to be tested

    delete(current_f);

    return 0;

}

