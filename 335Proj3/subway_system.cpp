/*******************************************************************************
  Title          : subway_system.cpp
  Author         : Kaizen Castanos
  Created on     : May 12, 2018
  Description    : Functions for the subway_system class
  Purpose        : to be written
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
#include "subway_system.h"
#include "haversine.h"
using namespace std;


int subway_system::line_hash(string x){
	//horner's method of encoding, then simple modulo hashing
	int hashval = 0;
	for(int i = 0;i < x.length();i++){
		hashval = x[i] + 33*hashval;
	}
	return hashval%51;
}

int subway_system::station_hash(string name){
	string x = name;
	sanitize(x);
	int hashval = 0;
	for(int i = 0;i < x.length();i++){
		hashval = x[i] + 80*hashval;
	}
	return hashval%4001;
}
int subway_system::quad_probe(int hashval, int &k){
	return (hashval + (k*k))%4001;
}

void subway_system::build_station_hash_table(){
	return;
}

void subway_system::insert_entrance(subway_entrance e){
	entrances.push_back(e);
	for(int i = 0;i<stations.size();i++){
		if(is_station(entrances[stations[i]], e)){
			entrance_p_tree.push_back(stations[i]);			
			return;
		}
	}	
	entrance_p_tree.push_back(-1);
	stations.push_back(entrance_p_tree.size()-1);	
}

bool subway_system::is_station(subway_entrance &e1, subway_entrance &e2){
	bool a = (e1.getMask() ^ e2.getMask()) == 0;
	double distance = haversine(e1.getLat(), e1.getLong(), e2.getLat(), e2.getLong());
	double limit = 0.28;
	bool b = (distance <= limit);
	return a and b;
}

void subway_system::sanitize(string &x){
	bool space_seq = false; //true if encountering spaces
	string new_x = "";
	for(int i = 0;i<x.length();i++){
		if(x[i] == ' '){
			space_seq = true;
			continue;
		}
		if (space_seq) new_x+=" ";
		space_seq = false;
		new_x +=tolower(x[i]);
	}
	x = new_x;
}



void subway_system::list_line_stations(string x){
	unsigned long mask1 = 1UL << (line_hash(x));
	for (int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		long result = mask1 & temp.getMask();
		if (result > 0){ //match found
			cout << temp.getName() << endl;
		}
	}
}

void subway_system::list_all_stations(){
	for (int i=0;i<stations.size();i++){
		cout << entrances[stations[i]].getName() << endl;
	}
}

void subway_system::nearest_station(double long_, double lat_){
	vector<subway_entrance> result;
	double shortest;
	for (int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		double curr_distance = haversine(temp.getLat(), temp.getLong(), lat_, long_);
		if(i == 0){
			result.push_back(temp);
			shortest = curr_distance;
		}else if(curr_distance == shortest){
			result.push_back(temp);
			continue;
		}else if(curr_distance < shortest){
			result.clear();
			result.push_back(temp);
			shortest = curr_distance;
		}
	}
	for(int i = 0;i<result.size();i++){
		cout << result[i].getName() << endl;
	}
}