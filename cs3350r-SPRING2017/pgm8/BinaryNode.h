// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 
#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode
{   
private:
   ItemType              item;                           // Data portion
   std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;   // Pointers to 
   std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;  // left, right child

public:
   BinaryNode();
   BinaryNode(const ItemType& anItem);
   BinaryNode(const ItemType& anItem,
              std::shared_ptr<BinaryNode<ItemType>> leftPtr,
              std::shared_ptr<BinaryNode<ItemType>> rightPtr);

   void setItem(const ItemType& anItem);
   ItemType getItem() const;
   
   bool isLeaf() const;

   std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
   std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;
   
   void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
   void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
}; // end BinaryNode

#include "BinaryNode.cpp"
#endif
