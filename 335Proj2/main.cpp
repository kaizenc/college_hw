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
	while(1){
		string temp = "";
		getline(commands, temp);
		if (temp == ""){
			break;
		}
		string command_name = "";
		for(int i = 0;i<temp.length();i++){
			if(&temp[i] == " "){
				break;
			}
			command_name += &temp[i];
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