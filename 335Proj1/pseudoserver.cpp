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
	//
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