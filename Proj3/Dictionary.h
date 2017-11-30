#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class KeyType, class ItemType>
class Dictionary{
    KeyType* keys;
    ItemType* items;
    int height;
  public:
    Dictionary();
    bool IsEmpty(); //returns true if container is empty
    void Clear(); //removes all items and leaves container empty
    int Size(); //returns number of items
    int Height(); //returns height of BST
    int Count(KeyType key); //returns number of items
    ItemType operator[](KeyType key); //returns reference to item with key - should also create
    
    void Remove(KeyType key);
    void Balance();
};