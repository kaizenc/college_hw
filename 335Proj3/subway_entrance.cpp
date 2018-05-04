/*******************************************************************************
  Title          : subway_entrance.cpp
  Author         : Kaizen Castanos
  Created on     : May 3, 2018
  Description    : Functions for the subway_entrance class
  Purpose        : to be written
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

//NOT DONE YET
subway_entrance::subway_entrance(const string & data){
	//sample: 51,http://web.mta.info/nyct/service/,Parsons Blvd & Archer Ave at NE corner, POINT (-73.799784000399 40.70235300071414) ,E-J-Z
	vector<string> data_arr;
	bool in_an_entry = false;

	string word = ""; 
	for(int i = 0; i<data.length(); i++){
		if(data[i] == '"'){ //ensures strings aren't separated by "," inside values
			in_an_entry = !in_an_entry;
		}
		if(data[i] == ',' && !in_an_entry){
			data_arr.push_back(word);
			word = "";
			continue;
		}
		word+=data[i];
	}
	data_arr.push_back(word); //pushes back last word

	ObjectID = stoi(data_arr[0]);
	URL = data_arr[1];
	name = data_arr[2];
	//assign variables here
	/**

	double longitude;
	double latitude;
	unsigned short line_mask;
	**/
}
double subway_entrance::getLong(){
	return longitude;
}
double subway_entrance::getLat(){
	return latitude;
}
string subway_entrance::getName(){
	return name;
}
short subway_entrance::getMask(){
	return line_mask;
}
