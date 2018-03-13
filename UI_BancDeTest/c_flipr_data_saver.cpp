#include "c_flipr_data_saver.h"

///
/// \brief c_flipr_data_saver::c_flipr_data_saver : Constructor
///
c_flipr_data_saver::c_flipr_data_saver()
{
    //
}

///
/// \brief c_flipr_data_saver::~c_flipr_data_saver : Destructor
///
c_flipr_data_saver::~c_flipr_data_saver()
{
    cout<<"Object has been deleted"<<endl;
}

///
/// \brief c_flipr_data_saver::f_save_current_flipr_data : Funtion to save the current flipr data into a csv file
/// \param fileDestination : A QString with the name of the file use to save flipr data
/// \param v_flipr_data : A QString of flipr data with the separtor
/// \return A boolean : true if success, false else
///
bool c_flipr_data_saver::f_save_current_flipr_data(QString fileDestination, QString v_flipr_data)
{
    QFile v_file_to_save(fileDestination);
    if (v_file_to_save.open(QIODevice::WriteOnly | QIODevice::Append)) {

        QTextStream v_out(&v_file_to_save);
        v_out<<v_flipr_data;

        v_out.flush();

        return true;
    }

    return false;
}

///
/// \brief c_flipr_data_saver::f_get_current_flipr_data_to_csv : Function to produce a QString with the data of a flipr with the separator for the csv format
/// \param o_current_flipr :: A c_flipr, the current flipr on the benchmark
/// \param separator : A QChar with the separator use in the csv format to split the flipr data
/// \return A QString with the data of the flipr split with the separator
///
QString c_flipr_data_saver::f_get_current_flipr_data_to_csv(c_flipr o_current_flipr, QChar separator=';')
{
    QString v_flipr_data_string = "";

    v_flipr_data_string.append(o_current_flipr.getV_id_pac() + separator+
                                o_current_flipr.getV_flirp_temperature() + separator+
                                o_current_flipr.getV_flipr_conductivity() + separator+
                                o_current_flipr.getV_flipr_ph() + separator+
                                o_current_flipr.getV_flipr_redox() + separator+
                                "BLE is ok = " + o_current_flipr.getV_ble_is_ok() + separator+
                                "Sigfox is ok = " +o_current_flipr.getV_sigfox_is_ok() + separator+"\n");


    return v_flipr_data_string;
}
