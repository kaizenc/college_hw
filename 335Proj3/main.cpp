/*******************************************************************************
  Title          : main.cpp
  Author         : Kaizen Castanos
  Created on     : April 29, 2018
  Description    : 
  Purpose        : 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "subway_entrance.h"
#include "subway_system.h"
#include "command.h"
using namespace std;

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
	//write some code to process csv into the thing
	subway_system sub_system;
	string line = "";
	while(getline(sub_data, line)){
		subway_entrance e(line);
		sub_system.insert_entrance(e);
	}
	sub_system.build_station_hash_table();


	Command command_parser;
	string arg_line_identifier;
	string arg_station_name;
	double arg_longitude;
	double arg_latitude;
	bool result;

	while(command_parser.get_next(cmd_data)){
		if(command_parser.type_of() == list_line_stations_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			cout << "Stations of the " << arg_line_identifier << " line:" << endl;
			sub_system.list_line_stations(arg_line_identifier);
			cout << endl;
			
		} else if(command_parser.type_of() == list_all_stations_cmmd){
			cout << "All stations:" << endl;
			sub_system.list_all_stations();
			cout << endl;

		} else if(command_parser.type_of() == list_entrances_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			cout << "Entrances of " << arg_station_name << endl;
			sub_system.list_entrances(arg_station_name);
			cout << endl;


		} else if(command_parser.type_of() == nearest_station_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			cout << "The stations closest to (" << arg_longitude << "," << arg_latitude << ") are: ";
			sub_system.nearest_station(arg_longitude, arg_latitude);
			cout << endl;

		} else if(command_parser.type_of() == nearest_lines_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			cout << "The lines closest to (" << arg_longitude << "," << arg_latitude << ") are: ";
			sub_system.nearest_lines(arg_longitude, arg_latitude);
			cout << endl;
		} else if(command_parser.type_of() == nearest_entrance_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			cout << "The entrances closest to (" << arg_longitude << "," << arg_latitude << ") are: ";
			sub_system.nearest_entrance(arg_longitude, arg_latitude);
			cout << endl;
		}
	}
	
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