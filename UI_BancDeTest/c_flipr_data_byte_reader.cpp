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
/// \return A c_flipr with the data got from the selected mode
///
c_flipr c_flipr_data_byte_reader::f_convert_byte_data_to_string(e_mode_flipr_data_reader v_mode, QByteArray v_data_to_convert)
{
    c_flipr* o_current_flipr_tested = new c_flipr();


    if(v_mode == e_mode_flipr_data_reader::GET_ID_PAC)
    {
        o_current_flipr_tested->setV_id_pac(f_convert_byte_data_for_id_pac(v_data_to_convert));
    }

    if(v_mode == e_mode_flipr_data_reader::GET_DATA_BY_BLE)
    {

        f_convert_byte_data_for_ble_data(v_data_to_convert, o_current_flipr_tested);
        return *o_current_flipr_tested;
    }

    if(v_mode == e_mode_flipr_data_reader::GET_DATA_BY_SIGFOX)
    {
        return *o_current_flipr_tested;

    }

    return *o_current_flipr_tested;
}

//************** Private functions **************//

///
/// \brief c_flipr_data_byte_reader::f_convert_byte_data_for_id_pac
/// \param v_data_to_convert
/// \return
///
int c_flipr_data_byte_reader::f_convert_byte_data_for_id_pac(QByteArray v_data_to_convert)
{
    int v_flipr_idpac = 0;
    bool ok;
    QString v_converted_data = "";
    v_converted_data = QByteArray::fromHex(v_data_to_convert);

    //  v_flipr_idpac = v_converted_data.toInt(&ok,10);
    v_flipr_idpac = v_converted_data.toInt(&ok,16);


    return v_flipr_idpac;
}


int c_flipr_data_byte_reader::f_convert_byte_data_for_ble_data(QByteArray v_data_to_convert, c_flipr* o_crurrent_flipr)
{
    //change the return type to a int, and edit the current_flipr instead of returning it


    QByteArray v_data;
    //v_data = QByteArray::fromRawData(v_data_to_convert);
    v_data = v_data_to_convert.toHex();

    int size_byte_array = v_data.size();

    //search of the measures part of the data
    for(int index = 0; index < size_byte_array; index+=2)
    {
        if(v_data_to_convert.data()[index] == NULL)
        {
            cout << "ERROR : end of byte array already reach." << endl;
            return 1;
        }

        if( v_data_to_convert.mid(index,8).data() == this->start_of_flipr_data_by_ble )
        {
            return 0;
        }
    }
    // " 6c 56 32 fd 2f 8e--E3 02 : 00 06 : 81 1 : b8 7 : b3 1 : 64 3 : 1 : 1 0 : d0 6-- 65 ff 8e 21 1a"
    //reading by part of 2 bytes, when 'E3 02' and '00 06' spotted, take the 13 next bytes
    //


    return 1;
}


int c_flipr_data_byte_reader::f_convert_byte_data_for_sigfox_data(QByteArray v_data_to_convert, c_flipr* v_crurrent_flipr)
{

     return 1;
}

