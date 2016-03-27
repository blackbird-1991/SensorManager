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
}tStateSensor;

typedef enum {
	NO_ERROR,
	INIT_FAIL,
	OPEN_FAIL,
	COMM_FAIL,
	READ_FAIL,
}tErrorSensor;


class DataSensor
{
public:
	DataSensor(char* _name, char _ref,int _id,int _dataSize,int _dataFullSize);
	virtual ~DataSensor();
	virtual void	initialize()=0;
	static int 		getNbSensors();

	//Data ref
	const int 		id;
	char*			name;
	const char		ref;

	//Data params
	tStateSensor	state;
	tErrorSensor	error;
	unsigned long	data_time;

	//Data string
	virtual char* 	getDataString()=0;
	const int		dataStrSize;
	virtual char* 	getFullDataString()=0;
	const int		dataFullStrSize;

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
	virtual void	initialize();

	virtual char* 	getDataString();
	virtual char* 	getFullDataString();
};


class Height_DataSensor: public DataSensor
{
public:
	Height_DataSensor();
	~Height_DataSensor();
	virtual void	initialize();

	virtual char* 	getDataString();
	virtual char* 	getFullDataString();
};





#endif /* DATASENSOR_HPP_ */
