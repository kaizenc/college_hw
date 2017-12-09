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
ItemType & Dictionary<KeyType, ItemType>::operator[](KeyType key){
	Node<KeyType, ItemType> * node = search(head, key);
	if (node == NULL){			
		head = insert(head, key);
		node = search(head, key);
	}
	ItemType & result = node->getItem();
	delete node;
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
		cout << "went left" << endl;	
		return search(curr->getLeft(), key);
	}	
	return search(curr->getRight(), key);
}

template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::insert(Node<KeyType,ItemType> * curr, KeyType key){
	if(curr == NULL){		
		Node<KeyType, ItemType> new_node(key);		
		Node<KeyType, ItemType> * node = &new_node;
		return node;
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

	//Dictionary<string, int> container(&node);
	Dictionary<string, int> container;	
	
	//cout << container["potato"] << endl;	
	//container["potato"] += 3;
	//cout << container["potato"] << endl;
	container.head = container.insert(container.head, "a");
	container.head->getItem() = 2;
	cout << container.head->getItem() << endl;
	cout << container.search(container.head, "a")->getItem() << endl;
	//container["a"] = 2;
}
