/*******************************************************************************
  Title          : tree_collection.h
  Author         : Kaizen Castanos
  Created on     : March 11, 2018
  Description    : 
  Purpose        : 
  Usage          : 
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __TREE_COLLECTION_H__
#define __TREE_COLLECTION_H__
#include <iostream>
#include <vector>
#include <string>


class TreeCollection{
	private:
		//avl tree, treespecies, and another container
	public:
		//Constructors for Tree
		TreeCollection();
		~TreeCollection();
		
		int total_tree_count() const;
		int count_of_tree_species ( const string & species_name ) const;
		int count_of_trees_in_boro( const string & boro_name ) const;
		list<string> get_matching_species(const string & species_name) const;
		list<string> get_all_in_zipcode(int zipcode) const;
		list<string> get_all_near(double latitude, double longitude, double distance) const;
};

#endif /* __TREE_COLLECTION_H__ */