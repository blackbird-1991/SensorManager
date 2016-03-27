/*
 * dataLogger.hpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#ifndef LOGGERS_DATALOGGER_HPP_
#define LOGGERS_DATALOGGER_HPP_

#include <stdlib.h>
#include <malloc.h>

typedef enum{
	LOG_INIT,
	LOG_LOGON,
	LOG_LOGOFF,
	LOG_FAIL
}tStateLogger;

typedef enum{
	LOG_NO_ERROR,
	LOG_INIT_FAIL,
	LOG_WRITE_FAIL
}tErrorLogger;


class DataLogger
{
public:
	DataLogger(char* _name);
	virtual ~DataLogger();

	virtual bool initialize()=0;
	virtual bool open()=0;
	virtual bool close()=0;
	virtual bool record(unsigned int size_str, char* data)=0;

	char* 			name;
	tStateLogger 	state;
	tErrorLogger	error;
	unsigned int 	nbRecords;
	bool			active;
};

class SD_Logger: public DataLogger
{
public:
	SD_Logger();
	~SD_Logger();

	virtual bool initialize();
	virtual bool open();
	virtual bool close();
	virtual bool record(unsigned int size_str, char* data);
};

class EEPROM_Logger: public DataLogger
{
public:
	EEPROM_Logger();
	~EEPROM_Logger();

	virtual bool initialize();
	virtual bool open();
	virtual bool close();
	virtual bool record(unsigned int size_str, char* data);
};



#endif /* LOGGERS_DATALOGGER_HPP_ */
