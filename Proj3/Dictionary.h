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
    Node<KeyType,ItemType> * insert(Node<KeyType,ItemType> * curr, KeyType key); //recursive, node has to be placed below top
    void Fill_Array(Node<KeyType, ItemType>* arr);
    void BalanceByArray(Node<KeyType, ItemType> * curr, Node<KeyType, ItemType> * arr, int small, int large);
  public:
    //Constructors
    Dictionary();
    //REQUIRES DESTRUCTOR

    bool IsEmpty(); //returns true if container is empty
    int Size(); //returns number of items
    int Count(KeyType key); //returns 1 if exists, 0 if otherwise, aka search
    
    int Height(); //returns height of BST
    void Clear(); //removes all items and leaves container empty
    
    ItemType & operator[](KeyType key); //returns reference to item with key - should also create if DNE
    
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