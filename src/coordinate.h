#ifndef _COORDINATE_H
#define _COORDINATE_H

typedef struct GpsCoordinate GpsCoordinate;

struct GpsCoordinate {
  float x;
  float y;   
};
 
typedef enum {
  GARAGE_DOOR,
  KITCHEN_LIGHT,
  AIRCOND,
  WATER_HEATER,
} Device;

typedef enum {
  OFF,
  ON
} State;

GpsCoordinate getCoordinate();
void turn(Device device, State state);

#endif // _COORDINATE_H
