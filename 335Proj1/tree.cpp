#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
using namespace std;

Tree::Tree(const string & treedata){
	vector<string> data;

	string word = ""; 
  for(int i = 0; i<treedata.length(); i++){
  	if(treedata[i] == ','){
			i++;
			data.push_back(word);
			word = "";
			continue;
  	}
		word+=treedata[i];
  }
  spc_common = data[9]; 
	//int tree_id; //0
	//int tree_dbh; //3
	status = data[6];
	health = data[7];
	address = data[24];
	boroname = data[29];
	//int zipcode; //25
	//double latitude; //37
	//double longitude; //3
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
	temp = "tree_id: " + tree_id + delimiter;
	result += temp;
	temp = "tree_dbh: " + tree_dbh + delimiter;
	result += temp;
	temp = "status: " + status + delimiter;
	result += temp;
	temp = "health: " + health + delimiter;
	result += temp;
	temp = "address: " + address + delimiter;
	result += temp;
	temp = "boroname: " + boroname + delimiter;
	result += temp;
	temp = "zipcode: " + zipcode + delimiter;
	result += temp;
	temp = "latitude: " + 3 + delimiter;//FIX THIS
	result += temp;
	temp = "longitude: " + 3 + delimiter;//FIX THIS
	result += temp;
}