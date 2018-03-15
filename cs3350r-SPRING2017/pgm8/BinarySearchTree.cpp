// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 
using namespace std;

//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//                      placeNode
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr,
                                                                
std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      if (subTreePtr->getItem() > newNodePtr->getItem())
         subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), 
         newNodePtr));
      else 
         subTreePtr->setRightChildPtr
         (placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
       
      return subTreePtr;
   } 
} 

//------------------------------------------------------------
//                    removeValue (recursive)
// Removes the given target value from the tree while maintaining a
// binary search tree.
// Called by: remove
// Calls: removeNode (if target is found)
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>
::removeValue(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr,const ItemType target, bool& success)
{
   if (subTreePtr == nullptr)           
   {
      // Not found here
      success = false;
      return subTreePtr;
   }
   if (subTreePtr->getItem() == target)
   {
      // Item is in the root of some subtree
      subTreePtr = removeNode(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      if (subTreePtr->getItem() > target)
      {
         // Search the left subtree
         subTreePtr->setLeftChildPtr
         (removeValue(subTreePtr->getLeftChildPtr(), target, success));
      }
      else
      {
         // Search the right subtree
         subTreePtr->setRightChildPtr
         (removeValue(subTreePtr->getRightChildPtr(), target, success));
      }
      return subTreePtr;
   } 
} 

//------------------------------------------------------------
//                   removeNode
// Removes a given node from a tree while maintaining a
// binary search tree.
// Called by: removeValue (after target is found)
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> 
nodePtr)
{
   // Case 1) Node is a leaf - it is deleted
   if (nodePtr->isLeaf())
   {
      nodePtr.reset();
      return nodePtr; // delete and return nullptr
   }
   
   // Case 2) Node has one child - parent adopts child
   else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
   {
      return nodePtr->getRightChildPtr();
   }
   else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
   {
      return nodePtr->getLeftChildPtr();
   }
   
   // Case 3) Node has two children:
   else                                             // Has two children
   {
      // Traditional way to remove a value in a node with two children
      // Find successor node.
      ItemType newNodeValue;
      nodePtr->setRightChildPtr
         (removeLeftmostNode(nodePtr->getRightChildPtr(), 
          newNodeValue));
      nodePtr->setItem(newNodeValue);
      return nodePtr;
   }
} 

//------------------------------------------------------------
//                removeLeftmostNode
// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
//------------------------------------------------------------
template<class ItemType> 
std::shared_ptr<BinaryNode<ItemType>> 
BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> 
nodePtr,
                                                                     
ItemType& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == nullptr)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode
         (nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }    
}

//------------------------------------------------------------
//                     findNode
// Returns a pointer to the node containing the given value,
// or nullptr if not found.
// Override findNode because now we can use a binary search:
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>
   ::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
     const ItemType& target) const 
{
   // Uses a binary search 
   if (subTreePtr == nullptr)
      return subTreePtr;                        // Not found
   else if (subTreePtr->getItem() == target)  
      return subTreePtr;                     // Found
   else if (subTreePtr->getItem() > target)
      // Search left subtree
      return findNode(subTreePtr->getLeftChildPtr(), target);
   else
      // Search right subtree
      return findNode(subTreePtr->getRightChildPtr(), target);
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//               Default constructor
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{   }

//------------------------------------------------------------
//               Second constructor
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{  } 

//------------------------------------------------------------
//                 Copy constructor
// Calls: copyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const 
BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}

//------------------------------------------------------------
//                   Destructor
// Calls: destroyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//                    isEmpty
//------------------------------------------------------------
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
   return rootPtr == nullptr;
} 

//------------------------------------------------------------
//                   getHeight
// Calls: getHeightHelper (inhrited, recursive) 
//------------------------------------------------------------
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
   return this->getHeightHelper(rootPtr);
} 

//------------------------------------------------------------
//                  getNumberOfNodes
// Calls: getNumberOfNodesHelper (inherited, recursive) 
//------------------------------------------------------------
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
   return this->getNumberOfNodesHelper(rootPtr);
}

//------------------------------------------------------------
//                      clear
// Calls: destroyTree (inherited, recursive)
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
   this->destroyTree(rootPtr);
   rootPtr.reset();
}

//------------------------------------------------------------
//                    getRootData
//------------------------------------------------------------
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const 
throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("getRootData() called with empty tree."); 
   
   return rootPtr->getItem();
}

//------------------------------------------------------------
//                    setRootData
// Must override setRootData to disable its affect
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const 
throw(PrecondViolatedExcep)
{
   throw PrecondViolatedExcep("Cannot change root value in a BST!");
} 

//------------------------------------------------------------
//                      add
// Calls: insertInorder
//------------------------------------------------------------
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = placeNode(rootPtr, newNodePtr);
   
   return true;
}

