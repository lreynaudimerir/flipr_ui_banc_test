#ifndef C_FLIPR_H
#define C_FLIPR_H

#include <iostream>
#include <QObject>


using namespace std;

class c_flipr
{
private:
    int v_id_pac;
    int v_card_state;

    float v_flirp_temperature;
    float v_flipr_conductivity;
    float v_flipr_ph;
    float v_flipr_redox;

    bool v_ble_is_ok;
    bool v_sigfox_is_ok;

public:
    c_flipr();
    ~c_flipr();

    QList<QString> f_get_all_flipr_data();

    //Get/Set functions
    int getV_card_state() const;
    void setV_card_state(int value);
    int getV_id_pac() const;
    void setV_id_pac(int value);
    float getV_flirp_temperature() const;
    void setV_flirp_temperature(float value);
    float getV_flipr_conductivity() const;
    void setV_flipr_conductivity(float value);
    float getV_flipr_ph() const;
    void setV_flipr_ph(float value);
    float getV_flipr_redox() const;
    void setV_flipr_redox(float value);
    bool getV_ble_is_ok() const;
    void setV_ble_is_ok(bool value);
    bool getV_sigfox_is_ok() const;
    void setV_sigfox_is_ok(bool value);
};

#endif // C_FLIPR_H
