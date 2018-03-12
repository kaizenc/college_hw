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

int main(int argc, char *argv[]){
	
	if(argc < 4){
		cerr << "Error: Insufficient Parameters" << endl;
		exit(1);
	}
	string in_filename = argv[1];
	ifstream tree_data(in_filename);
	if (!tree_data) { //If file fails to open
	  	cerr << "Unable to open input file: " << in_filename << endl;
	    exit(1);
	}
	string out_filename = argv[2];
	ofstream output(out_filename);
	if (!output.is_open()) { //If file fails to open
	  	cerr << "Unable to open output file: " << out_filename << endl;
	    exit(1);
	}
	
	int seed = 0;
	try{
		seed = stoi(argv[3]);
	}catch(const invalid_argument& ia){
		cerr << "Last parameter isn't an integer: " << argv[3] << endl;
		exit(1);
	}
	
	int num_of_flips = 0;
	int q_size_sum = 0;
	int empty_q_count = 0;
	int eof_q_size = 0;
	int max_q_size = 0;

	Bitcoin coin = Bitcoin(seed);
	PseudoServer server;
	
	bool server_is_done = false;
	
	while(!server_is_done){
		if(coin() == 0){
			string line = "";
			if(server.extract(line)){
				Tree new_tree(line);
				output << new_tree;
			}
		}else{//coin is 1
			if(!server.read(tree_data)){
				server_is_done = true;
				eof_q_size = server.queuesize();
			}
		}
		//keep track of stats
		num_of_flips++;
		q_size_sum += server.queuesize();
		if(server.queuesize() == 0){
			empty_q_count++;
		}
		if(server.queuesize() > max_q_size){
			max_q_size = server.queuesize();
		}
	}
	
	string line = "";
	while(server.extract(line)){
		Tree new_tree(line);
		output << new_tree;
	}
	tree_data.close();
	output.close();
	cout << "average queue size: " << (q_size_sum*1.0)/num_of_flips << endl;
	cout << "maximum queue size: " << max_q_size << endl;
	cout << "empty queue count: " << empty_q_count << endl;
	cout << "queue size on eof: " << eof_q_size << endl;
	
	
	
}