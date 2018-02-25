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
		string pop();
		void push(string &s);
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