//------------------------------------------------------------
//                      remove
// Calls: removeValue
//------------------------------------------------------------
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   // call may change isSuccessful
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}

//------------------------------------------------------------
//                   getEntry
// Override getEntry to use our improved findNode
// Calls: findNode
//------------------------------------------------------------
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const 
throw(NotFoundException)
{
   std::shared_ptr<BinaryNode<ItemType>> nodeWithEntry 
      = findNode(rootPtr, anEntry);
   if (nodeWithEntry == nullptr)
      throw NotFoundException("Entry not found in tree.");
   else
      return nodeWithEntry->getItem();
}

//------------------------------------------------------------
//                  contains
// Override contains to use our improved findNode
// Calls: findNode
//------------------------------------------------------------
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
   // nullptr same as false
   return (findNode(rootPtr, anEntry) == nullptr);  
} 

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//               preorderTraverse (inherited)
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) 
const
{
   this->preorder(visit, rootPtr); // Call inherited method
}

//------------------------------------------------------------
//               inorderTraverse (inherited)
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   this->inorder(visit, rootPtr); // Call inherited method
}

//------------------------------------------------------------
//               postorderTraverse (inherited)
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) 
const
{
   this->postorder(visit, rootPtr); // Call inherited method
}

//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//                        operator=
// Calls: copyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
                            operator=(const BinarySearchTree<ItemType>& 
rightHandSide)
{
   if (!isEmpty())
      clear();
   this = copyTree(&rightHandSide); // Call inherited method
   
   return *this;
}

//////////////////////////////////////////////////////////////
//      Replacement Algorithm
//    This code will search to see if the node you are
//    looking for exists.  If so, it will find the node
//    and replace it with the item you want to replace. 
//////////////////////////////////////////////////////////////
template<class ItemType>
bool BinarySearchTree<ItemType>::replace(const ItemType& item, const ItemType& itemReplace) const
{
   bool isSuccessful = false;	// Set isSuccessful to false

   // Jump into the if statment to replace item if the list contains said item
   if(contains(item) == true)
   {
       isSuccessful = true;
       std::shared_ptr<BinaryNode<ItemType>> nodeWithEntry = findNode(rootPtr, item);	// Call to find the node in which the item exists
       removeValue(nodeWithEntry, item, isSuccessful);	// Call to remove item you want to remove
       add(itemReplace);	// Call add to add itemReplace
       return true;
   }
   else 
   {
	   // Let user know that the item does not exist if contains doesnt equal true
      cout << "This item does not exist" << endl;
      return false;
   }
   
}
//------------------------------------------------------------
//                        iterators
// start(), end()
//------------------------------------------------------------
/*
template<class ItemType>
BinarySearchTreeIterator<ItemType> BinarySearchTree<ItemType>::start() {
	return BinarySearchTreeIterator<ItemType>(this, rootPtr);
}

template<class ItemType>
BinarySearchTreeIterator<ItemType> BinarySearchTree<ItemType>::end() {
	return BinarySearchTreeIterator<ItemType>(this, nullptr);
}
*/

//------------------------------------------------------------
//                       Unused code
//------------------------------------------------------------
      // Alternative way to remove a value in a node with two children
      //   Find successor value and replace node's value
      //   Does not need pass-by-reference
      // Check whether this right child has a left child.
      //   Similar to base case in "findSuccessorValue" but need to remove
      //   special case where the right child *is* the inorder successor
      /* --------
      std::shared_ptr<BinaryNode<ItemType>> myRightChildPtr = 
         nodePtr->getRightChildPtr();
      std::shared_ptr<BinaryNode<ItemType>> myLeftGrandChildPtr = 
         myRightChildPtr->getLeftChildPtr();
      
      // Special case - right child is successor
      if (myLeftGrandChildPtr == nullptr) 
      {
         nodePtr->setItem(myRightChildPtr->getItem());
         nodePtr->setRightChildPtr(removeNode(myRightChildPtr));
         return nodePtr;
      } 
      else 
      {
         // Now we can recurse
         nodePtr->setItem(findSuccessorValue(nodePtr->getRightChildPtr()));
         return nodePtr;
      }
         -------- */

/* ----------
template<class ItemType>ItemType 
BinarySearchTree<ItemType>::findSuccessorValue
(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
   std::shared_ptr<BinaryNode<ItemType>> myLeftChildPtr = 
subTreePtr->getLeftChildPtr();
   if (myLeftChildPtr->getLeftChildPtr() == nullptr) {
      ItemType nodeItemValue = myLeftChildPtr->getItem();
      subTreePtr->setLeftChildPtr(removeNode(myLeftChildPtr));
      return nodeItemValue;
   }
   else 
   {
      return findSuccessorValue(subTreePtr->getLeftChildPtr());
   }  // end if  
}
   ------- */


