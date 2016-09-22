
#include "Arduino.h"

class FuguMotorDriver
{
private:
    enum STATESBYTE {
        DRIVEROFF = 0x80,
        DRIVERON = 0x90
    };

    enum DATABYTE {
        FUGU_SHUTDOWN = 0x00,
        FUGU_CW = 0x01,
        FUGU_CCW = 0x02
    };

    int ch;

    void cw( byte speed );
    void ccw( byte speed );
    void stop();

public:
    FuguMotorDriver( int ch );
    void move( byte speed );
    void stop();

}