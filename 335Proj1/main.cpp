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
	/*
	string filename = "filename.csv";
	ifstream tree_data(filename);

	if (!tree_data) { //If file fails to open
	  	cerr << "Unable to open file " << filename << endl;
	    exit(1);
	}
	*/

	int seed = 0;
	int num_of_flips = 0;
	int q_size_sum = 0;
	int empty_q_count = 0;
	int eof_q_size = 0;

	Bitcoin coin = Bitcoin(seed);
	PseudoServer server;
	string sample_data = "180683,348711,08/27/2015,3,0,OnCurb,Alive,Fair,Acer rubrum,red maple,None,None,NoDamage,TreesCount Staff,None,No,No,No,No,No,No,No,No,No,108-005 70 AVENUE,11375,Forest Hills,406,4,Queens,29,28,16,QN17,Forest Hills,4073900,New York,40.72309177,-73.84421522,1027431.148,202756.7687";
	Tree new_tree(sample_data);	
	cout << new_tree.write(", ") << endl;
	/*
	if(coin() == 0){
		string line = "";
		if(server.extract(line)){
			Tree new_tree(line);
			cout << new_tree;
		}
	}else{//coin is 1
		//read server
	}
	*/
	
}