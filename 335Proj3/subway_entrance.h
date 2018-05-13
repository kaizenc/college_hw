/*******************************************************************************
  Title          : subway_entrance.h
  Author         : Kaizen Castanos
  Created on     : April 19, 2018
  Description    : The interface file for the subway_entrance class
  Purpose        : to be written
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __SUBWAY_ENTRANCE_H__
#define __SUBWAY_ENTRANCE_H__
#include <iostream>
#include <string>
using namespace std;

//simply unpack everything into variables
class subway_entrance{
private:
	//sample: 51,http://web.mta.info/nyct/service/,Parsons Blvd & Archer Ave at NE corner, POINT (-73.799784000399 40.70235300071414) ,E-J-Z
	int ObjectID;
	string URL;
	string name;
	double longitude;
	double latitude;
	vector<string> arr_lines;
	unsigned long line_mask;
	long convertToMask(string lines);
public:
	subway_entrance(const string & data);
	double getLong();
	double getLat();
	string getName();
	long getMask();
	int line_hash(string x);


};



#endif