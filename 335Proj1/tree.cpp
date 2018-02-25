#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
using namespace std;

Tree::Tree(const string & treedata){
	//
}
ostream& operator<< (ostream & os, const Tree & t){
	os << t.write(", ") << "\n";
	return os;
}
string Tree::write(string delimiter) const{
	string result = "";
	string temp = "";
	//ARE YOU READY FOR THIS **incredible** CODE WRITING SKILLS BOIZ
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