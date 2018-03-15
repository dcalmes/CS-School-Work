// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "lib/BagInterface.h"
#include "lib/Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
  private:
     Node<ItemType>* headPtr; // Pointer to first node
     int itemCount;           // Current count of bag items
   
     // Returns either a pointer to the node containing a given entry
     // or the null pointer if the entry is not in the bag.
     Node<ItemType>* getPointerTo(const ItemType& target) const;
   
  public:
     LinkedBag();
     LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
     virtual ~LinkedBag();                       // Virtual destructor
     int getCurrentSize() const;
     bool isEmpty() const;
     bool add(const ItemType& newEntry);
     bool remove(const ItemType& anEntry);
     void clear();
     bool contains(const ItemType& anEntry) const;
     int getFrequencyOf(const ItemType& anEntry) const;
     std::vector<ItemType> toVector() const;
	 void spellCheck(LinkedBag<ItemType>& checkWords, LinkedBag<ItemType>& incorrectBag);
};

#include "pgm3bag.cpp"
#endif
