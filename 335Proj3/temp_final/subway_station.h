/*******************************************************************************
  Title          : subway_station.h
  Author         : Kaizen Castanos
  Created on     : May 13, 2018
  Description    : The interface file for the subway_station class
  Purpose        : Used to store information about a subway_station, also includes
  								 the line hash function and its mask
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __SUBWAY_STATION_H__
#define __SUBWAY_STATION_H__
#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
using namespace std;

//holds a vector of entrances and the centroid location
class subway_station{
private:
	double longitude;
	double latitude;
	vector<subway_entrance> entrances;
public:
	void insert_entrance();
	vector<subway_entrance> getEntrances();
	double getLong();
	double getLat();
};



#endif