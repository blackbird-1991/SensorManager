/*
 * dataSensor.cpp
 *
 *  Created on: 26 mars 2016
 *      Author: Djibril
 */

#include "dataSensor.hpp"
#include <stdio.h>

#define DATA_SENSOR_GPS_NAME	"GPS sensor"
#define DATA_SENSOR_GPS_REF		0x0A

#define DATA_SENSOR_HEIGHT_NAME	"Height sensor"
#define DATA_SENSOR_HEIGHT_REF	0x0B

#define SIZE_DATA_SENSOR_NAME		15

#define DEBUG

DataSensor::DataSensor(char* _name, char _ref,int _id,int _dataSize,int _dataFullSize):
id(_id),
ref(_ref),
dataStrSize(_dataSize),
dataFullStrSize(_dataFullSize)
{
	_compteurId++;
	_nbInstances++;
	//id=_compteurId;

	name	= (char *)malloc(sizeof(char)*SIZE_DATA_SENSOR_NAME);
	name	= _name;
	error	= SENSOR_NO_ERROR;
	_data_string=NULL;

	state	= UNCONNECTED;
	data_time	= 0;
}

DataSensor::~DataSensor()
{
	_nbInstances--;
	free(_data_string);
	free(name);
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
DataSensor(DATA_SENSOR_GPS_NAME,DATA_SENSOR_GPS_REF,_compteurId,
		SIZE_GPS_DATA_SENSOR_STRING,SIZE_GPS_DATA_SENSOR_STRING)
{
	_data_string=(char*)malloc(sizeof(char*)*SIZE_GPS_DATA_SENSOR_STRING);
}

GPS_DataSensor::~GPS_DataSensor()
{

}

bool GPS_DataSensor::initialize()
{
#ifdef DEBUG
	printf("Debug : GPS init\n");
#endif
	return true;
}

bool GPS_DataSensor::acquire()
{
#ifdef DEBUG
	printf("Debug : GPS acquire\n");
#endif
	return true;
}

char* GPS_DataSensor::getDataString()
{
	return _data_string;
}

char* GPS_DataSensor::getFullDataString()
{
	return _data_string;
}

/*
 *  Height Sensor
 */
#define SIZE_HEIGHT_DATA_SENSOR_STRING	20

Height_DataSensor::Height_DataSensor():
DataSensor(DATA_SENSOR_HEIGHT_NAME,DATA_SENSOR_HEIGHT_REF,_compteurId,
		SIZE_GPS_DATA_SENSOR_STRING,SIZE_GPS_DATA_SENSOR_STRING)
{
	_data_string=(char*)malloc(sizeof(char*)*SIZE_HEIGHT_DATA_SENSOR_STRING);
}

Height_DataSensor::~Height_DataSensor()
{

}

bool Height_DataSensor::initialize()
{
#ifdef DEBUG
	printf("Debug : Height sensor init\n");
#endif
	return true;
}

bool Height_DataSensor::acquire()
{
#ifdef DEBUG
	printf("Debug : Height sensor acquire\n");
#endif
	return true;
}

char* Height_DataSensor::getDataString()
{
	return _data_string;
}

char* Height_DataSensor::getFullDataString()
{
	return _data_string;
}
