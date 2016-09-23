
#include "FuguMotorDriver.h"

FuguMotorDriver( HardwareSerial *hardwareSerial, int ch )
{
    FuguMotorDriver::ch = ch;
    serial = hardwareSerial;
    serial.begin( 115200 );
}

void FuguMotorDriver::move(int speed)
{
    if( speed == 0) {
        FuguMotorDriver::stop();
    }
    else if( speed < 0 ) {
        FuguMotorDriver::cw( speed );
    }
    else if( speed > 0 ) {
            FuguMotorDriver::ccw( speed );
    }

}

void FuguMotorDriver::cw( int speed )
{
    if( abs(speed) > 127 ) speed = 127;
    
    Serial1.write( DRIVERON + ch );
	Serial1.write( FUGU_CW );
	Serial1.write( speed );
}

void FuguMotorDriver::ccw( int speed )
{
    if( abs(speed) > 127) speed = 127;

    Serial1.write( DRIVERON + ch );
	Serial1.write( FUGU_CCW );
	Serial1.write( speed );
}

void FuguMotorDriver::stop()
{
	Serial1.write( DRIVEROFF + ch );
	Serial1.write( FUGU_SHUTDOWN );
	Serial1.write( 0x00 );
}
