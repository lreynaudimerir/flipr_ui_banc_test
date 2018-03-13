#include "c_flipr.h"

///
/// \brief c_flipr::c_flipr : Constructor
///
c_flipr::c_flipr()
{
    this->v_id_pac = 0000;
    this->v_card_state = 0;

    this->v_flirp_temperature = 0.0;
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
QList<QString> c_flipr::f_get_all_flipr_data()
{
    QList<QString> v_list_flipr_data = QList<QString>();

}


//Get/Set functions
int c_flipr::getV_card_state() const
{
    return v_card_state;
}

void c_flipr::setV_card_state(int value)
{
    v_card_state = value;
}

int c_flipr::getV_id_pac() const
{
    return v_id_pac;
}

void c_flipr::setV_id_pac(int value)
{
    v_id_pac = value;
}

float c_flipr::getV_flirp_temperature() const
{
    return v_flirp_temperature;
}

void c_flipr::setV_flirp_temperature(float value)
{
    v_flirp_temperature = value;
}

float c_flipr::getV_flipr_conductivity() const
{
    return v_flipr_conductivity;
}

void c_flipr::setV_flipr_conductivity(float value)
{
    v_flipr_conductivity = value;
}

float c_flipr::getV_flipr_ph() const
{
    return v_flipr_ph;
}

void c_flipr::setV_flipr_ph(float value)
{
    v_flipr_ph = value;
}

float c_flipr::getV_flipr_redox() const
{
    return v_flipr_redox;
}

void c_flipr::setV_flipr_redox(float value)
{
    v_flipr_redox = value;
}

bool c_flipr::getV_ble_is_ok() const
{
    return v_ble_is_ok;
}

void c_flipr::setV_ble_is_ok(bool value)
{
    v_ble_is_ok = value;
}

bool c_flipr::getV_sigfox_is_ok() const
{
    return v_sigfox_is_ok;
}

void c_flipr::setV_sigfox_is_ok(bool value)
{
    v_sigfox_is_ok = value;
}


