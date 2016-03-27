/*
 * main.cpp
 *
 *  Created on: 26 mars 2016
 *      Author: Djibril
 */
#include <stdio.h>
#include "dataSensor.hpp"



int main(void)
{
	printf("Test de l'architecture de gestion des capteurs!\n");

	GPS_DataSensor* gps;
	gps=new GPS_DataSensor();

	Height_DataSensor* height;
	height=new Height_DataSensor();
	printf("nb capteurs : %i\n",DataSensor::getNbSensors());
	printf("name : %s  id : %i\n",gps->name,gps->id);
	printf("name : %s  id : %i\n",height->name,height->id);

	return 0;
}


