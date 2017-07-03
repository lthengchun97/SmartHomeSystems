#include "unity.h"
#include "smarthome.h"
#include "mock_coordinate.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_smarthome_Expect_garage_door_open_given_range_below_5(void)
{
    GpsCoordinate gps;
    gps.x = 210;
    gps.y = 5300;
    getCoordinate_ExpectAndReturn(gps);
    turn_Expect(GARAGE_DOOR,ON);
    
    doSmartThings();
}

void test_smarthome_Expect_air_cond_and_heater_open_given_range_below_2000(void)
{
    GpsCoordinate gps;
    gps.x = 215;
    gps.y = 6000;
    getCoordinate_ExpectAndReturn(gps);
    turn_Expect(AIRCOND,ON);
    turn_Expect(WATER_HEATER,ON);
    
    doSmartThings();
}

void test_smarthome_Expect_garage_door_close_given_range_0(void)
{
    GpsCoordinate gps;
    gps.x = 215;
    gps.y = 5300;
    getCoordinate_ExpectAndReturn(gps);
    turn_Expect(GARAGE_DOOR,OFF);
    
    doSmartThings();
}

void test_smarthome_Expect_light_on_given_range_below_2(void)
{
    GpsCoordinate gps;
    gps.x = 198;
    gps.y = 5400;
    getCoordinate_ExpectAndReturn(gps);
    turn_Expect(KITCHEN_LIGHT,ON);
    
    doSmartThings();
}


