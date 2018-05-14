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
#include "subway_station.h"
#include "haversine.h"
using namespace std;

subway_system::subway_system(){
	subway_station def = subway_station();
	for(int i = 0;i<4001;i++){
		temp_stations.push_back(def);
	}
}


int subway_system::line_hash(string x){
	//horner's method of encoding, then simple modulo hashing
	int hashval = 0;
	for(unsigned int i = 0;i < x.length();i++){
		hashval = x[i] + 33*hashval;
	}
	return hashval%51;
}

int subway_system::station_hash(string name){
	string x = name;
	sanitize(x);
	int hashval = 0;
	for(unsigned int i = 0;i < x.length();i++){
		hashval = x[i] + 80*hashval;
	}
	return hashval%4001;
}
void subway_system::quad_probe(int &hashval, int &k){
	hashval = (hashval + (k*k))%4001;
	k++;
}


void subway_system::build_station_hash_table(){
	for(unsigned int i=0;i<stations.size();i++){
		subway_station temp_station(entrances[stations[i]].getMask());
		temp_station.insert_entrance(entrances[stations[i]]);
		int hashval = station_hash(temp_station.getName());
		int k=0;

		while(!temp_stations[hashval].isEmpty()){
			quad_probe(hashval, k);
		}
		for(unsigned int j=0;j<entrances.size();j++){
			if(entrance_p_tree[j] == i){
				temp_station.insert_entrance(entrances[j]);
			}
		}
		temp_station.calculate_centroid();
		//temp_stations.push_back(temp_station);

		vector<subway_entrance> asdf = temp_station.getEntrances();
		for(unsigned int j=1;j<asdf.size();j++){
			int hashval2 = station_hash(asdf[j].getName());
			int k2 = 0;
			while(!temp_stations[hashval2].isEmpty()){
				quad_probe(hashval2, k2);
			}
			temp_stations[hashval] = temp_station;
		}

		temp_stations[hashval] = temp_station;
	}
}


void subway_system::insert_entrance(subway_entrance e){
	entrances.push_back(e);
	for(unsigned int i = 0;i<entrances.size()-1;i++){
		if(is_connected(entrances[i], e)){
			int act_index = i;
			while(entrance_p_tree[act_index] > 0){
				act_index = entrance_p_tree[act_index];
			}
			entrance_p_tree.push_back(act_index);			
			return;
		}
	}	
	entrance_p_tree.push_back(-1);
	stations.push_back(entrance_p_tree.size()-1);
}

bool subway_system::is_connected(subway_entrance &e1, subway_entrance &e2){
	bool a = (e1.getMask() ^ e2.getMask()) == 0;
	double distance = haversine(e1.getLat(), e1.getLong(), e2.getLat(), e2.getLong());
	double limit = 0.28;
	bool b = (distance <= limit);
	return a and b;
}

void subway_system::sanitize(string &x){
	bool space_seq = false; //true if encountering spaces
	string new_x = "";
	for(unsigned int i = 0;i<x.length();i++){
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
	for (unsigned int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		long result = mask1 & temp.getMask();
		if (result > 0){ //match found
			cout << temp.getName() << endl;
		}
	}
}

void subway_system::list_all_stations(){
	for (unsigned int i=0;i<stations.size();i++){
		cout << entrances[stations[i]].getName() << endl;
	}
}

void subway_system::nearest_station(double long_, double lat_){
	vector<subway_entrance> result;
	double shortest;
	for (unsigned int i=0;i<stations.size();i++){
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
	for(unsigned int i = 0;i<result.size();i++){
		cout << result[i].getName() << endl;
	}
}