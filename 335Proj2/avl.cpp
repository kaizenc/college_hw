/*******************************************************************************
  Title          : avl.cpp
  Author         : Kaizen Castanos
  Created on     : March 27, 2018
  Description    : The code for the AVL Tree class
  Purpose        : 
  Usage          : Include this file with client code
  Build with     : Makefile; type make to compile, or make tree.o to compile
				   just this file
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "avl.h"
using namespace std;

//Con-De structors
AVL_Tree::AVL_Tree(){
  &actual_tree = new Tree();
  left = nullptr;
  right = nullptr;
}
AVL_Tree::AVL_Tree (const AVL_Tree & tree){
  //
}
AVL_Tree::~AVL_Tree (){
  //
}


//Search methods:
const Tree & AVL_Tree::find (const Tree & x) const{
  //
}
const Tree & AVL_Tree::findMin() const{
  //
}
const Tree & AVL_Tree::findMax() const{
  //
}
list <Tree>& AVL_Tree::findallmatches (const Tree & x) const{
  //
}

//Search Helper Methods:
//recursive versions of findmax & find min


//inorder print
void AVL_Tree::print ( ostream & out ) const{
  //
}
void AVL_Tree::clear(); // empty the tree
void AVL_Tree::insert(const Tree & x); // insert element x
void AVL_Tree::remove(const Tree & x); // remove element x