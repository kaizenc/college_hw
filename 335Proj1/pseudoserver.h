/*******************************************************************************
  Title          : pseudoserver.h
  Author         : Kaizen Castanos
  Created on     : February 26, 2018
  Description    : The interface file for the PseudoServer and Queue classes
  Purpose        : PseudoServer is a class used to mimic an actual server for
				   reading and sending files to a client using a Queue, whose
				   implementation is also included. 
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __PSEUDOSERVER_H__
#define __PSEUDOSERVER_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Queue{
	private:
		vector<string> q_;
	public:
		/** pop() removes the first element and returns it
	     *  @return std::string		Element string
	     */
		string pop();
		
		/** push(string &s) adds the string s to the end of the queue
	     *  @param string&s			String element to add
	     */
		void push(string &s);
		
		/** operator() returns the size of the queue
	     *  @return int 			Size 
	     */
		int get_size();
};

class PseudoServer{
	private:
		Queue queue;
	public:
		bool read(istream & is);
		bool extract(string & s);
		int queuesize();
};
#endif /* __PSEUDOSERVER_H__ */