
#include "FuguMotorDriver.h"


FuguMotorDriver::FuguMotorDriver( int ch )
{
    FuguMotorDriver::ch = ch;
    Serial2.begin(115200);
}

void FuguMotorDriver::move(int speed)
{
    if( speed == 0) {
        FuguMotorDriver::stop()
    }
    else if( speed < 0 ) {
        FuguMotorDriver::cw( speed );
    }
    else if( speed > 0 ) {
            FuguMotorDriver::ccw( speed )
    }

}

void FuguMotorDriver::cw( int speed )
{(
    if( abs(speed) > 127 ) speed = 127;
    
    Serial2.write( DRIVERON + ch );
	Serial2.write( FUGU_CW );
	Serial2.write( speed );
}

void FuguMotorDriver::ccw( int speed )
{
    if( abs(speed) > 127) speed = 127;

    Serial2.write( DRIVERON + ch );
	Serial2.write( FUGU_CCW );
	Serial2.write( speed );
}

void FuguMotorDriver::stop()
{
	Serial2.write( DRIVEROFF + ch );
	Serial2.write( FUGU_SHUTDOWN );
	Serial2.write( 0x00 );
}
