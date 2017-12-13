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
    Node(KeyType new_key);
    Node(KeyType new_key, ItemType new_item);

    ItemType & getItem();
    KeyType getKey();
    Node<KeyType,ItemType> * getLeft();
    Node<KeyType,ItemType> * getRight();
    void setLeft(Node<KeyType,ItemType> * node);
    void setRight(Node<KeyType,ItemType> * node);    
};

template<class KeyType, class ItemType>
class Dictionary{    
    int size;
    Node<KeyType,ItemType> *head; //basically the tree
    
    int Height_Helper(Node<KeyType,ItemType>* node);
    void Clear_Helper(Node<KeyType,ItemType>* node);
    Node<KeyType,ItemType> * search(Node<KeyType,ItemType> * curr, KeyType key);
    Node<KeyType,ItemType> * insert(Node<KeyType,ItemType> * curr, KeyType key);
    Node<KeyType, ItemType> * searchParent(Node<KeyType, ItemType> * curr, KeyType key);
    Node<KeyType, ItemType> * getLeftmost(Node<KeyType, ItemType> * curr);

    void Fill_Array(Node<KeyType, ItemType>* curr, Node<KeyType, ItemType>** arr, int & counter);
    Node<KeyType, ItemType> *  BalanceByArray(Node<KeyType, ItemType> * curr, Node<KeyType, ItemType>** arr, int small, int large);
  public:
    //Structors
    Dictionary();
    ~Dictionary();

    bool IsEmpty(); //DONE
    int Size(); //DONE
    int Count(KeyType key); //DONE
    int Height(); //DONE
    void Clear(); //?
    
    ItemType & operator[](KeyType key); //DONE
    
    void Remove(KeyType key); //DONE
    void Balance(); //DONE
};
#include "Dictionary.cpp"
#endif