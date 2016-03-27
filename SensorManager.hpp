/*
 * SensorManager.hpp
 *
 *  Created on: 27 mars 2016
 *      Author: Diallo
 */

#ifndef SENSORMANAGER_HPP_
#define SENSORMANAGER_HPP_

#include "loggers/dataLogger.hpp"
#include "sensors/dataSensor.hpp"
#include <vector>

typedef enum{
	MNGR_NO_ERROR,
	MNGR_ERR_SENSOR_LIST,
	MNGR_ERR_LOGGER_LIST,
	MNGR_ERR_SENSOR_INIT,
	MNGR_ERR_LOGGER_INIT,
	MNGR_ERR_ACQ,
	MNGR_ERR_LOG
}tErrorManager;

class SensorManager
{
public:
	SensorManager(unsigned int logPeriod, unsigned int acqPeriod);
	~SensorManager();

	void addLogger(DataLogger* _dataLogger);
	void addSensor(DataSensor* _dataSensor);

	// period=0 => auto disabled
	void setLogPeriod(unsigned int period);
	void setUpdatePeriod(unsigned int period);

	//main functions of the manager
	bool init();
	bool update();
	bool log();
	bool acquire();

	//list acces
	std::vector<DataSensor*>	getListDataSensor();
	std::vector<DataLogger*>	getListDataLogger();

	tErrorManager error;

private:
	bool 		initLoggers();
	bool 		initSensors();

	bool			_trigger;

	unsigned int	_log_period;  		//millis
	unsigned int	_log_temp_time;

	unsigned int	_acq_period;		//millis
	unsigned int	_acq_temp_time;

	//list of sensors and loggers
	std::vector<DataSensor* > 	_sensors;
	std::vector<DataLogger* >	_loggers;
};

unsigned int get_time();

#endif /* SENSORMANAGER_HPP_ */
