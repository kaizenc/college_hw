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
  root = nullptr;
}
AVL_Tree::AVL_Tree(const Tree & tree){
  root = nullptr;
  root->actual_tree = tree;
}
AVL_Tree::AVL_Tree (const AVL_Tree & tree){
  this->root = tree.root;
}
AVL_Tree::~AVL_Tree (){
  clear();
}

AVL_Node::AVL_Node(){
  right = nullptr;
  left = nullptr;
}
AVL_Node::AVL_Node(Tree tree){
  right = nullptr;
  left = nullptr;
  actual_tree = tree;
}
AVL_Node::~AVL_Node(){
  delete left;
  delete right;
  left = nullptr;
  right = nullptr;
}


//Search methods (wrapper functions)
const Tree & AVL_Tree::find (const Tree & x) const{
  root->find(x);
}
const Tree & AVL_Tree::findMin() const{
  root->findMin();
}
const Tree & AVL_Tree::findMax() const{
  root->findMax();
}
list<Tree>& AVL_Tree::findallmatches (const Tree & x) const{
  list<Tree> result;
  //figure out how to search without looking through every node in the tree
  root->search(x, result);
  return result;
}
void AVL_Node::search(const Tree & x, list<Tree> & result){
  if(x == actual_tree){
    result.push_back(actual_tree);
  }
  if(left != nullptr){
    left->search(x, result);
  }
  if(right != nullptr){
    right->search(x, result);
  }
}
//Search methods (node recursive)
const Tree & AVL_Node::find (const Tree & x) const{
  if(x == actual_tree){
    return actual_tree;
  }
  if(left != nullptr && x < actual_tree){
    return left->find(x);
  }else if(right != nullptr && actual_tree < x){
    return right->find(x);
  } //needs to return something if we can't find it
}
const Tree & AVL_Node::findMin() const{
  if(left != nullptr){
    return left->findMin();
  }
  return actual_tree;
}
const Tree & AVL_Node::findMax() const{
  if(right != nullptr){
    return right->findMax();
  }
  return actual_tree;
}

//inorder print
void AVL_Tree::print (ostream & out) const{
  root->print(out);
}
void AVL_Node::print (ostream & out) const{
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
  root->clear();
  delete root;
  root = nullptr;
}
void AVL_Node::clear(){
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
  if (root == nullptr){
    root = new AVL_Node(x);
    return;
  }
  root->insert(x);
}
void AVL_Node::insert(const Tree & x){
  if(x < actual_tree){
    if(left != nullptr){
      left->insert(x);
    }else{
      AVL_Node *new_left = new AVL_Node(x);
      left = new_left;
    }
  }else if (actual_tree < x){
    if(right != nullptr){
      right->insert(x);
    }else{
      AVL_Node *new_right = new AVL_Node(x);
      right = new_right;
    }
  }
  balance();
} 

// remove element x
void AVL_Tree::remove(const Tree & x){
  root->remove(x);
}
void AVL_Node::remove(const Tree & x){
  if(x < actual_tree){
    left->remove(x);
    return;
  }
  if(actual_tree < x){
    right->remove(x);
    return;
  }
  //AVL_Tree* leftmost = right->getLeftmost();
  //insert tree into pointer
  balance();
}


//AVL Helper Functions:
int AVL_Node::getHeight(){
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
void AVL_Node::getCount(int& counter) const{
  counter++;
  if(left!=nullptr){
    left->getCount(counter);
  }
  if(right!=nullptr){
    right->getCount(counter);
  }
}
int AVL_Tree::getCount() const{
  int counter = 0;
  root->getCount(counter);
  return counter;
}

//Rotations
void AVL_Node::balance(){
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


void LL_Rotation(AVL_Node* k2){
  AVL_Node* k1 = k2->getLeft();
  k2->setLeft(k1->getRight());
  k1->setRight(k2);
  k2 = k1;
}
void RR_Rotation(AVL_Node* k2){
  AVL_Node* k1 = k2->getRight();
  k2->setRight(k1->getLeft());
  k1->setLeft(k2);
  k2 = k1;
}
void RL_Rotation(AVL_Node* A){
  AVL_Node* C = A->getRight()->getLeft();
  AVL_Node* B = A->getRight();
  B->setLeft(C->getRight());
  A->setRight(C->getLeft());
  C->setLeft(A);
  C->setRight(B);
  A = C;
}
void LR_Rotation(AVL_Node* A){
  AVL_Node* C = A->getLeft()->getRight();
  AVL_Node* B = A->getLeft();
  B->setRight(C->getLeft());
  A->setLeft(C->getRight());
  C->setRight(A);
  C->setLeft(B);
  A = C;
}
/*
void LR_Rotation(AVL_Node* A){
  AVL_Node* B = A->left;
  AVL_Node* C = A->left->right;
  B->right = C->left;
  A->left = C->right;
  C->right = A;
  C->left = C;
  A = C;
}
*/