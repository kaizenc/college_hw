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
	bool empty = true;
	unsigned long line_mask;
	double longitude;
	double latitude;
	vector<subway_entrance> entrances;
public:
	subway_station();
	subway_station(unsigned long mask);
	void insert_entrance(subway_entrance e);
	vector<subway_entrance> getEntrances();
	void calculate_centroid();
	double getLong();
	double getLat();

	string getName();

	bool isEmpty();
};



#endif