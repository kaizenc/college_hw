#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <iostream>
#include <string>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

///////////////////////////////////////////////////////
//---------------Node Class Definitions--------------//
///////////////////////////////////////////////////////
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(){
	left = NULL;
	right = NULL;	
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(const KeyType &new_key){
	left = NULL;
	right = NULL;
	key = new_key;	
}


template<class KeyType, class ItemType>
ItemType & Node<KeyType,ItemType>::getItem(){
	return item;
}
template<class KeyType, class ItemType>
KeyType & Node<KeyType,ItemType>::getKey(){
	return key;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Node<KeyType,ItemType>::getLeft() const{
	return left;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Node<KeyType,ItemType>::getRight() const{
	return right;
}


template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setLeft(Node<KeyType,ItemType> * node){
	left = node;	
}
template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setRight(Node<KeyType,ItemType> * node){
	right = node;	
}



///////////////////////////////////////////////////////
//------------Dictionary Class Definitions-----------//
///////////////////////////////////////////////////////
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(){	
	size = 0;
	head = NULL;
}
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::~Dictionary(){
	Clear();
}


template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Size(){
	return size;
}
template<class KeyType, class ItemType>
bool Dictionary<KeyType, ItemType>::IsEmpty() const{
	return head == NULL;
}
template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Count(KeyType key){
	return (search(head, key)==NULL)?0:1;
}


template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height(){
	return (Height_Helper(head)==0)?0:Height_Helper(head)-1;
}
template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height_Helper(Node<KeyType,ItemType>* node){
	//returns a result built up through recursion
	if(node == NULL) return 0;
	int result = 1;
	if(!(node->getLeft() == NULL and node->getRight() == NULL)){
		result+= max(Height_Helper(node->getLeft()), Height_Helper(node->getRight()));
	}
	return result;
}


template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Clear(){
	//recursively delete
	if(head == NULL) return;
	if(head->getLeft() != NULL) Clear_Helper(head->getLeft());
	if(head->getRight() != NULL) Clear_Helper(head->getRight());
	delete head;
	head = NULL;
	size = 0;
}
template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Clear_Helper(Node<KeyType,ItemType>* node){
		if(node->getLeft() != NULL) Clear_Helper(node->getLeft()); //delete left and right before deleting self
		if(node->getRight() != NULL) Clear_Helper(node->getRight());
		delete node;
		node = NULL;
}


template<class KeyType, class ItemType>
ItemType & Dictionary<KeyType, ItemType>::operator[](KeyType key){
	Node<KeyType, ItemType> * node = search(head, key); //looks for the node
	if (node == NULL){ //if the node isn't there
		head = insert(head, key); //inserts the node
		size++; //increment size
		node = search(head, key); //searches for the node again
	}
	return node->getItem(); //return reference to item
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::search(Node<KeyType,ItemType> * curr, KeyType key){		
	if(curr == NULL) return curr;

	KeyType curr_key = curr->getKey();	
	if(curr_key == key) return curr;
	
	if(key < curr_key) return search(curr->getLeft(), key);	
	return search(curr->getRight(), key);
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::insert(Node<KeyType,ItemType> * curr, KeyType key){
	if(curr == NULL){		
		Node<KeyType, ItemType> * new_node = new Node<KeyType, ItemType>(key);
		return new_node;
	}
	
	KeyType curr_key = curr->getKey();
	if(key < curr_key){
		Node<KeyType, ItemType> * node = insert(curr->getLeft(), key);	
		curr->setLeft(node);
	}else if(key > curr_key){
		Node<KeyType, ItemType> * node = insert(curr->getRight(), key);
		curr->setRight(node);
	}
	return curr;
}


template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Balance(){
	Node<KeyType, ItemType> ** arr = new Node<KeyType, ItemType>*[size]; //array of node pointers
	int * counter = new int(0); //save counter in memory
	Fill_Array(head, arr, *counter); //pre-order transversal, will also set left/right to NULL for each	
	head = BalanceByArray(head, arr, 0, size-1); // will recursively set tree using the array
	
	//prevent memory leak
	delete [] arr;
	arr = NULL;
	delete counter;
	counter = NULL;
}
template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Fill_Array(Node<KeyType, ItemType>* curr, Node<KeyType, ItemType>** arr, int &counter){
	if (curr == NULL) return;
	if (curr->getRight() == NULL and curr->getLeft() == NULL){ //if you can't recurse any further...
		arr[counter] = curr; //insert node
		counter++; //increment counter
		curr->setLeft(NULL); //nullify left and right pointers
		curr->setRight(NULL);
		return;
	}
	Fill_Array(curr->getLeft(), arr, counter); //recurse left...
	arr[counter] = curr; //then insert...
	counter++; //increment counter...
	Fill_Array(curr->getRight(), arr, counter); //then recurse right...
	curr->setLeft(NULL); //nullify left and right pointers
	curr->setRight(NULL);
}
template<class KeyType, class ItemType>
Node<KeyType, ItemType> * Dictionary<KeyType, ItemType>::BalanceByArray(Node<KeyType, ItemType> * curr, Node<KeyType, ItemType>** arr, int small, int large){
	if (small > large) return NULL;
	int mid = (small+large)/2;
	
	Node<KeyType, ItemType> * node = arr[mid]; //return this node after setting its left and right

	node->setLeft(BalanceByArray(node->getLeft(), arr, small, mid-1)); //if there's nothing left, left is set to null
	node->setRight(BalanceByArray(node->getRight(), arr, mid+1, large)); //same for right

	return node;
}


template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Remove(KeyType key){
	Node<KeyType, ItemType> * child = search(head, key);
	if (child == NULL) return; //Node DNE
	Node<KeyType, ItemType> * parent = searchParent(head, key);
	if (parent == NULL){ //removing the root/head
		Node<KeyType, ItemType> * temp = head;
		if(head->getRight() != NULL){ //if right exists
			getLeftmost(head->getRight())->setLeft(head->getLeft());
			head = head->getRight();
		}else{
			head = head->getLeft();
		}
		delete temp;
		size-=1;
		return;
	}
	
	if(parent->getRight() == child){//if the child is on the right
		if(child->getRight() != NULL){//if the child's right exists
			parent->setRight(child->getRight());//set the parents right to the child's right
			getLeftmost(child->getRight())->setLeft(child->getLeft());//set the child's left to the new parent's right's left
		}else{//the child's right is null
			parent->setRight(child->getLeft());//replace child with its left
		}
	}else{//if the child is on the left, same process, but every parent->setRight is now left
		
		if(child->getRight() != NULL){
			parent->setLeft(child->getRight());
			getLeftmost(child->getRight())->setLeft(child->getLeft());
		}else{
			parent->setLeft(child->getLeft());
		}
	}
	delete child; //prevent memory leaks
	child = NULL;
	size-=1;	//decrement size
}
template<class KeyType, class ItemType>
Node<KeyType, ItemType> * Dictionary<KeyType, ItemType>::searchParent(Node<KeyType, ItemType> * curr, KeyType key){
	//only returns the curr if one of its child's keys is equal to the key
	if(curr == NULL or curr->getKey() == key) return NULL;
	if(curr->getRight() != NULL and curr->getRight()->getKey() == key){
		return curr;
	}
	if(curr->getLeft() != NULL and curr->getLeft()->getKey() == key){
		return curr;
	}
	
	KeyType curr_key = curr->getKey();	
	
	if(key < curr_key) return searchParent(curr->getLeft(), key);	
	return searchParent(curr->getRight(), key);
}
template<class KeyType, class ItemType>
Node<KeyType, ItemType> * Dictionary<KeyType, ItemType>::getLeftmost(Node<KeyType, ItemType> * curr){
	//IN a tree, goes as far left as possible
	if(curr->getLeft() == NULL) return curr;
	return getLeftmost(curr->getLeft());
}
#endif
