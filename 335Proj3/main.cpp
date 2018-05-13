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

	Command command_parser;
	string arg_line_identifier;
  string arg_station_name;
  double arg_longitude;
  double arg_latitude;
  bool result;
	while(command_parser.get_next(cmd_data)){
		if(command_parser.typeof() == list_line_stations_cmmd){
			command_parser.get_args(arg_line_identifier, arg_station_name, arg_longitude, arg_latitude, result);
			//linehash the identifier
			//turn it into a bitmask
			//& it with every station
			//if the & is greater than 0, list it 
		} else if(command_parser.typeof() == list_all_stations_cmmd){
			//iterate through the stations table
		} else if(command_parser.typeof() == list_entrances_cmmd){
			//find the station using the station hash
			//get the parent tree index
			//iterate through the parent tree, look for everything that has that as its entry
		} else if(command_parser.typeof() == nearest_station_cmmd){
			//iterate through stations, haversine each
		} else if(command_parser.typeof() == nearest_lines_cmmd){
			//iterate through stations, haversine each, decode bitmask
		} else if(command_parser.typeof() == nearest_entrance_cmmd){
			//nearest stations with a larger radius, and then check nearest entrance
		}
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