// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinaryNode.cpp */

#include "BinaryNode.h"
#include <cstddef>

//--------------------- Constructors ---------------------
template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
      : item(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
      : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                    std::shared_ptr<BinaryNode<ItemType>> 
leftPtr,
                                    std::shared_ptr<BinaryNode<ItemType>> 
rightPtr)
      : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{ } 

//--------------------- setItem ---------------------
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
}

//--------------------- getItem ---------------------
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const 
{
   return item;
}

//--------------------- isLeaf ---------------------
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

//--------------------- setLeftChildPtr ---------------------
template<class ItemType>
void 
BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> 
leftPtr)
{
   leftChildPtr = leftPtr;
}

//--------------------- setRightChildPtr ---------------------
template<class ItemType>
void 
BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> 
rightPtr)
{
   rightChildPtr = rightPtr;
}

//--------------------- setLeftChildPtr ---------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() 
const
{
   return leftChildPtr;
}

//--------------------- setRightChildPtr ---------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNode<ItemType>::getRightChildPtr() const
{
   return rightChildPtr;
}
