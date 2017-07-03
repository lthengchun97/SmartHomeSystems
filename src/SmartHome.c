#include "smarthome.h"
#include "coordinate.h"
#include <math.h>
#include <stdio.h>

GpsCoordinate House = {
	200,
	5345,
};

GpsCoordinate OutsideGarage = {
	220,
	5300,
};

GpsCoordinate CenterGarage = {
	215,
	5300,
};

GpsCoordinate Kitchen = {
	196,
	5400,
};

int distance_function(GpsCoordinate coor,int x,int y)
{
  return sqrt(square(x-coor.x)+square(y-coor.y));
}

void doSmartThings()
{
  GpsCoordinate gps = getCoordinate();
  
  int range_kitchen = distance_function(gps,Kitchen.x,Kitchen.y);
  int range_house = distance_function(gps,House.x,House.y);
  int range_center_garage = distance_function(gps,CenterGarage.x,CenterGarage.y);
  
  if(range_kitchen <= 2)
  {
    turn(KITCHEN_LIGHT,ON);
  }
  else if(range_center_garage == 0)
  {
    turn(GARAGE_DOOR,OFF);
  }
  else if(range_center_garage <= 5)
  {
    turn(GARAGE_DOOR,ON);
  }
  
  else if(range_house <= 2000)
  {
    turn(AIRCOND, ON);
		turn(WATER_HEATER, ON);
  }
  else
    printf("INVALID");
}

int square(int x){
	return x*x;
}
