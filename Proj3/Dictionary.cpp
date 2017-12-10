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
	left = NULL;
	right = NULL;
	key = new_key;	
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(KeyType new_key, ItemType new_item){
	left = NULL;
	right = NULL;
	key = new_key;
	item = new_item;
}


template<class KeyType, class ItemType>
ItemType & Node<KeyType,ItemType>::getItem(){
	return item;
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
void Node<KeyType,ItemType>::setLeft(Node<KeyType,ItemType> * node){
	left = node;	
}
template<class KeyType, class ItemType>
void Node<KeyType,ItemType>::setRight(Node<KeyType,ItemType> * node){
	right = node;	
}






//------------Dictionary Class Definitions-----------//
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(){	
	size = 0;
	head = NULL;
}
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(Node<KeyType,ItemType> * node){	
	size = 1;
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
int Dictionary<KeyType, ItemType>::Count(KeyType key){
	return (search(head, key)==NULL)?0:1;
}


template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height(){
	return Height_Helper(head)-1;
}
template<class KeyType, class ItemType>
int Dictionary<KeyType, ItemType>::Height_Helper(Node<KeyType,ItemType>* node){
	if(node == NULL) return 0;
	int result = 1;
	if(!(node->getLeft() == NULL and 	node->getRight() == NULL)){
		result+= max(Height_Helper(node->getLeft()), Height_Helper(node->getRight()));
	}
	return result;
}

template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Clear(){
	if(head->getLeft() != NULL) Clear_Helper(head->getLeft());
	if(head->getRight() != NULL) Clear_Helper(head->getRight());
	//delete head;
	head = NULL;
}
template<class KeyType, class ItemType>
void Dictionary<KeyType, ItemType>::Clear_Helper(Node<KeyType,ItemType>* node){
	if(node->getLeft() == NULL and node->getRight() == NULL){
		delete node;
		node = NULL;
	}else{
		if(node->getLeft() != NULL) Clear_Helper(node->getLeft());
		if(node->getRight() != NULL) Clear_Helper(node->getRight());
		delete node;
		node = NULL;
	}
}


template<class KeyType, class ItemType>
ItemType & Dictionary<KeyType, ItemType>::operator[](KeyType key){
	Node<KeyType, ItemType> * node = search(head, key);
	if (node == NULL){			
		head = insert(head, key);
		size++;
		node = search(head, key);
	}
	ItemType & result = node->getItem();
	return result;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::search(Node<KeyType,ItemType> * curr, KeyType key){		
	if(curr == NULL){		
		return curr;
	}
	KeyType curr_key = curr->getKey();	
	if(curr_key == key){		
		return curr;
	}
	
	if(key < curr_key){	
		return search(curr->getLeft(), key);
	}	
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

//----------------Main Function Test---------------//

int main(){	
	Node<string, int> node("potato",3);	
	Node<string, int> node2("apple",2);  

	Dictionary<string, int> container(&node);
	Dictionary<string, int> container2;	
	
	container["banana"] = 4;
	container["apple"] = 3;
	container["apple"] += 1;
	container["carrot"] = 5;
	
	cout << container["apple"] << endl;
	cout << container.Height() << endl;
	cout << container.Count("carrot") << endl;
	cout << container.Count("karrot") << endl;
	container.Clear();
}
