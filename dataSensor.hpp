/*
 * dataSensor.hpp
 *
 *  Created on: 26 mars 2016
 *      Author: Djibril
 */

#ifndef DATASENSOR_HPP_
#define DATASENSOR_HPP_

#include <stdlib.h>
#include <malloc.h>

typedef enum {
	CONNECTED,
	UNCONNECTED,
	FAIL
}tSensorState;


class DataSensor
{
public:
	DataSensor(char* _name, char _ref);
	virtual ~DataSensor();

	static int getNbSensors();
	virtual char* getDataString()=0;

	int 			id;
	char*			name;
	char			ref;
	char*			error;

	//Data
	tSensorState	state;
	unsigned long	data_time;

protected:
	static int		_nbInstances;
	static int		_compteurId;
	char*			_data_string;

};

class GPS_DataSensor: public DataSensor
{
public:
	GPS_DataSensor();
	~GPS_DataSensor();

	virtual char* getDataString();

};


class Height_DataSensor: public DataSensor
{
public:
	Height_DataSensor();
	~Height_DataSensor();

	virtual char* getDataString();
};





#endif /* DATASENSOR_HPP_ */
