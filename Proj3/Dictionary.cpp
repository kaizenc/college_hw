#include <iostream>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

//---------------Node Class Definitions--------------//
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(){
	left = NULL;
	right = NULL;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(KeyType new_key){
	Node();
	key = new_key;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(KeyType new_key, ItemType new_item){
	Node();
	key = new_key;
	item = new_item;
}

template<class KeyType, class ItemType>
ItemType * Node<KeyType,ItemType>::getItem(){
	return &item;
}
template<class KeyType, class ItemType>
KeyType Node<KeyType,ItemType>::getKey(){
	return key;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Node<KeyType,ItemType>::getLeft(){
	return left;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Node<KeyType,ItemType>::getRight(){
	return right;
}
template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::operator=(ItemType new_item){
	item = new_item;
}

//------------Dictionary Class Definitions-----------//
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(){
    height = 0;
    size = 0;
    head = NULL;
}

template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(Node<KeyType,ItemType> * node){
	height = 0;
    size = 0;
    head = node;
}

template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Size(){
	return size;
}

template<class KeyType, class ItemType>
bool Dictionary<KeyType, ItemType>::IsEmpty(){
	return head == NULL;
}

template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height(){
	return Height_Helper(head);
}
template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height_Helper(Node<KeyType,ItemType>* node){
	if(node == NULL) return 0;
	int result = 0;
	if(node->left == NULL and 	node->right == NULL){
		return 1;
	}else{
		result+= max(Height_Helper(node->left), Height_Helper(node->right));
	}
	return result;
}



template<class KeyType, class ItemType>
ItemType & Dictionary<KeyType, ItemType>::operator[](KeyType key){
	Node<KeyType,ItemType> * node = search(head, key);
	if(node == NULL){
		node = Node<KeyType,ItemType>(key);
		insert(node);
		return node;
	}
	return node;	
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::search(Node<KeyType,ItemType>* curr, KeyType key){
	if(curr == NULL) return NULL;
	Node<KeyType,ItemType> * left = NULL;
	Node<KeyType,ItemType> * right = NULL;

	if(key == curr->getKey()){
		return curr;
	}else if(key < curr->getKey()){
		if(curr->getLeft() != NULL){
			left = search(curr->getLeft(), key);
		}
	}else{
		if(curr->getRight() != NULL){				
			right = search(curr->getRight(), key);
		}
	}
	if(left!=NULL) return left;
	if(right!=NULL) return right;
	return NULL;
}
template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::insert(Node<KeyType,ItemType>* curr, Node<KeyType,ItemType>* node){
	if(curr == NULL) curr = node;
	if(node->getKey() <= curr->getKey()){
		if(curr->getLeft() == NULL){
			curr->getLeft() = node;
		}else{
			insert(curr->getLeft(), node);
		}
	}else{
		if(curr->getRight() == NULL){
			curr->getRight() = node;
		}else{
			insert(curr->getRight(), node);
		}
	}
}

//----------------Main Function Test---------------//
int main(){    
    Node<string, int> node("potato",3);    
    Dictionary<string, int> container(&node);

   int a = container["potato"];
}