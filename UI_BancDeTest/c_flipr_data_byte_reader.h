#ifndef C_FLIPR_DATA_BYTE_READER_H
#define C_FLIPR_DATA_BYTE_READER_H

#include <iostream>

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "e_mode_flipr_data_reader.h"
#include "c_flipr.h"


using namespace std;

///
/// \brief The c_flipr_data_byte_reader class
///
class c_flipr_data_byte_reader
{

public:
    explicit c_flipr_data_byte_reader();
    ~c_flipr_data_byte_reader();

    int f_convert_byte_data_to_string(e_mode_flipr_data_reader v_mode, QByteArray v_data_to_convert, c_flipr *o_current_flipr_tested);

    int f_request_flipr_id_pac();
    QByteArray f_get_flipr_id_pac();

    int f_ble_request_flipr_data();
    QByteArray f_ble_get_flipr_data();

    int f_read_flipr_data_on_serial(QByteArray* v_array_empty, QString v_port_name);


private:
    const QString start_of_flipr_data_by_ble = "e3020006";

    int f_convert_byte_data_for_id_pac(QByteArray v_data_to_convert, c_flipr *o_current_flipr);

    int f_convert_byte_data_for_ble_data(QByteArray v_data_to_convert, c_flipr* o_current_flipr);

    int f_convert_byte_data_for_sigfox_data(QByteArray v_data_to_convert, c_flipr* o_current_flipr);



signals:

//public slots:
};

#endif // C_FLIPR_DATA_BYTE_READER_H
