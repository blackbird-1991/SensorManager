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
	MNGR_ERR_LOGGER_INIT
}tErrorManager;

class SensorManager
{
public:
	SensorManager(unsigned int logPeriod, unsigned int acqPeriod);
	~SensorManager();

	const unsigned int clock_period;

	bool addLogger(DataLogger* _dataLogger);
	bool addSensor(DataSensor* _dataSensor);

	// period=0 => auto disabled
	void setLogPeriod(unsigned int period);
	void setUpdatePeriod(unsigned int period);

	//main functions of the manager
	bool init();
	bool update();
	bool log();
	bool acquire();

	//list acces
	std::vector<*DataSensor>	getListDataSensor();
	std::vector<*DataLogger>	getListDataLogger();

	tErrorManager error;

private:
	void 		initLoggers();
	void 		initSensors();

	bool			_trigger;

	unsigned int	_log_period;  		//millis
	unsigned int	_log_elapsed_time;  //time elapsed since the last record;

	unsigned int	_acq_period;		//millis
	unsigned int	_acq_elapsed_time;	//time elapsed since the last data acq;

	//list of sensors and loggers
	std::vector<DataSensor *> 	*_sensors;
	std::vector<DataLogger *>	*_loggers;
};



#endif /* SENSORMANAGER_HPP_ */
