#include "mainwindow.h"
#include <QApplication>

#include "c_flipr.h"
#include "c_flipr_data_saver.h"
#include "c_flipr_data_byte_reader.h"


int test_functions();
int print_byte_array(QByteArray trame);


int main(int argc, char *argv[])
{

    std::cout << "START TEST FUNCTIONS" << std::endl;
    test_functions();
    std::cout << "END TEST FUNCTIONS" << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
//    w.show();

return 0;
//    return a.exec();
}

int print_byte_array(QByteArray trame){

    trame = "0";
    return 0;
}

int test_functions()
{

    QByteArray trame_test;
    trame_test[0] = 0x00;
    trame_test[1] = 0x00;
    trame_test[2] = 0x03;
    trame_test[3] = 0xe3;
    trame_test[4] = 0x02;
    trame_test[5] = 0x00;
    trame_test[6] = 0x06;
    trame_test[7] = 0x81;
    trame_test[8] = 0x01;
    trame_test[9] = 0xb8;
    trame_test[10] = 0x07;
    trame_test[11] = 0xb3;
    trame_test[12] = 0x01;
    trame_test[13] = 0x64;
    trame_test[14] = 0x03;
    trame_test[15] = 0x01;
    trame_test[16] = 0x01;
    trame_test[17] = 0x00;
    trame_test[18] = 0xd0;
    trame_test[19] = 0x06;
    trame_test[20] = 0x1d;
    trame_test[21] = 0xff;


    //flipr tested
    c_flipr* current_f = new c_flipr();

    c_flipr_data_byte_reader flipr_reader;

    *current_f = flipr_reader.f_convert_byte_data_to_string(e_mode_flipr_data_reader::GET_DATA_BY_BLE,trame_test);


    delete(current_f);
    delete(&flipr_reader);

    return 0;

}

