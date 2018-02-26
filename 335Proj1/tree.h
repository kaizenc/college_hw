#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Tree{
	private:
		string spc_common; //9
		int tree_id; //0
		int tree_dbh; //3
		string status; //6
		string health; //7
		string address; //24
		string boroname; //29
		int zipcode; //25
		double latitude; //37
		double longitude; //38
		
	public:
		Tree(const string & treedata); 
		friend ostream& operator<< (ostream & os, const Tree & t);
		string write(string delimiter="	") const;
};

#endif /* __TREE_H__ */