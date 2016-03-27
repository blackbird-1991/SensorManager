/*
 * dataLogger.cpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#include "dataLogger.hpp"

#define SIZE_DATA_LOGGER_NAME		15

#define SD_LOGGER_NAME			"SD logger"
#define EEPROM_LOGGER_NAME		"EEPROM_logger"

DataLogger::DataLogger(char* _name):
state(LOG_INIT),
error(LOG_NO_ERROR),
nbRecords(0),
active(false)
{
	name	= (char*)malloc(sizeof(char*)*SIZE_DATA_LOGGER_NAME);
	name 	= _name;
}

DataLogger::~DataLogger() {
	free(name);
}

/*
* Logger for SD card
*/

SD_Logger::SD_Logger():
DataLogger(SD_LOGGER_NAME)
{
}

SD_Logger::~SD_Logger() {
}

bool SD_Logger::initialize() {
	return false;
}

bool SD_Logger::open() {
	return false;
}

bool SD_Logger::close() {
	return false;
}

bool SD_Logger::record(unsigned int size_str, char* data) {
	return false;
}

/*
* Logger for EEPROM
*/

EEPROM_Logger::EEPROM_Logger():
DataLogger(EEPROM_LOGGER_NAME)
{
}

EEPROM_Logger::~EEPROM_Logger() {
}

bool EEPROM_Logger::initialize() {
	return false;
}

bool EEPROM_Logger::open() {
	return false;
}

bool EEPROM_Logger::close() {
	return false;
}

bool EEPROM_Logger::record(unsigned int size_str, char* data) {
	return false;
}




