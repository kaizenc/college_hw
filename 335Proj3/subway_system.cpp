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

void subway_system::insert_entrance(subway_entrance e){
	entrances.push_back(e);
	//iterate through stations, attempt to union, if not then list it as a station	
	for(int i = 0;i<stations.size();i++){
		//compare entrances[stations[i]] with e
		//if they're able to be unionized
			//entrance_p_tree.push_back(stations[i]);
			//is_solo = false;
			//break;
		//
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
	//
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

/**
int main(){
	subway_system hello;
	subway_entrance e1("911,http://web.mta.info/nyct/service/,103rd St & 159th Ave at NE corner,POINT( -73.83051800 40.66046500),A");
	subway_entrance e2("983,http://web.mta.info/nyct/service/,21st St & 41st Ave at NE corner1,POINT( -73.94193500 40.75425500),F");
	hello.insert_entrance(e2);
	cout << hello.entrances[0].getName() << endl;
	return 0;
}
**/