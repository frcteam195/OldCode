#include "WPILib.h"
#include <math.h>

DriverStationLCD::Line getLine(int number)
{
	switch(number)
	{
		case 1:
			return DriverStationLCD::kUser_Line1;
		break;
		case 2:
			return DriverStationLCD::kUser_Line2;
		break;
		case 3:
			return DriverStationLCD::kUser_Line3;
		break;
		case 4:
			return DriverStationLCD::kUser_Line4;
		break;
		case 5:
			return DriverStationLCD::kUser_Line5;
		break;
		case 6:
			return DriverStationLCD::kUser_Line6;
		break;
	}
	
	return DriverStationLCD::kUser_Line1;
}

void dsprint(char* dataDescriptor, int data, DriverStationLCD *driver_station_LCD, int lineNumber = 1)
{

	driver_station_LCD->PrintfLine(getLine(lineNumber), "%s : %i", dataDescriptor, data);
	driver_station_LCD->UpdateLCD();
}

void dsprint(char* dataDescriptor, float data, DriverStationLCD *driver_station_LCD, int lineNumber = 1)
{
	driver_station_LCD->PrintfLine(getLine(lineNumber), "%s : %f", dataDescriptor, data);
	driver_station_LCD->UpdateLCD();
}

void dsprint(char* dataDescriptor, double data, DriverStationLCD *driver_station_LCD, int lineNumber = 1)
{
	driver_station_LCD->PrintfLine(getLine(lineNumber), "%s : %d", dataDescriptor, data);
	driver_station_LCD->UpdateLCD();
}

void dsprint(char* text, DriverStationLCD *driver_station_LCD,  int lineNumber = 1)
{
	driver_station_LCD->PrintfLine(getLine(lineNumber), "%s", text);
	driver_station_LCD->UpdateLCD();
}

bool float_equality(float value1, float value2, float tolerance = 0.01)
{
	return (fabs (value1 - value2) < tolerance);
}
