// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-1    @file ArrayStack.cpp */
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file

// -------------------------------------
//         Default constructor
// -------------------------------------
template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{ }

// Copy constructor and destructor are supplied by the compiler

// -------------------------------------
//             isEmpty
// -------------------------------------
template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{  return top < 0;  } 

// -------------------------------------
//             push
// -------------------------------------
template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
   bool result = false;	
   if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
   {
      top++;
      items[top] = newEntry;
      result = true;
   }
   
   return result;
}

// -------------------------------------
//              pop
// -------------------------------------
template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
   bool result = false;
   if (!isEmpty())
   {
      top--;
      result = true;
   }
   
   return result;
}

// -------------------------------------
//             peek
// -------------------------------------
template<class ItemType> 
ItemType ArrayStack<ItemType>::peek() const
{
   assert(!isEmpty());  // Enforce precondition
   
   // Stack is not empty; return top
   return items[top];
}  


