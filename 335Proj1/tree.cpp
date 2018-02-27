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
	os << t.write(", ") << "\n";
	return os;
}
string Tree::write(string delimiter) const{
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