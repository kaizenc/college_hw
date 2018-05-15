/*******************************************************************************
  Title          : subway_system.cpp
  Author         : Kaizen Castanos
  Created on     : May 12, 2018
  Description    : Functions for the subway_system class
  Purpose        : Handles hash tables and actually doing the commands
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

subway_system::subway_system(){
	for(int i = 0;i<4001;i++){
		stations_hash_table.push_back(-1);
		stations_long.push_back(-1);
		stations_lat.push_back(-1);
	}
}

void subway_system::insert_entrance(subway_entrance e){
	entrances.push_back(e);
	//n^2, really bad
	for(unsigned int i = 0;i<entrances.size()-1;i++){
		if(is_connected(entrances[i], e)){
			int act_index = i;
			while(entrance_p_tree[act_index] > 0){
				act_index = entrance_p_tree[act_index]; //build parent tree as shallowly as possible
			}
			entrance_p_tree.push_back(act_index); //pushes back index of entrance that its a union with			
			return;
		}
	}	
	entrance_p_tree.push_back(-1); //pushes back a -1, aka a station
	stations.push_back(entrance_p_tree.size()-1); //pushes index of the entrance in the entrance vector
}

void subway_system::build_station_hash_table(){
	for(unsigned int i=0;i<stations.size();i++){
		int hashval = station_hash(entrances[stations[i]].getName());
		int k=0;
		while(stations_hash_table[hashval] >= 0){
			quad_probe(hashval, k);
		}
		stations_hash_table[hashval] = stations[i]; //store in hashtable at the hash value, stores index only
		calculate_centroid(stations[i]); //runs for each station, saves longitude and latitude for each station
	}
	for(unsigned int i=0;i<stations.size();i++){
		int index_to_use = stations[i];
		for(unsigned int j=0;j<entrance_p_tree.size();j++){
			if(entrance_p_tree[j] == index_to_use){
				int hashval = station_hash(entrances[j].getName());
				int k=0;
				while(stations_hash_table[hashval] >= 0){
					quad_probe(hashval, k);
				}
				stations_hash_table[hashval] = j;
			}
		}
	}
}


//Hash Functions + Probing
int subway_system::line_hash(string x){
	//horner's method of encoding, then simple modulo hashing
	int hashval = 0;
	for(unsigned int i = 0;i < x.length();i++){
		hashval = x[i] + 33*hashval;
	}
	return hashval%51;
}
unsigned int subway_system::station_hash(string name){
	//horner's method of encoding, then simple modulo hashing
	string x = name;
	sanitize(x);
	unsigned int hashval = 0;
	for(unsigned int i = 0;i < x.length();i++){
		hashval = x[i] + 80*hashval;
	}
	return hashval%4001;
}
void subway_system::quad_probe(int &hashval, int &k){
	//uses references, changes the hashvalue and the value of k directly
	hashval = (hashval + (k*k))%4001;
	k++;
}

//Helper Functions
bool subway_system::is_connected(subway_entrance &e1, subway_entrance &e2){
	bool a = (e1.getMask() ^ e2.getMask()) == 0; //checks if bitmasks are equal using XOR
	double distance = haversine(e1.getLat(), e1.getLong(), e2.getLat(), e2.getLong());
	double limit = 0.28; //can change the limit
	bool b = (distance <= limit);
	return a and b; //both have to be true
}

bool subway_system::is_exit_only(string x){
	string name = x;
	sanitize(name);
	return name.find("(exit only)")!=string::npos; //looks for "(exit only)" and returns true if it's there
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
		new_x +=tolower(x[i]); //lowercase each character
	}
	x = new_x;
}

void subway_system::calculate_centroid(int index_to_use){
	//hashval gets the index, allows us to re_insert later
	int count = 0; //number of entrances in a station

	double sum_lat = 0;
	double sum_long = 0;
	for(unsigned int i = 0;i<entrance_p_tree.size();i++){
		if(entrance_p_tree[i] == index_to_use){
			count++;
			sum_long+=entrances[i].getLong();
			sum_lat+=entrances[i].getLat();
		}
	}
	stations_lat[index_to_use] = sum_lat/count;
	stations_long[index_to_use] = sum_long/count;
}


/**********Commands Functions**********/
void subway_system::list_line_stations(string x){
	unsigned long mask1 = 1UL << (line_hash(x)); //create bitmask
	for (unsigned int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		long result = mask1 & temp.getMask(); //all 0s if nothing matches
		if (result > 0){ //match found
			cout << temp.getName() << endl;
		}
	}
}

