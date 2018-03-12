/*******************************************************************************
  Title          : pseudoserver.cpp
  Author         : Kaizen Castanos
  Created on     : February 26, 2018
  Description    : The code for the PseudoServer and Queue classes
  Purpose        : PseudoServer is a class used to mimic an actual server for
				   reading and sending files to a client using a Queue, whose
				   implementation is also included. 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "pseudoserver.h"
using namespace std;

string Queue::pop(){
	string result = q_.front();
	q_.erase(q_.begin());
	return result;
}
void Queue::push(string & s){
	q_.push_back(s);
}
int Queue::get_size(){
	return q_.size();
}



bool PseudoServer::read(istream & is){
	string temp = "";
	getline(is, temp);
	if(temp != ""){
		queue.push(temp);
		return true;
	}
	return false;
}

bool PseudoServer::extract(string & s){
	if(queue.get_size() == 0){
		return false;
	}
	s = queue.pop();
	return true;
}
int PseudoServer::queuesize(){
	return queue.get_size();
}