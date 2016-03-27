/*
 * dataLogger.cpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#include "dataLogger.hpp"
#include <stdio.h>

#define SIZE_DATA_LOGGER_NAME		15

#define SD_LOGGER_NAME			"SD logger"
#define EEPROM_LOGGER_NAME		"EEPROM_logger"

#define DEBUG

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
#ifdef DEBUG
	printf("Debug : SD init\n");
#endif
	return true;
}

bool SD_Logger::open() {
#ifdef DEBUG
	printf("Debug : SD open\n");
#endif
	return true;
}

bool SD_Logger::close() {
#ifdef DEBUG
	printf("Debug : SD close\n");
#endif
	return true;
}

bool SD_Logger::record(unsigned int size_str, char* data) {
#ifdef DEBUG
	printf("Debug : SD record\n");
#endif
	return true;
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
#ifdef DEBUG
	printf("Debug : EEPROM init\n");
#endif
	return true;
}

bool EEPROM_Logger::open() {
#ifdef DEBUG
	printf("Debug : EEPROM open\n");
#endif
	return true;
}

bool EEPROM_Logger::close() {
#ifdef DEBUG
	printf("Debug : EEPROM close\n");
#endif
	return true;
}

bool EEPROM_Logger::record(unsigned int size_str, char* data) {
#ifdef DEBUG
	printf("Debug : EEPROM record\n");
#endif
	return true;
}




