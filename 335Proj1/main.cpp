#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bitcoin.h"
#include "pseudoserver.h"
#include "tree.h"

int main(int argc, char *argv[]){
	//if argc=2, only input file supplied
	//if argc=3, input/output supplied
	//if argc=4, input/output and seed supplied
	
	if(argc < 2){
		cerr << "Insufficient params" << endl;
		exit(1);
	}
	string filename = "smol.csv";
	ifstream tree_data(filename);
	ofstream output("out2.txt");

	if (!tree_data) { //If file fails to open
	  	cerr << "Unable to open file " << filename << endl;
	    exit(1);
	}

	int seed = 0;
	int num_of_flips = 0;
	int q_size_sum = 0;
	int empty_q_count = 0;
	int eof_q_size = 0;

	Bitcoin coin = Bitcoin(seed);
	PseudoServer server;
	
	bool server_is_done = false;
	
	while(!server_is_done){
		if(coin() == 0){
			string line = "";
			if(server.extract(line)){
				cout << line << endl << endl;
				Tree new_tree(line);
				output << new_tree;
			}
		}else{//coin is 1
			if(!server.read(tree_data)){
				server_is_done = true;
			}
		}
	}
	
	string line = "";
	while(server.extract(line)){
		Tree new_tree(line);
		output << new_tree;
	}
	
}