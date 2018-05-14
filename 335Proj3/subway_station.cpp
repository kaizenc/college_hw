/*******************************************************************************
  Title          : subway_station.h
  Author         : Kaizen Castanos
  Created on     : May 14, 2018
  Description    : Fucntions for the subway_station class
  Purpose        : Used to store information about a subway_station
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
#include "subway_station.h"
using namespace std;

//holds a vector of entrances and the centroid location
subway_station::subway_station(unsigned long mask){
  line_mask = mask;
}

void subway_station::insert_entrance(subway_entrance e){
  entrances.push_back(e);
}

void subway_station::calculate_centroid(){
  double sum_lat = 0;
  double sum_long = 0;
  for(unsigned int i = 0;i<entrances.size();i++){
    sum_lat += entrances[i].getLat();
    sum_long += entrances[i].getLong();
  }
  latitude = sum_lat/(entrances.size());
  longitude = sum_long/(entrances.size());
}

