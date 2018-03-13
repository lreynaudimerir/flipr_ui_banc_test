#ifndef C_SIGFOX_DETECTION_H
#define C_SIGFOX_DETECTION_H

#include <iostream>

#include <QObject>

using namespace std;

class c_sigfox_detection
{
private:
    bool v_signal_ok;
public:
    c_sigfox_detection();
    bool f_using_python_function();
};

#endif // C_SIGFOX_DETECTION_H
