
#include "FuguMotorDriver.h"

FuguMotorDriver FuguDra;

void setup()
{
  Serial.begin(9600);
  /* add setup code here */

}

int i = 0;
int flag = 0;

void loop()
{
  FuguDra.move(i);
  delay(100);
  /* add main program code here */
  if(flag) i++;
  else i--;

  if(i == 127) flag = 0;
  else flag = 1;
}
