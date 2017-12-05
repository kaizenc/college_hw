#include <iostream>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

//---------------Node Class Definitions--------------//
template<class KeyType, class ItemType>
ItemType Node<KeyType,ItemType>::getItem(){
	return item;
}

//------------Dictionary Class Definitions-----------//
template<class KeyType, class ItemType>
Dictionary<KeyType,ItemType>::Dictionary(){
    height = 0;
    size = 0;
    head = NULL;
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
ItemType* Dictionary<KeyType, ItemType>::operator[](KeyType key){
	return search(key)->getItem();
}
template<class KeyType, class ItemType>
Node<KeyType,ItemType> * Dictionary<KeyType, ItemType>::search(KeyType key){
	return NULL;
}

//----------------Main Function Test---------------//
int main(){
    //
}