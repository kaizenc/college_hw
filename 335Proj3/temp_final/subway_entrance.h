/*******************************************************************************
  Title          : subway_entrance.h
  Author         : Kaizen Castanos
  Created on     : April 19, 2018
  Description    : The interface file for the subway_entrance class
  Purpose        : Used to store information about a subway_entrance, also includes
  								 the line hash function and its mask
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
	void convertToMask(string lines);
	int line_hash(string x);
public:
	//Subway Entrance Constructor
	subway_entrance(const string & data);

	/** getLong(): returns the longitude of this subway entrance
		* @return double 	The longitude of this subway entrance
		*/
	double getLong();

	/** getLat(): returns the latitude of this subway entrance
		* @return double 	The latitude of this subway entrance
		*/
	double getLat();

	/** getLat(): returns the name of this subway entrance
		* @return std::string 	The name of this subway entrance
		*/
	string getName();

	/** getMask(): returns a long to be used as a bitmask, formed
		* 	using a hash function for the lines
		* @return long 	A bitmask representing the lines of this entrance
		*/
	long getMask();

	/** getLines(): returns a vector containing the lines of this entrance
		* @return vector<std::string> 	A vector containing the lines of this entrance
		*/
	vector<string> getLines();
};



#endif