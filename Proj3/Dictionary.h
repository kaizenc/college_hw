#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class KeyType, class ItemType>
class Node{
    Node<KeyType,ItemType> *left;
    Node<KeyType,ItemType> *right;
    KeyType key;
    ItemType item;
  public:
    Node();
    void operator=(ItemType item);
    ItemType getItem();
};

template<class KeyType, class ItemType>
class Dictionary{
    Node<KeyType,ItemType> *head; //basically the tree
    int height;
    int size;

    int Height_Helper(Node<KeyType,ItemType>* node);
    Node<KeyType,ItemType> * search(KeyType key);
  public:
    Dictionary(); //Constructor
    bool IsEmpty(); //returns true if container is empty
    void Clear(); //removes all items and leaves container empty
    int Size(); //returns number of items
    int Height(); //returns height of BST
    int Count(KeyType key); //returns 1 if exists, 0 if otherwise, aka search
    ItemType* operator[](KeyType key); //returns reference to item with key - should also create if DNE
    
    void Remove(KeyType key);
    void Balance();
};
/*
IsEmpty is true if Node is a null pointer
Clear recursively goes through the BST and deletes the pointers (go to the bottom, when bottom is done, do top)
Size should just keep track of size
Count is just a search, as is operator[]

*/
#endif