/*******************************************************************************
  Title          : tree.h
  Author         : Kaizen Castanos
  Created on     : February 26, 2018
  Description    : The interface file for the Tree class
  Purpose        : A tree container used to contain some data, specifically
                   from NYC's OpenData data set on trees. Also includes
                   functions to populate its variables with a string and a
                   function to send data to an output stream. 
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

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
		/** write_with_delim(string delimiter) returns a string with the 
		 *  Tree's parameters written in order and separated by a delimiter. 
		 *  @param std::string		Delimiter
	     *  @return std::string		Final String
	     */
		string write_with_delim(string delimiter) const;
	public:
		//Constructor for Tree
		Tree(const string & treedata); 
		
		/** operator<<(ostream & os, const Tree & t) allows us to send the
		 *  tree to an output stream
	     *  @return ostream&		Output Stream
	     */
		friend ostream& operator<< (ostream & os, const Tree & t);
		
	    /** write() returns a string with the Tree's parameters written in
		 *  order and separated by a tab. 
	     *  @return std::string		Final String
	     */
		string write() const;
};

#endif /* __TREE_H__ */