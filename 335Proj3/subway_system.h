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
#include "subway_entrance.h"
#include "haversine.cpp"

//contains a station hash table
//contains a line hash table
//contains subway station parent trees

//requires a bit mask
class subway_system{
private:
  int *stations //contains indices of stations
  int *entrance_p_tree; //parent tree
  subway_entrance *entrances; //actual entrances
  subway_line *line_hash;
public:
  int hash_line(string x);
  void insert_entrance(subway_entrance)
  //
};





#endif