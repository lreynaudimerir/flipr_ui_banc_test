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
    int v_id;
    int v_pac;
    int v_card_state;

    //Capteurs
    double v_flipr_temperature;
    double v_flipr_conductivity;
    double v_flipr_ph;
    double v_flipr_redox;

    //Activation key
    int v_flipr_activation_key;

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
    int getV_id() const;
    void setV_id(int value);
    int getV_pac() const;
    void setV_pac(int value);
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
    int getV_flipr_activation_key() const;
    void setV_flipr_activation_key(int value);
};

#endif // C_FLIPR_H
