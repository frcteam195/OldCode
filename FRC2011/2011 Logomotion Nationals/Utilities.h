#ifndef UTILITIES_H_
#define UTILITIES_H_

DriverStationLCD::Line getLine(int number);

void dsprint(char* dataDescriptor, int data, DriverStationLCD *driver_station_LCD, int lineNumber = 1);
void dsprint(char* dataDescriptor, float data, DriverStationLCD *driver_station_LCD, int lineNumber = 1);
void dsprint(char* dataDescriptor, double data, DriverStationLCD *driver_station_LCD, int lineNumber = 1);
void dsprint(char* text, DriverStationLCD *driver_station_LCD,  int lineNumber = 1);

bool float_equality(float value1, float value2, float tolerance);

#endif /*UTILITIES_H_*/
