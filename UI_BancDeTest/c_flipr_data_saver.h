#ifndef C_FLIPR_DATA_SAVER_H
#define C_FLIPR_DATA_SAVER_H

#include <iostream>
#include <stdio.h>

#include <QObject>
#include <QFile>
#include <QTextStream>

#include "c_flipr.h"


using namespace std;

class c_flipr_data_saver
{
private:
//open(FILENAME, std::ios_base::app);

public:
    c_flipr_data_saver();
    ~c_flipr_data_saver();

    bool f_save_current_flipr_data(QString fileDestination, QString v_flipr_data);
    QString f_get_current_flipr_data_to_csv(c_flipr o_current_flipr, QChar separator);


};

#endif // C_FLIPR_INFORMATION_SAVER_H
