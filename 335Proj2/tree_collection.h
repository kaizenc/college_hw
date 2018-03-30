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
#include <list>
#include <string>
#include "tree.h"
#include "avl.h"
#include "tree_species.h"


class TreeCollection{
	private:
		AVL_Tree root;
		TreeSpecies species;
		list<string> BoroughNames; //access by same index
		list<int> BoroughTreeCounts;
		//avl tree, treespecies, and another container
	public:
		//Constructors for Tree
		TreeCollection();
		~TreeCollection();
		
		int total_tree_count() const;
		int count_of_tree_species ( const string & species_name ) const;
		int count_of_trees_in_boro( const string & boro_name ) const;
		void insert_tree(const Tree & tree);
		list<string> get_matching_species(const string & species_name) const;
		list<string> get_all_in_zipcode(int zipcode) const;
		list<string> get_all_near(double latitude, double longitude, double distance) const;

		void print_all_species(ostream & out) const;
};

#endif /* __TREE_COLLECTION_H__ */