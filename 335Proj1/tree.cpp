/*******************************************************************************
  Title          : tree.cpp
  Author         : Kaizen Castanos
  Created on     : February 26, 2018
  Description    : The code for the Tree class
  Purpose        : A tree container used to contain some data, specifically
                   from NYC's OpenData data set on trees. Also includes
                   functions to populate its variables with a string and a
                   function to send data to an output stream. 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
using namespace std;

Tree::Tree(const string & treedata){
	vector<string> data;
	bool in_an_entry = false;

	string word = ""; 
	for(int i = 0; i<treedata.length(); i++){
		if(treedata[i] == '"'){
			in_an_entry = !in_an_entry;
		}
		if(treedata[i] == ',' && !in_an_entry){
			data.push_back(word);
			word = "";
			continue;
		}
		word+=treedata[i];
	}
	data.push_back(word);

	spc_common = data[9]; 
	tree_id = stoi(data[0]); //0
	tree_dbh = stoi(data[3]); //3
	status = data[6];
	health = data[7];
	address = data[24];
	boroname = data[29];
	zipcode = stoi(data[25]); //25
	latitude = stod(data[37]); //37
	longitude = stod(data[38]); //38
}
ostream& operator<< (ostream & os, const Tree & t){
	if(os == cout){
		os << t.write_with_delim(", ") << "\n";
	}else{
		os << t.write() << "\n";
	}
	return os;
}
string Tree::write() const{
	return write_with_delim("	");
}
string Tree::write_with_delim(string delimiter) const{
	string result = "";
	string temp = "";
	
	temp = "spc_common: " + spc_common + delimiter;
	result += temp;
	temp = "tree_id: " + to_string(tree_id) + delimiter;
	result += temp;
	temp = "tree_dbh: " + to_string(tree_dbh) + delimiter;
	result += temp;
	temp = "status: " + status + delimiter;
	result += temp;
	temp = "health: " + health + delimiter;
	result += temp;
	temp = "address: " + address + delimiter;
	result += temp;
	temp = "boroname: " + boroname + delimiter;
	result += temp;
	temp = "zipcode: " + to_string(zipcode) + delimiter;
	result += temp;
	temp = "latitude: " + to_string(latitude) + delimiter;
	result += temp;
	temp = "longitude: " + to_string(longitude);
	result += temp;

	return result;
}