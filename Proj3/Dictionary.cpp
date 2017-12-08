#include <iostream>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

//---------------Node Class Definitions--------------//
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(){
	left = NULL;
	right = NULL;
	item = 0;
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType>::Node(KeyType new_key){
	left = NULL;
	right = NULL;
	key = new_key;
	item = 0;
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
	return left; //returns reference to node that pointer is pointing to
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
ItemType & Dictionary<KeyType, ItemType>::operator[](KeyType key){
	Node<KeyType, ItemType> * node = search(head, key);
	if (node == NULL){		
		Node<KeyType, ItemType> new_node(key);
		head = insert(head, new_node);
		node = search(head, key);		
		return new_node.getItem();
	}
	return node->getItem();
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::search(Node<KeyType,ItemType> * curr, KeyType key){		
	if(curr == NULL) return curr;
	
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
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::insert(Node<KeyType,ItemType> * curr, Node<KeyType,ItemType> node){
	if(curr == NULL){
		Node<KeyType, ItemType> * new_node = &node;
		return new_node;
	}
	
	KeyType curr_key = curr->getKey();
	KeyType key = node.getKey();
	if(key < curr_key) curr->setLeft(insert(curr->getLeft(), node));
	else if(key > curr_key) curr->setRight(insert(curr->getRight(), node));
	return curr;
}

//----------------Main Function Test---------------//

int main(){    
    Node<string, int> node("potato",3);    
    Node<string, int> node2("apple",2);  
    Dictionary<string, int> container(&node);
    
    //container["potato"] = 2;
    //container["potato"] += 2;
    //container["quasi"] = 0;
    container["quasi"] = 4;
    
    //cout << container["potato"] << endl;
    cout << container.head->getRight()->getItem() << endl;


    container["quasi"] = 3;

    cout << container.head->getRight()->getItem() << endl;
    cout << container["quasi"] << endl;
}
