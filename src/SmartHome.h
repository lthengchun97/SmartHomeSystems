#ifndef _SMARTHOME_H
#define _SMARTHOME_H
#include "coordinate.h"

GpsCoordinate getCoordinate();
int distance_function(GpsCoordinate coor,int x,int y);
void doSmartThings();
int square(int x);

#endif // _SMARTHOME_H
