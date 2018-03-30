/*******************************************************************************
  Title          : tree_collection.cpp
  Author         : Kaizen Castanos
  Created on     : March 27, 2018
  Description    : The code for the Tree Collection class
  Purpose        : 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "tree_species.h"
#include "tree_collection.h"
using namespace std;

TreeCollection::TreeCollection(){
  //
}
TreeCollection::~TreeCollection(){
  //
}

int TreeCollection::total_tree_count() const{
  return root->getCount();
  return 0;
}
int TreeCollection::count_of_tree_species ( const string & species_name ) const{
  return species.get_matching_species(species_name).size();
}
int TreeCollection::count_of_trees_in_boro( const string & boro_name ) const{
  //
  return 0;
}
list<string> TreeCollection::get_matching_species(const string & species_name) const{
  return species.get_matching_species(species_name);
}
list<string> TreeCollection::get_all_in_zipcode(int zipcode) const{
  //
}
list<string> TreeCollection::get_all_near(double latitude, double longitude, double distance) const{
  list<string> results;
  
}

void TreeCollection::print_all_species(ostream & out) const{
  species.print_all_species(out);
}

void TreeCollection::insert_tree(const Tree & tree){
  root->insert(tree);
  species.add_species(tree.common_name());
}