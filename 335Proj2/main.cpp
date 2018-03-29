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
#include "bitcoin.h"
#include "pseudoserver.h"
#include "tree.h"
using namespace std;


void tree_info(string comm_string, TreeCollection collection){
	string lookup = "";
	bool read_string = false;
	for(int i = 0;i<comm_string.length();i++){
		if(comm_string[i] == " "){
			read_string = true;
			continue;
		}
		if(!read_string){
			continue;
		}
		lookup += comm_string[i];
	}

	list<string> all_matching = collection.get_matching_species(lookup);
	cout << lookup << endl;
	cout << "All Matching Species: " << endl;
	for(list<string>::const_iterator iterator = all_matching.begin(), end =all_matching.end(); iterator != end, iterator++){
		cout << *iterator << endl;
	}
	cout << "Frequency By Borough: " << endl;
}
void listall_names(string comm_string, TreeCollection){
	collection.print_all_species(cout);
}
void listall_inzip(string comm_string){
	//
}
void list_near(string comm_string){
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
	  	cerr << "Unable to open input file: " << in_filename << endl;
	    exit(1);
	}
	string command_filename = argv[2];
	ifstream commands(command_filename);
	if (!commands.is_open()) { //If file fails to open
	  	cerr << "Unable to open output file: " << out_filename << endl;
	    exit(1);
	}

	//Tree_Collection Population Loop
	while(1){
		string temp = "";
		getline(tree_data, temp);
		if (temp == ""){
			break;
		}
		Tree temp_tree = new Tree(temp);
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
			if(temp[i] == " "){
				break;
			}
			command_name += temp[i];
		}
		if(command_name == "tree_info"){
			tree_info();
		}else if(command_name == "listall_names"){
			listall_names();
		}else if (command_name == "listall_inzip"){
			listall_inzip();
		}else if (command_name == "list_near"){
			list_near();
		}else{
			cerr << "Invalid command: " << command_name << endl;
			exit(1);
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