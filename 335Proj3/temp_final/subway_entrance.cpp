/*******************************************************************************
  Title          : subway_entrance.cpp
  Author         : Kaizen Castanos
  Created on     : May 3, 2018
  Description    : Functions for the subway_entrance class
  Purpose        : Used to store information about all subway_entrance, uses
                   several hash tables to store and retreive data. Also contains
                   functions used to respond to commands
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
using namespace std;

//Constructor
subway_entrance::subway_entrance(const string & data){
	vector<string> data_arr;
	bool in_an_entry = false;

	string word = ""; 
	for(unsigned int i = 0; i<data.length(); i++){
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


	vector<double> coord_arr;
	int word_count = 0;
	for(unsigned int i = 0; i<data_arr[3].length();i++){
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

	convertToMask(data_arr[4]);
}

void subway_entrance::convertToMask(string lines){
	string word = "";
	for(unsigned int i = 0; i<lines.length(); i++){		
		if(lines[i] == '-'){
			arr_lines.push_back(word);
			word = "";
			continue;
		}
		word+=lines[i];
	}
	arr_lines.push_back(word);

	unsigned long finalmask = 0;
	for(unsigned int i = 0; i < arr_lines.size();i++){
		int k = line_hash(arr_lines[i]);
		unsigned long mask_k = 1UL << k; 
		finalmask = finalmask | mask_k;
	}
	line_mask = finalmask;
}

int subway_entrance::line_hash(string x){
	//horner's method of encoding, then simple modulo hashing
	int hashval = 0;
	for(unsigned int i = 0;i < x.length();i++){
		hashval = x[i] + 33*hashval;
	}
	return hashval%51;
}

//Get Functions
double subway_entrance::getLong(){
	return longitude;
}
double subway_entrance::getLat(){
	return latitude;
}
string subway_entrance::getName(){
	return name;
}
long subway_entrance::getMask(){
	return line_mask;
}
vector<string> subway_entrance::getLines(){
	return arr_lines;
}

