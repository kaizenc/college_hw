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
#include "subway_entrance.h"
using namespace std;

//NOT DONE YET
subway_entrance::subway_entrance(const string & data){
	//sample: 1457,http://web.mta.info/nyct/service/,10th Ave & 207th St at NE corner,POINT( -73.91868100 40.86459900),1
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
	lines = data_arr[4];


	vector<double> coord_arr;

	int word_count = 0;
	for(int i = 0; i<data_arr[3].length();i++){
		if(data_arr[3][i] == ')') break;
		if(data_arr[3][i] == ' '){
			if (word_count != 0){
				coord_arr.push_back(stof(word));
			}
			word_count++;
			word = "";
			continue;
		}
		word+=data_arr[3][i];
	}
	coord_arr.push_back(stof(word)); //push_back last word

	longitude = coord_arr[0];
	latitude = coord_arr[1];



	//unsigned  long mask_k = 1UL << k; 
	//mask with a "1" in bit k
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

int main(){
	subway_entrance entrance("1457,http://web.mta.info/nyct/service/,10th Ave & 207th St at NE corner,POINT( -73.91868100 40.86459900),1");
	return 0;
}