#include <iostream>
#include <vector>
#include <string>
#include "bitcoin.h"
#include "pseudoserver.h"
#include "tree.h"

int main(int argc, char *argv[]){
	//if argc=2, only input file supplied
	//if argc=3, input/output supplied
	//if argc=4, input/output and seed supplied
	Bitcoin coin;
	Pseudoserver server;
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