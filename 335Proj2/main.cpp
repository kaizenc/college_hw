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

void tree_info(string tree_to_find, TreeCollection collection){
	cout << tree_to_find << endl;
	cout << "All Matching Species: " << endl;

	list<string> collection_species = collection.get_matching_species(tree_to_find);
	list<int>::const_iterator iterator;
	for (list<int>::const_iterator iterator = collection_species.begin(), end = collection_species.end(); iterator != end; ++iterator) {
	    cout << *iterator;
	}

	cout << "Frequency By Borough: " << endl;
}
void listall_names(){
	//
}
void listall_inzip(int zip){
	//
}
void list_near(double latitude, double longitude, double distance){
	//
}

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
	string arg_tree_to_find;
	int arg_zip;
    double arg_latitude; 
    double arg_longitude;
    double arg_distance;
    bool result;
	while(1){
		if(command_handler.get_next(commands)){
			command_handler.get_args(arg_tree_to_find, arg_zip, arg_latitude, arg_longitude, arg_distance, result);
			switch(command_handler.type_of()){
				case tree_info_cmmd: tree_info(arg_tree_to_find, collection);
					break;
				case listall_names_cmmd: listall_names();
					break;
			    case listall_inzip_cmmd: listall_inzip(arg_zip);
			    	break;
			    case list_near_cmmd: list_near(arg_latitude, arg_longitude, arg_distance);
			    	break;
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