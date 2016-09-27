
#include <Arduino.h>
#include "FuguMotorDriver.h"

FuguMotorDriver fuguMD( &Serial1, 0 );

void setup()
{
    
}

void loop()
{
    fuguMD.move(100);
    delay(1000);
    fuguMD.move(-100);
    delay(1000);

}