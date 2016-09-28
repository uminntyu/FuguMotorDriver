
#include "FuguMotorDriver.h"


FuguMotorDriver::FuguMotorDriver( HardwareSerial *serial, int ch ) : ch( ch ), serial( serial )
{
    //FuguMotorDriver::ch = ch;
    //FuguMotorDriver::serial = serial;
    serial->begin(115200);
}

void FuguMotorDriver::move(int speed)
{
    if( speed == 0) {
        stop();
    }
    else if( speed < 0 ) {
        cw( speed );
    }
    else if( speed > 0 ) {
        ccw( speed );
    }

}

void FuguMotorDriver::cw( int speed )
{
    speed = abs( speed );
    if( speed > 120 ) speed = 120;
    
    serial->write( DRIVERON + ch );
	serial->write( FUGU_CW );
	serial->write( speed );
}

void FuguMotorDriver::ccw( int speed )
{
    speed = abs( speed );
    if( speed > 120 ) speed = 120;

    serial->write( DRIVERON + ch );
	serial->write( FUGU_CCW );
	serial->write( speed );
}

void FuguMotorDriver::stop()
{
	serial->write( DRIVEROFF + ch );
	serial->write( FUGU_SHUTDOWN );
	serial->write( 0x00 );
}
