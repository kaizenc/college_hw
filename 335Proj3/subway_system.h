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

//contains a station hash table
//contains a line hash table
//contains subway station parent trees

//requires a bit mask
//real quick: 1234567ABCDEFGJLMNQRSWZ
//in ascii, it's 48-55, then 65 to 71, then 74, 76, 77, 78, 81, 82, 83, 87, 90
//sub 48, it's 0-7, 17 to 23, 26, 28, 29, 30, 33, 34, 35, 39, 40
//mod 40
//Hash it to 23 slots
class subway_system{
private:
  subway_station *station_hash[100];
  subway_entrance *entrances[100];
  subway_line *line_hash[100];
public:
  //
};





#endif