/*******************************************************************************
  Title          : main.cpp
  Author         : Kaizen Castanos
  Created on     : February 26, 2018
  Description    : A project used to simulate reading and parsing text using a
				   server, a queue, and a random "bitcoin.""
  Purpose        : To simulate the reading and parsing of data using a server
				   and possibly scaling it up to work with larger sets of data.
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include "tree.h"
#include "avl.h"
#include "tree_collection.h"
#include "tree_species.h"
#include "command.h"
using namespace std;

int main(int argc, char *argv[]){
	
	if(argc < 3){
		cerr << "Error: Insufficient Parameters" << endl;
		exit(1);
	}
	string tree_filename = argv[1];
	ifstream tree_data(tree_filename);
	if (!tree_data) { //If file fails to open
	  	cerr << "Unable to open input file: " << tree_filename << endl;
	    exit(1);
	}
	string command_filename = argv[2];
	ifstream commands(command_filename);
	if (!commands.is_open()) { //If file fails to open
	  	cerr << "Unable to open output file: " << command_filename << endl;
	    exit(1);
	}

	TreeCollection collection;
	Command command_handler;
	//Tree_Collection Population Loop
	while(1){
		string temp = "";
		getline(tree_data, temp);
		if (temp == ""){
			break;
		}
		Tree temp_tree(temp);
		//insert into tree_collection
	}

	//Command Loop
	int arg_zip;
    double arg_latitude; 
    double arg_longitude,;
    double arg_distance,;
    bool result;
	while(1){
		if(command_handler.get_next(commands)){
			command_handler.get_args(arg_zip, arg_latitude, arg_longitude, result);
			switch(command_handler.type_of()){
				case tree_info_cmmd: //run tree info command
				case listall_names_cmmd: //run command
			    case listall_inzip_cmmd: //run command
			    case list_near_cmmd: //run command
			}
		}else{
			break;
		}
	}

	
	//create a loop for reading commands
	/***
	 * tree_info "tree_to_find": treecollection.get_matching_species, check output
	 * listall_names: cout << print_all_species
	 * listall_inzip "zipcode": nothing in treecollection, finds all trees in zipcode
	 * list_near "latitude longitude dist": use haversine formula on all trees, generate output
	 **/
	tree_data.close();
	commands.close();
	
	
	
}