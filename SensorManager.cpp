/*
 * SensorManager.cpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#include <stddef.h>
#include "SensorManager.hpp"
#include <sys/time.h>

SensorManager::SensorManager(unsigned int logPeriod, unsigned int acqPeriod):
_trigger(false),
_log_period(logPeriod),
_acq_period(acqPeriod),
_log_temp_time(0),
_acq_temp_time(0),
error(MNGR_NO_ERROR)
{

}

SensorManager::~SensorManager()
{

}


void SensorManager::addLogger(DataLogger* _dataLogger)
{
	_loggers.push_back(_dataLogger);
}

void SensorManager::addSensor(DataSensor* _dataSensor) {
	_sensors.push_back(_dataSensor);
}

void SensorManager::setLogPeriod(unsigned int period) {
	_log_period=period;
}

void SensorManager::setUpdatePeriod(unsigned int period) {
	_acq_period=period;
}


bool SensorManager::init() {
	if(!initSensors()) return false;
	if(!initLoggers()) return false;
	return true;
}

bool SensorManager::update() {
	//update sensor values
	if(_acq_period==0) return true;

	if((get_time()-_acq_temp_time)>_acq_period){
		if(!this->acquire()) return false;
	}
	//If no record activity
	if(_log_period==0) return true;

	//update logger values
	if((get_time()-_log_temp_time)>_log_period){
		if(!this->log()) return false;
	}
	return true;
}

bool SensorManager::log() {
	_log_temp_time=get_time();
	for(std::vector<DataLogger*>::iterator logger = _loggers.begin(); logger!=_loggers.end();++logger){
		//each sensor is recored
		for(std::vector<DataSensor*>::iterator sensor = _sensors.begin(); sensor!=_sensors.end();++sensor){
			if(!(*logger)->record((*sensor)->dataFullStrSize,(*sensor)->getFullDataString())){
				error=MNGR_ERR_LOG;
				return false;
			}
		}
	}
	return true;
}

bool SensorManager::acquire() {
	_acq_temp_time=get_time();
	for(std::vector<DataSensor*>::iterator sensor = _sensors.begin(); sensor!=_sensors.end();++sensor){
		if(!(*sensor)->acquire()){
			error=MNGR_ERR_ACQ;
			return false;
		}
	}
	return true;
}

std::vector<DataSensor*> SensorManager::getListDataSensor() {
	return _sensors;
}

std::vector<DataLogger*> SensorManager::getListDataLogger() {
	return _loggers;
}

bool SensorManager::initLoggers() {
	//init loggers
	for(std::vector<DataLogger*>::iterator logger = _loggers.begin(); logger!=_loggers.end();++logger) {
		if(!(*logger)->initialize()){
			error=MNGR_ERR_LOGGER_INIT;
			return false;
		}
	}
	return true;
}

bool SensorManager::initSensors() {
	//init sensors
	for(std::vector<DataSensor*>::iterator sensor = _sensors.begin(); sensor != _sensors.end(); ++sensor) {
	    if(!(*sensor)->initialize()){
	    	error=MNGR_ERR_SENSOR_INIT;
	    	return false;
	    }
	}
	return true;
}

struct timeval tp;
unsigned int get_time(){
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

