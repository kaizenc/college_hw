/*******************************************************************************
  Title          : subway_system.cpp
  Author         : Kaizen Castanos
  Created on     : May 12, 2018
  Description    : Functions for the subway_system class
  Purpose        : to be written
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
#include "subway_system.h"
using namespace std;


int subway_system::hash_line(string x){
	//horner's method of encoding, then simple modulo hashing
	int hashval = 0;
	for(int i = 0;i < x.length();i++){
		hashval = x[i] + 33*hashval;
	}
	return hashval%51;

}