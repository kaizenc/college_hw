#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Tree{
	private:
		string spc_common;
		int tree_id;
		int tree_dbh;
		string status;
		string health;
		string address;
		string boroname;
		int zipcode;
		double latitude;
		double longitude;
		
	public:
		Tree(const string & treedata); 
		friend ostream& operator<< (ostream & os, const Tree & t);
		string write(string delimiter="	") const;
};

#endif /* __TREE_H__ */