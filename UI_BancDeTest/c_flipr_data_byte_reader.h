#ifndef C_FLIPR_DATA_BYTE_READER_H
#define C_FLIPR_DATA_BYTE_READER_H

#include <iostream>

#include <QObject>


using namespace std;

class c_flipr_data_byte_reader
{
public:
    c_flipr_data_byte_reader();
    ~c_flipr_data_byte_reader();

    bool f_request_flipr_id_pac();
    QByteArray f_get_flipr_id_pac();

    QString f_convert_byte_data_to_string(QString v_mode, QByteArray v_data_to_convert);

    bool f_ble_request_flipr_data();
    QByteArray f_ble_get_flipr_data();



private:



//signals:

//public slots:
};

#endif // C_FLIPR_DATA_BYTE_READER_H
