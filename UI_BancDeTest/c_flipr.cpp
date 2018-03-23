#include "c_flipr.h"

///
/// \brief c_flipr::c_flipr : Constructor
///
c_flipr::c_flipr()
{
    this->v_id = 0000;
    this->v_card_state = 0;

    this->v_flipr_temperature = 0.0;
    this->v_flipr_conductivity =0.0;
    this->v_flipr_ph = 0.0;
    this->v_flipr_redox= 0.0;

    this->v_ble_is_ok = false;
    this->v_sigfox_is_ok = false;
}

//
///
/// \brief c_flipr::~c_flipr : Destructor
///
c_flipr::~c_flipr()
{

    cout << "Object is being deleted" << endl;

}


///[WIP]
/// \brief c_flipr::f_get_all_flipr_data
/// \return A list of QString with data of the Flipr
///
//QList<QString> c_flipr::f_get_all_flipr_data()
//{
//    QList<QString> v_list_flipr_data = QList<QString>();

//    return v_list_flipr_data;

//}


//Get/Set functions
//Card state
int c_flipr::getV_card_state() const
{
    return v_card_state;
}

void c_flipr::setV_card_state(int value)
{
    v_card_state = value;
}

//ID
int c_flipr::getV_id() const
{
    return v_id;
}

void c_flipr::setV_id(int value)
{
    v_id = value;
}

//PAC
int c_flipr::getV_pac() const
{
    return v_pac;
}

void c_flipr::setV_pac(int value)
{
    v_pac = value;
}

//Temperature
double c_flipr::getV_flipr_temperature() const
{
    return v_flipr_temperature;
}

void c_flipr::setV_flipr_temperature(double value)
{
    v_flipr_temperature = value;
}

//Conductivity
double c_flipr::getV_flipr_conductivity() const
{
    return v_flipr_conductivity;
}

void c_flipr::setV_flipr_conductivity(double value)
{
    v_flipr_conductivity = value;
}

//PH
double c_flipr::getV_flipr_ph() const
{
    return v_flipr_ph;
}

void c_flipr::setV_flipr_ph(double value)
{
    v_flipr_ph = value;
}

//Redox
double c_flipr::getV_flipr_redox() const
{
    return v_flipr_redox;
}

void c_flipr::setV_flipr_redox(double value)
{
    v_flipr_redox = value;
}

//BLE
bool c_flipr::getV_ble_is_ok() const
{
    return v_ble_is_ok;
}

void c_flipr::setV_ble_is_ok(bool value)
{
    v_ble_is_ok = value;
}

//Sigfox
bool c_flipr::getV_sigfox_is_ok() const
{
    return v_sigfox_is_ok;
}

void c_flipr::setV_sigfox_is_ok(bool value)
{
    v_sigfox_is_ok = value;
}

//Activation key
int c_flipr::getV_flipr_activation_key() const
{
    return v_flipr_activation_key;
}

void c_flipr::setV_flipr_activation_key(int value)
{
    v_flipr_activation_key = value;
}

