// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "pgm3bag.h"
#include <cstddef>

// --------------------------------------------------
//                Default Constructor
// --------------------------------------------------
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}

// --------------------------------------------------
//                   Copy  Constructor
// --------------------------------------------------
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
   itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == NULL)
      headPtr = NULL;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != NULL)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(NULL);              // Flag end of chain
   }  // end if
}

// --------------------------------------------------
//                 Destructor
// --------------------------------------------------
template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}

// --------------------------------------------------
//                    isEmpty
// --------------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  

// --------------------------------------------------
//                 getCurrentSize
// --------------------------------------------------
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}  

// --------------------------------------------------
//                      add
// --------------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
}

// --------------------------------------------------
//                    toVector
// --------------------------------------------------
template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  
   
   return bagContents;
}

// --------------------------------------------------
//                    remove
// --------------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      nodeToDeletePtr = NULL;
      
      itemCount--;
   }
   
	return canRemoveItem;
}  

// --------------------------------------------------
//                    clear
// --------------------------------------------------
template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }                       // headPtr, nodeToDeletePtr now nullptr
   
   itemCount = 0;
}  

// --------------------------------------------------
//                  getFrequencyOf
// --------------------------------------------------
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
   return frequency;
}  

// --------------------------------------------------
//                    contains
// --------------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return (getPointerTo(anEntry) != nullptr);
}  


// --------------------------------------------------
//                    getPointerTo
// --------------------------------------------------
// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) 
const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   }
   
   return curPtr;
} 

template<class ItemType>
void LinkedBag<ItemType>::spellCheck(LinkedBag<ItemType>& checkWords, LinkedBag<ItemType>& incorrectBag)
{
	std::vector<std::string> word = checkWords.toVector();
	std::string storeWord;
	std::string Temp;

	for (unsigned int i = 0; i < checkWords.getCurrentSize(); i++)
	{
		if (!contains(word[i]))
		{
			storeWord = word[i];
			incorrectBag.add(storeWord);
		}
	}
}

// --------------------------------------------------
//                      add
//            ALTERNATE for 1st 3 lines
// --------------------------------------------------
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); 

// --------------------------------------------------
//                    contains
//            ALTERNATE 1 implementation
// --------------------------------------------------
/*
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/

// --------------------------------------------------
//                    contains
//            ALTERNATE 2 implementation
// --------------------------------------------------
// ALTERNATE 2 
/*
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/


