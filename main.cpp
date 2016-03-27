/*
 * main.cpp
 *
 *  Created on: 26 mars 2016
 *      Author: Djibril
 */
#include <stdio.h>
#include <windows.h>

#include "sensors/dataSensor.hpp"
#include "loggers/dataLogger.hpp"
#include "SensorManager.hpp"

int main(void)
{
	printf("Test de l'architecture de gestion des capteurs!\n");

	//Sensors
	GPS_DataSensor* gps;
	gps=new GPS_DataSensor();
	Height_DataSensor* height;
	height=new Height_DataSensor();

	//Loggers
	SD_Logger* sdlogger;
	sdlogger=new SD_Logger();
	EEPROM_Logger* eepromlogger;
	eepromlogger=new EEPROM_Logger();

	//Manager
	SensorManager*	manager;
	manager=new SensorManager(500,500);
	manager->init();

	manager->addLogger(sdlogger);
	manager->addSensor(gps);

	while(true){
		manager->update();
		Sleep(100);
	}

	return 0;
}


