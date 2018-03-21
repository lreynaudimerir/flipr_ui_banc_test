#ifndef C_FLIPR_H
#define C_FLIPR_H

#include <iostream>

using namespace std;

///
/// \brief The c_flipr class
///
class c_flipr
{
private:
    //Information carte
    int v_id_pac;
    int v_card_state;

    //Capteurs
    double v_flipr_temperature;
    double v_flipr_conductivity;
    double v_flipr_ph;
    double v_flipr_redox;

    //Systèmes de communication
    bool v_ble_is_ok;
    bool v_sigfox_is_ok;

public:
    c_flipr();
    ~c_flipr();

    //QList<QString> f_get_all_flipr_data();

    //Get/Set functions
    int getV_card_state() const;
    void setV_card_state(int value);
    int getV_id_pac() const;
    void setV_id_pac(int value);
    double getV_flipr_temperature() const;
    void setV_flipr_temperature(double value);
    double getV_flipr_conductivity() const;
    void setV_flipr_conductivity(double value);
    double getV_flipr_ph() const;
    void setV_flipr_ph(double value);
    double getV_flipr_redox() const;
    void setV_flipr_redox(double value);
    bool getV_ble_is_ok() const;
    void setV_ble_is_ok(bool value);
    bool getV_sigfox_is_ok() const;
    void setV_sigfox_is_ok(bool value);
};

#endif // C_FLIPR_H
