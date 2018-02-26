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
	string filename = "filename.csv";
	ifstream tree_data(filename);

	if (!tree_data) {
  	cerr << "Unable to open file " << filename << endl;
    exit(1);   // call system to stop
}

	int seed = 0;
	int num_of_flips = 0;
	int q_size_sum = 0;
	int empty_q_count = 0;
	int eof_q_size = 0;

	Bitcoin coin = Bitcoin(seed);
	PseudoServer server;
	Tree new_tree("1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1");
	
	if(coin() == 0){
		string line = "";
		if(server.extract(line)){
			Tree new_tree(line);
			cout << new_tree;
		}
	}else{//coin is 1
		//read server
	}
	
}