#include "c_flipr_data_byte_reader.h"


/**************************
*** UUID : Info
* 0xE302 : Contient les caractéristiques de la dernière mesure
* 0xF906 : Contient les informations du device
* 0x0006 : [Temperature : 2 octets ; PH : 2 octets ; ORP : 2 octets ; Conductivité : 2 octets ; Mode : 1 octet ; Identifiant : 2 octets ; Batterie : 2 octets ]
* 0x07C1 : [Identifiant logiciel : 2 octets ; Identifiant matériel : 2 octets ]
* 0x549D : [Niveau batterie : 2 octets ]
* 0x73B4 : Mode du device (0: veille ; 1: normal)
* 0x940d : Lancer acquisition (ecrire une valeur sur 8 bits)
*
***************************/

///
/// \brief c_flipr_data_byte_reader::c_flipr_data_byte_reader : Constructor
///
c_flipr_data_byte_reader::c_flipr_data_byte_reader()
{


}

///
/// \brief c_flipr_data_byte_reader::~c_flipr_data_byte_reader : Destructor
///
c_flipr_data_byte_reader::~c_flipr_data_byte_reader()
{

}

///
/// \brief c_flipr_data_byte_reader::f_convert_byte_data_to_string :
/// \param v_mode : A enum to select the mode to convert the data
/// \param v_data_to_convert : A QByteArray which contain flipr data and will be converted
/// \return A interger 0 = succes, 1 = error
///
int c_flipr_data_byte_reader::f_convert_byte_data_to_string(e_mode_flipr_data_reader v_mode, QByteArray v_data_to_convert, c_flipr *o_current_flipr_tested)
{

    if(v_mode == e_mode_flipr_data_reader::GET_ID_PAC)
    {
        f_convert_byte_data_for_id_pac(v_data_to_convert, o_current_flipr_tested);
        return 0;
    }

    if(v_mode == e_mode_flipr_data_reader::GET_DATA_BY_BLE)
    {

        f_convert_byte_data_for_ble_data(v_data_to_convert, o_current_flipr_tested);
        return 0;
    }

    if(v_mode == e_mode_flipr_data_reader::GET_DATA_BY_SIGFOX)
    {
        return 0;
    }

    return 1;
}

///
/// [WIP]
/// \brief c_flipr_data_byte_reader::f_read_flipr_data_on_serial
/// \param v_array_empty
/// \param v_port_name
/// \return
///
int c_flipr_data_byte_reader::f_read_flipr_data_on_serial(QByteArray* v_array_empty, QString v_port_name)
{

    //AT$I=11 : 41 54 24 49 3d 31 31
    //AT$I=10 : 41 54 24 49 3d 31 30
    QByteArray v_id_request = {"AT$I=11"};
    QByteArray v_pac_request = {"AT$I=10"};

    QSerialPort o_serialPort;
    o_serialPort.setPortName(v_port_name);
    o_serialPort.setParity(QSerialPort::NoParity);
    o_serialPort.setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
    o_serialPort.setStopBits(QSerialPort::OneStop);
    o_serialPort.setFlowControl(QSerialPort::NoFlowControl);
    o_serialPort.open(QIODevice::ReadWrite);

    if(o_serialPort.isOpen())
    {

        //ID
        //write
        o_serialPort.write(v_id_request.data());
        if( (o_serialPort.waitForBytesWritten(2000)))
        {
        }
        else
        {
            std::cout << "ERROR : request not send" << std::endl;
        }
        //read
        if (o_serialPort.waitForReadyRead(2000))
        {
            QByteArray flipr_id = o_serialPort.readAll();
            while (o_serialPort.waitForReadyRead(10))
            {
                flipr_id += o_serialPort.readAll();
            }
            v_array_empty = &flipr_id;
        }
        else
        {
            std::cout << "Flipr ID/PAC data not receive"<<endl;
            return 1;
        }


        //PAC
        //write
        o_serialPort.write(v_pac_request.data());
        if( (o_serialPort.waitForBytesWritten(2000)))
        {
        }
        else
        {
            std::cout << "ERROR : request not send" << std::endl;
        }
        //read
        if (o_serialPort.waitForReadyRead(2000))
        {
            QByteArray flipr_pac = o_serialPort.readAll();
            while (o_serialPort.waitForReadyRead(10))
            {
                flipr_pac += o_serialPort.readAll();
            }
            v_array_empty->append(':');
            v_array_empty->append(flipr_pac);

        }
        else
        {
            std::cout << "Flipr ID/PAC data not receive"<<endl;
            return 1;
        }

    }

    return 0;
}

//************** Private functions **************//

