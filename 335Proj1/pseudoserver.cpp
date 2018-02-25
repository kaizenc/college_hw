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
	return true;
	//
}

bool PseudoServer::extract(string & s){
	return false;
	//
}
int PseudoServer::queuesize(){
	return 1;
	//
}