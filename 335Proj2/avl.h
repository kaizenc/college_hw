/*******************************************************************************
  Title          : avl.h
  Author         : Kaizen Castanos
  Created on     : March 11, 2018
  Description    : 
  Purpose        : 
  Usage          : 
  Build with     : No building
  Modifications  : Modified for Project 2
 
*******************************************************************************/

#ifndef __AVL_H__
#define __AVL_H__
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "tree.h"

class AVL_Tree{
    private:
        Tree actual_tree;
        AVL_Tree* left;
        AVL_Tree* right;
        //Node, left, and right....?
    public:
        AVL_Tree (); // default
        AVL_Tree (const Tree & tree); //Constructor with tree as param
        AVL_Tree (const AVL_Tree & tree); // copy constructor
        ~AVL_Tree (); // destructor
        // Search methods :
        const Tree & find (const Tree & x) const ;
        const Tree & findMin () const ;
        const Tree & findMax () const ;
        list<Tree>& findallmatches (const Tree & x) const ;
        // Traversals :
        // prints the Tree objects onto the ostream using inorder traversal .
        // Each of the members of the Tree object is printed , in the exact
        // same order as they are above , e . g . , with the tree spc_common name
        // first , then the tree_id . Fields should be separated by commas
        // in the output stream .
        void print ( ostream & out ) const ; // prints the Tree objects
        // Methods to consider adding - getting all trees in a zipcode ,
        // or near a given point
        // Tree modifiers :
        void clear (); // empty the tree
        void insert ( const Tree & x ); // insert element x
        void remove ( const Tree & x ); // remove element x
};

#endif /* __AVL_H__ */