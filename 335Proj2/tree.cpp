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

//Constructors
Tree::Tree(){
	//
}
Tree::Tree(const string & treedata){
	vector<string> data;
	bool in_an_entry = false;

	string word = ""; 
	for(int i = 0; i<treedata.length(); i++){
		if(treedata[i] == '"'){ //ensures strings aren't separated by "," inside values
			in_an_entry = !in_an_entry;
		}
		if(treedata[i] == ',' && !in_an_entry){
			data.push_back(word);
			word = "";
			continue;
		}
		word+=treedata[i];
	}
	data.push_back(word); //pushes back last word

	spc_common = data[9]; 
	tree_id = stoi(data[0]);
	tree_dbh = stoi(data[3]);
	status = data[6];
	if(status != "Alive" and status != "Dead" and status != "Stump" and status !=""){
		cerr << "Invalid value for 'Status'" << endl;
		exit(1);
	}
	health = data[7];
	if(health != "Good" and health != "Fair" and health != "Poor" and health !=""){
		cerr << "Invalid value for 'Health'" << endl;
		exit(1);
	}
	address = data[24];
	boroname = data[29];
	if(boroname != "Manhattan" and boroname != "Bronx" and boroname != "Brooklyn" and boroname != "Queens" and boroname != "Staten Island"){
		cerr << "Invalid value for 'Boroname'" << endl;
		exit(1);
	}
	zipcode = stoi(data[25]);
	latitude = stod(data[37]);
	longitude = stod(data[38]);
}
Tree::Tree(int id, int diam, string status,
		string health, string spc, int zip,
		string addr, string boro, double
		latitude, double longitude ){
	tree_id = id;
	tree_dbh = diam;
	this->status = status;
	this->health = health;
	this->spc_common = spc;
	zipcode = zip;
	address = addr;
	boroname = boro;
	this->latitude = latitude;
	this->longitude = longitude;
}




//edit to check lower case versions of strings
bool operator==(const Tree & t1, const Tree & t2){
	if(t1.spc_common == t2.spc_common && t1.tree_id == t2.tree_id){
		return true;
	}
	return false;
}
bool operator<(const Tree & t1, const Tree & t2){
	if(t1.spc_common < t2.spc_common){
		return true;
	}
	if(t1.tree_id < t2.tree_id){
		return true;
	}
	return false;
}
ostream& operator<< (ostream & os, const Tree & t){
	os << t.write() << "\n";
	return os;
}


//get functions
string Tree::common_name() const{
	return spc_common;
}
string Tree::borough_name() const{
	return boroname;
}
string Tree::nearest_address() const{
	return address;
}
int Tree::diameter() const{
	return tree_dbh;
}
int Tree::zip() const{
	return zipcode;
}
void Tree::get_position(double & latitude, double & longitude) const{
	latitude = this->latitude;
	longitude = this->longitude;
}

//
string Tree::write() const{ //Wrapper function
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