void subway_system::list_all_stations(){
	for (unsigned int i=0;i<stations.size();i++){ //iterate through
		cout << entrances[stations[i]].getName() << endl;
	}
}

void subway_system::list_entrances(string x){
	int hashval = station_hash(x);
	int k=0;
	while(entrances[stations_hash_table[hashval]].getName() != x){
		quad_probe(hashval, k);
		if(stations_hash_table[hashval] < 0){ //hits an empty spot
			cout << "Station Not Found :(" << endl;
			return;
		}
	}
	//only print if it's not an exit
	if(!is_exit_only(entrances[stations_hash_table[hashval]].getName())){
		cout << entrances[stations_hash_table[hashval]].getName() << endl;
	}
	//print if it's not an exit
	int index_to_use = stations_hash_table[hashval];
	for (unsigned int i=0;i<entrance_p_tree.size();i++){
		if(entrance_p_tree[i] == index_to_use and !is_exit_only(entrances[i].getName())){
			cout << entrances[i].getName() << endl;
		}
	}
}

void subway_system::nearest_station(double long_, double lat_){
	//Iterates through stations, if distance is shortest, it's added to the result vector
	vector<subway_entrance> result;
	double shortest;
	for (unsigned int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		double lat_check = stations_lat[stations[i]];	
		double long_check = stations_long[stations[i]];	
		double curr_distance = haversine(lat_check, long_check, lat_, long_);
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

void subway_system::nearest_lines(double long_, double lat_){
	//Same as nearest_station, but prints out the station's lines
	vector<subway_entrance> result;
	double shortest;
	for (unsigned int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		double lat_check = stations_lat[stations[i]];	
		double long_check = stations_long[stations[i]];	
		double curr_distance = haversine(lat_check, long_check, lat_, long_);
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
		for(unsigned int j=0;j<result[i].getLines().size();j++){
			cout << result[i].getLines()[j] << " ";
		}
		cout << endl;
	}
}

void subway_system::nearest_entrance(double long_, double lat_){
	vector<int> result; //stores stations indices
	vector<subway_entrance> real_result; //stores entrances
	double shortest;

	//first pass, looks for closest stations
	for (unsigned int i=0;i<stations.size();i++){
		subway_entrance temp = entrances[stations[i]];
		double lat_check = stations_lat[stations[i]];	
		double long_check = stations_long[stations[i]];	
		double curr_distance = haversine(lat_check, long_check, lat_, long_);
		if(i == 0){
			result.push_back(i);
			real_result.push_back(temp);
			shortest = curr_distance;
		}else if(curr_distance == shortest){
			result.push_back(i);
			real_result.push_back(temp);
			continue;
		}else if(curr_distance < shortest){
			result.clear();
			real_result.clear();
			result.push_back(i);
			real_result.push_back(temp);
			shortest = curr_distance;
		}
	}
	//looks within stations, looks for closest entrances
	for (unsigned int i=0;i<result.size();i++){
		int index_to_use = stations[result[i]];
		for(unsigned int j=0;j<entrance_p_tree.size();j++){
			if(entrance_p_tree[j] == index_to_use){
				subway_entrance temp = entrances[j];
				double curr_distance = haversine(temp.getLat(), temp.getLong(), lat_, long_);
				if(curr_distance == shortest){
					real_result.push_back(temp);
					continue;
				}else if(curr_distance < shortest){
					real_result.clear();
					real_result.push_back(temp);
					shortest = curr_distance;
				}
			}
		}
	}
	for(unsigned int i = 0;i<real_result.size();i++){
		cout << real_result[i].getName() << ", ";
	}
	cout << endl;
	
}