///
/// \brief c_flipr_data_byte_reader::f_convert_byte_data_for_id_pac A function which returns the ID/PAC of a flipr in a int
/// \param v_data_to_convert the byte array get from the request of id/pac
/// \return Integer 0 or 1; 0 = success, 1 = error
///
int c_flipr_data_byte_reader::f_convert_byte_data_for_id_pac(QByteArray v_data_to_convert, c_flipr *o_current_flipr)
{

    //traitement trame ?
    //si vide -> Erreur application  ?
    int v_flipr_id = 0;
    int v_flipr_pac = 0;
    bool ok;
    QString v_converted_data = "";

    int index = 0;
    while(v_data_to_convert.data()[index] != ':')
    {
        index++;
    }

    v_converted_data = v_data_to_convert.mid(0,index).toHex();
    v_flipr_id = v_converted_data.toInt(&ok,16);
    o_current_flipr->setV_id(v_flipr_id);

    v_converted_data = v_data_to_convert.mid(index,v_data_to_convert.length()).toHex();
    v_flipr_pac = v_converted_data.toInt(&ok,16);
    o_current_flipr->setV_pac(v_flipr_pac);

    return 0;
}

///
/// \brief c_flipr_data_byte_reader::f_convert_byte_data_for_ble_data
/// \param v_data_to_convert
/// \param o_current_flipr
/// \return
///
int c_flipr_data_byte_reader::f_convert_byte_data_for_ble_data(QByteArray v_data_to_convert, c_flipr* o_current_flipr)
{
    QString v_byte_temp;
    bool ok;

    //search of the measures part of the data
    // " 6c 56 32 fd 2f 8e--E3 02 : 00 06 : 81 1 : b8 7 : b3 1 : 64 3 : 1 : 1 0 : d0 6-- 65 ff 8e 21 1a"
    //reading by part of 2 bytes, when 'E3 02' and '00 06' spotted, take the 13 next bytes
    //
    for(int index = 0; index < v_data_to_convert.size(); index++)
    {

        if( v_data_to_convert.mid(index,4).toHex() == this->start_of_flipr_data_by_ble )
        {
            int index_state = index+3;
            double tmp_data = 0.0;
            //v_data = v_data_to_convert.mid((index+8,(index+8)+13));

            //**Data analyze**//
            //bytes 1+2 -> 2+1 -> b10 -> °C
            v_byte_temp = v_data_to_convert.mid(index_state+2,1).toHex()+v_data_to_convert.mid(index_state+1,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            tmp_data = (tmp_data*0.06);
            o_current_flipr->setV_flipr_temperature(tmp_data);

            //bytes 3+4 -> 4+3 -> b10 -> ph
            v_byte_temp = v_data_to_convert.mid(index_state+4,1).toHex()+v_data_to_convert.mid(index_state+3,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            tmp_data = (tmp_data/2);
            o_current_flipr->setV_flipr_ph(tmp_data);

            //bytes 5+6 -> 6+5 -> b10 -> orp
            v_byte_temp = v_data_to_convert.mid(index_state+6,1).toHex()+v_data_to_convert.mid(index_state+5,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            tmp_data = (tmp_data/2);
            o_current_flipr->setV_flipr_redox(tmp_data);

            //bytes 7+8 -> 8+7-> b10-> conductivite
            v_byte_temp = v_data_to_convert.mid(index_state+8,1).toHex()+v_data_to_convert.mid(index_state+7,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            o_current_flipr->setV_flipr_conductivity(tmp_data);

            //bytes 9 -> 9 -> b10 -> mode
            v_byte_temp = v_data_to_convert.mid(index_state+9,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            //o_crurrent_flipr->setV_flipr_mode;

            //bytes 10+11 -> 11+10 -> b10 -> id
            v_byte_temp = v_data_to_convert.mid(index_state+11,1).toHex()+v_data_to_convert.mid(index_state+10,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
            o_current_flipr->setV_id(tmp_data);

            //bytes 12+13 -> 13+12 -> b10 ->battery
            v_byte_temp = v_data_to_convert.mid(index_state+13,1).toHex()+v_data_to_convert.mid(index_state+12,1).toHex();
            tmp_data = v_byte_temp.toLong(&ok,16);
//            o_crurrent_flipr->setV_flirp_battery(tmp_data);

            tmp_data = -1;

            return 0;
        }
    }


    return 1;
}

///
/// Currently not implemented in the app
/// \brief c_flipr_data_byte_reader::f_convert_byte_data_for_sigfox_data
/// \param v_data_to_convert
/// \param o_current_flipr
/// \return A Int : 0 if success, 1 else
///


