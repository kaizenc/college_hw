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
  list<Tree> result;
  //figure out how to search without looking through every node in the tree
  return result;
}


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
  if(left != nullptr){
    left->clear();
  }
  if (right != nullptr){
    right->clear();
  }
  left = nullptr;
  right = nullptr;
}
// insert element x
void AVL_Tree::insert(const Tree & x){
  if(x < actual_tree){
    if(left != nullptr){
      left->insert(x);
    }else{
      AVL_Tree *new_left = new AVL_Tree(x);
      left = new_left;
    }
  }else if (actual_tree < x){
    if(right != nullptr){
      right->insert(x);
    }else{
      AVL_Tree *new_right = new AVL_Tree(x);
      right = new_right;
    }
  }
  number_of_nodes += 1;
  balance();
} 

// remove element x
void AVL_Tree::remove(const Tree & x){
  if(x < actual_tree){
    left->remove(x);
    return;
  }
  if(actual_tree < x){
    right->remove(x);
    return;
  }
  AVL_Tree* leftmost = right->getLeftmost();
  //insert tree into pointer
  balance();
}


bool AVL_Tree::hasLeft(){
  return left==nullptr;
}
bool AVL_Tree::hasRight(){
  return right==nullptr;
}
//AVL Helper Functions:
AVL_Tree* AVL_Tree::getLeftmost(){
  if(left->hasLeft()){
    return left->getLeftmost();
  }
  AVL_Tree* temp = left;
  delete left;
  left = nullptr;
  return temp;
}
int AVL_Tree::getHeight(){
  if(left == nullptr && right == nullptr){
    return 0;
  }
  int left_height = 0;
  int right_height = 0;
  if(left != nullptr){
    left_height = 1 + left->getHeight();
  }
  if(right != nullptr){
    int right_height = 1 + right->getHeight();
  }
  return (left_height>right_height)?left_height:right_height;
}
int AVL_Tree::getCount(){
  return number_of_nodes;
}
AVL_Tree* AVL_Tree::getRight(){
  return right;
}
AVL_Tree* AVL_Tree::getLeft(){
  return left;
}

//Rotations
void AVL_Tree::balance(){
  if(left->getHeight() - right->getHeight() > 2){
    if(left->getLeft()->getHeight() >= left->getRight()->getHeight()){
      LL_Rotation(this);
    }else{
      LR_Rotation(this);
    }
  }else if(right->getHeight() - left->getHeight() > 2){
    if(right->getRight()->getHeight() >= right->getRight()->getHeight()){
      RR_Rotation(this);
    }else{
      RL_Rotation(this);
    }
  }
}

void LL_Rotation(AVL_Tree* k2){
  AVL_Tree* k1 = k2->left;
  k2->left = k1->getRight();
  k1->right = k2;
  k2 = k1;
}
void RR_Rotation(AVL_Tree* k2){
  AVL_Tree* k1 = k2->right;
  k2->right = k1->getLeft();
  k1->left = k2;
  k2 = k1;
}
void RL_Rotation(AVL_Tree* A){
  AVL_Tree* C = A->right->left;
  AVL_Tree* B = A->right;
  B->left = C->right;
  A->right = C->left;
  C->left = A;
  C->right = B;
  A = C;
}
void LR_Rotation(AVL_Tree* A){
  AVL_Tree* B = A->left;
  AVL_Tree* C = A->left->right;
  B->right = C->left;
  A->left = C->right;
  C->right = A;
  C->left = C;
  A = C;
}