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
#include "tree.h"
using namespace std;

//Con-De structors
AVL_Tree::AVL_Tree(){
  left = nullptr;
  right = nullptr;
}
AVL_Tree::AVL_Tree(const Tree & tree){
  left = nullptr;
  right = nullptr;
  actual_tree = tree;
}
AVL_Tree::AVL_Tree (const AVL_Tree & tree){
  this->left = tree.left;
  this->right = tree.right;
}
AVL_Tree::~AVL_Tree (){
  delete left;
  delete right;
  left = nullptr;
  right = nullptr;
}


//Search methods:
const Tree & AVL_Tree::find (const Tree & x) const{
  if(x == actual_tree){
    return actual_tree;
  }
  if(left != nullptr && x < actual_tree){
    return left->find(x);
  }else if(right != nullptr && actual_tree < x){
    return right->find(x);
  } //needs to return something if we can't find it
}
const Tree & AVL_Tree::findMin() const{
  if(left != nullptr){
    return left->findMin();
  }
  return actual_tree;
}
const Tree & AVL_Tree::findMax() const{
  if(right != nullptr){
    return right->findMin();
  }
  return actual_tree;
}
list<Tree>& AVL_Tree::findallmatches (const Tree & x) const{
  //
}

//Search Helper Methods:
//recursive versions of findmax & find min


//inorder print
void AVL_Tree::print (ostream & out) const{
  if(left != nullptr){
    left->print(out);
  }
  out << actual_tree;
  if(right != nullptr){
    right->print(out);
  }
}
// empty the tree
void AVL_Tree::clear(){

}
// insert element x
void AVL_Tree::insert(const Tree & x){
  if(x < actual_tree){
    if(left != nullptr){
      left->insert(x);
    }else{
      AVL_Tree *new_left = new AVL_Tree(x);
      left = new_left;
      //balance
    }
  }else if (actual_tree < x){
    if(right != nullptr){
      right->insert(x);
    }else{
      AVL_Tree *new_right = new AVL_Tree(x);
      right = new_right;
      //balance
    }
  }
} 

// remove element x
void AVL_Tree::remove(const Tree & x){

}

//AVL Helper Functions:
//Rotations