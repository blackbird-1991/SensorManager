/*
 * dataSensor.cpp
 *
 *  Created on: 26 mars 2016
 *      Author: Djibril
 */

#include "dataSensor.hpp"

#define SIZE_DATA_SENSOR_NAME		15
#define SIZE_DATA_SENSOR_ERROR		15

DataSensor::DataSensor()
{
	_compteurId++;
	_nbInstances++;
	id=_compteurId;

	name	= (char *)malloc(sizeof(char)*SIZE_DATA_SENSOR_NAME);
	name	= "no name";
	error	= (char *)malloc(sizeof(char)*SIZE_DATA_SENSOR_ERROR);
	error	= "no error";
	_data_string=NULL;

	state	= UNCONNECTED;
	data_time	= 0;
}

DataSensor::~DataSensor()
{
	_nbInstances--;
	free(name);
	free(error);
	free(_data_string);
}

int DataSensor::_compteurId=0;
int DataSensor::_nbInstances=0;

int DataSensor::getNbSensors()
{
	return _nbInstances;
}

/*
 *  GPS Sensor
 */
#define SIZE_GPS_DATA_SENSOR_STRING		20

GPS_DataSensor::GPS_DataSensor():
DataSensor()
{
	name	= "GPS";
	_data_string=(char*)malloc(sizeof(char*)*SIZE_GPS_DATA_SENSOR_STRING);
}

GPS_DataSensor::~GPS_DataSensor()
{

}

char* GPS_DataSensor::getDataString()
{
	return _data_string;
}
/*
 *  Height Sensor
 */
#define SIZE_HEIGHT_DATA_SENSOR_STRING	20

Height_DataSensor::Height_DataSensor():
DataSensor()
{
	name	= "Height Sensor";
	_data_string=(char*)malloc(sizeof(char*)*SIZE_HEIGHT_DATA_SENSOR_STRING);
}

Height_DataSensor::~Height_DataSensor()
{

}

char* Height_DataSensor::getDataString()
{
	return _data_string;
}
