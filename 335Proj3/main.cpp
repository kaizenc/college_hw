/*******************************************************************************
  Title          : main.cpp
  Author         : Kaizen Castanos
  Created on     : April 29, 2018
  Description    : 
  Purpose        : 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include "subway_entrance.h"
#include "subway_station.h"
#include "subway_system.h"
using namespace std;

string normalize(string line){
	string result = "";
	bool space_ = false;
	for(int i = 0;i<line.length();i++){
		char c = line[i];
		if(c == ' '){
			if(space_){
				continue;
			}
			else{
				space_ = true;
				result+=c;
				continue;
			}			
		}
		space_ = false;
		result+=char(tolower(c));
	}
	return result;
}

int main(int argc, char *argv[]){
	
	if(argc < 3){
		cerr << "Error: Insufficient Parameters" << endl;
		exit(1);
	}
	string csv_filename = argv[1];
	ifstream sub_data(csv_filename);
	if (!sub_data) { //If file fails to open
	  	cerr << "Unable to open csv file: " << csv_filename << endl;
	    exit(1);
	}
	string commands_filename = argv[2];
	ifstream cmd_data(commands_filename);
	if (!cmd_data) { //If file fails to open
	  	cerr << "Unable to open commands file: " << commands_filename << endl;
	    exit(1);
	}


	/**csv Processing Loop:
	Create a new subway_entrance in memory, normalize it first
	Run the subway_system function to insert it into a table or some container

	**/
	
	/**Commands Reference:
	All the commands return an array

	1. list_line_stations (line_identifier)
	Compare the bitmasks of the line_identifier and each line station in the hash.

	2. list_all_stations
	Literally list all the stations lmfao.

	3. list_entrances (station_name)
	During population, create a parent tree of stations. After completion, turn it into a hash table.
	The hash key is the name, the value is the index in the parent tree. 

	4. nearest_station (long, lat)
	Haversine function 

	5. nearest_lines (long, lat)
	6. nearest_entrance (long, lat)



	
	**/
	
	
}