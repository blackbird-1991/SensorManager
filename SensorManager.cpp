/*
 * SensorManager.cpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#include <stddef.h>


SensorManager::SensorManager(unsigned int logPeriod, unsigned int acqPeriod):
_trigger(false),
_log_period(logPeriod),
_acq_period(acqPeriod),
_log_elapsed_time(0),
_acq_elapsed_time(0),
error(MNGR_NO_ERROR)
{
	_sensors = new std::vector<DataLogger *>();
	_loggers = new std::vector<DataLogger *>();

}

SensorManager::~SensorManager() {
	delete _sensors;
	delete _loggers;
}


bool SensorManager::addLogger(DataLogger* _dataLogger) {
	if(_loggers!=NULL){
		_loggers->push_back(_dataLogger);
		return true;
	}
	else{
		error=MNGR_ERR_LOGGER_LIST;
		return false;
	}
}

bool SensorManager::addSensor(DataSensor* _dataSensor) {
	if(_sensors!=NULL){
		_sensors->push_back(_dataSensor);
		return true;
	}
	else{
		error=MNGR_ERR_SENSOR_LIST;
		return false;
	}
}

void SensorManager::setLogPeriod(unsigned int period) {
	_log_period=period;
}

void SensorManager::setUpdatePeriod(unsigned int period) {
	_acq_period=period;
}

bool SensorManager::init() {
	//init sensors
	for(std::vector<*DataSensor>::iterator it = _sensors->begin(); it != _sensors->end(); ++it) {
	    DataSensor* sensor=(DataSensor*)it;
	    if(!sensor->initialize()){
	    	error=MNGR_ERR_SENSOR_INIT;
	    	return false;
	    }
	}
	//init loggers
	for(std::vector<*DataLogger>::iterator it = _loggers->begin(); it!=_loggers->end();++it) {
		DataLogger* logger=(DataLogger*)it;
		if(!logger->initialize()){
			error=MNGR_ERR_LOGGER_INIT;
			return false;
		}
	}
	return true;
}

bool SensorManager::update() {
}

void SensorManager::log() {
}

void SensorManager::acquire() {
}

std::vector<*DataSensor> SensorManager::getListDataSensor() {
}

std::vector<*DataLogger> SensorManager::getListDataLogger() {
}

void SensorManager::initLoggers() {
}

void SensorManager::initSensors() {
}



