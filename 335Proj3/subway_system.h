/*******************************************************************************
  Title          : subway_system.h
  Author         : Kaizen Castanos
  Created on     : April 19, 2018
  Description    : The interface file for the subway_system class
  Purpose        : to be written
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __SUBWAY_SYSTEM_H__
#define __SUBWAY_SYSTEM_H__
#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"


//contains a station hash table
//contains a line hash table
//contains subway station parent trees

//requires a bit mask
class subway_system{
private:
  vector<int> stations; //contains **indices** of stations
  vector<int> entrance_p_tree; //parent tree
  vector<subway_entrance> entrances; //actual entrances
  //station hashtable needs 1899 entries (4001, prime number greater than 1899*2, used for quad probing)

  int line_hash(string x);
  int station_hash(string x);
  bool is_station(subway_entrance &e1, subway_entrance &e2);
  void sanitize(string &x); //cleans up the string so that we get single spaces, lowercased, etc.
public:
  void insert_entrance(subway_entrance e);

  //commands
  void list_line_stations(string x);
  void list_all_stations();
  void nearest_station(double long_, double lat_);
};





#endif