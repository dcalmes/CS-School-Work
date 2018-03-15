// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinaryNodeTree.cpp */

#include "BinaryNodeTree.h" 
#include "BinaryNode.h" 
#include <algorithm>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

//------------------------------------------------------------
//                   getHeightHelper
//               (protected, recursive)
// Called by: getHeight (public)
//------------------------------------------------------------
template<class ItemType>
int 
BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}

//------------------------------------------------------------
//                 getNumberOfNodesHelper 
//                 (protected, recursive)
// Called by: getNumberOfNodes (public)
//------------------------------------------------------------
template<class ItemType>
int 
BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) 
               + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

//------------------------------------------------------------
//                    balancedAdd (protected, recursive)
// Chooses location to add new node so that tree remains as balanced as
// possible. Always chooses to add the new node to the subtree
// of with the shorter height. If the heights are equal, it
// adds the new node as a leaf on the left subtree of the root.
// New node always added as a leaf.
//
// Calls: getHeightHelpter to get height of each subtree 
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr,
                                           
std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      auto rightPtr = subTreePtr->getRightChildPtr();
      
      if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
      {
         rightPtr = balancedAdd(rightPtr , newNodePtr);
         subTreePtr->setRightChildPtr(rightPtr );
      }
      else
      {
         leftPtr = balancedAdd(leftPtr, newNodePtr);
         subTreePtr->setLeftChildPtr(leftPtr);
      }  
      
      return subTreePtr;
   } 
} 

//------------------------------------------------------------
//                  moveValuesUpTree (protected)
// Called by: removeValue
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr)
{
   auto  leftPtr = subTreePtr->getLeftChildPtr();
   auto  rightPtr = subTreePtr->getRightChildPtr();
   int leftHeight = getHeightHelper(leftPtr);
   int rightHeight = getHeightHelper(rightPtr);
   if (leftHeight > rightHeight)
   {
      subTreePtr->setItem(leftPtr->getItem());
      leftPtr = moveValuesUpTree(leftPtr);
      subTreePtr->setLeftChildPtr(leftPtr);
      return subTreePtr;
   }
   else 
   {
      if (rightPtr != nullptr)
      {
         subTreePtr->setItem(rightPtr->getItem());
         rightPtr =moveValuesUpTree(rightPtr);         
         subTreePtr->setRightChildPtr(rightPtr);
         return subTreePtr;
      }
      else 
      {
         // This was a leaf!  Value not important
         return nullptr;
      }
   }  
} 

//------------------------------------------------------------
//                    removeValue (protected, recursive)
// Called by: remove
// Calls: moveValuesUpTree
/** Depth-first search of tree for item.
 @param subTreePtr  tree to search.
 @param target  target item to find.
 @param success  communicate to client we found it. 
 @returns  A pointer to node containing the item. */
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNodeTree<ItemType>::removeValue(
   std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
   const ItemType target,
   bool& success)
{
   if(subTreePtr == nullptr) // not found here
      return subTreePtr;

   if (subTreePtr->getItem() == target) // found it
   {
      subTreePtr = moveValuesUpTree(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(),
           target, success);
      subTreePtr->setLeftChildPtr(targetNodePtr);
      if (!success) // no need to search right subTree
      {
         targetNodePtr = removeValue(subTreePtr->getRightChildPtr(),
                            target, success);
         subTreePtr->setRightChildPtr(targetNodePtr);
      } 
      
      return subTreePtr;
   } 
}  

//------------------------------------------------------------
//                       findNode (protected, recursive)
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> 
treePtr,
                                                                  const 
ItemType& target,
                                                                  bool& 
success) const
{
   if (treePtr == nullptr) // not found here
      return treePtr;
   
   if (treePtr->getItem() == target) // found it
   {
      success = true;
      return treePtr;
   }
   else 
   {
      std::shared_ptr<BinaryNode<ItemType>> targetNodePtr = 
         findNode(treePtr->getLeftChildPtr(), target, success);
      if (!success) // no need to search right subTree
      {
         targetNodePtr = findNode(treePtr->getRightChildPtr(),
                            target, success);
      } 
      
      return targetNodePtr;
   } 
} 

//------------------------------------------------------------
//                       copyTree (protected, recursive)
//------------------------------------------------------------
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> 
BinaryNodeTree<ItemType>::copyTree(const 
std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
   std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
   
   // Copy tree nodes during a preorder traversal
   if (oldTreeRootPtr != nullptr)
   {
      // Copy node
      newTreePtr = std::make_shared<BinaryNode<ItemType>>
                   (oldTreeRootPtr->getItem(), nullptr, nullptr);
      newTreePtr->setLeftChildPtr
                   (copyTree(oldTreeRootPtr->getLeftChildPtr()));
      newTreePtr->setRightChildPtr
                   (copyTree(oldTreeRootPtr->getRightChildPtr()));
   } 
   
   return newTreePtr;
} 

//------------------------------------------------------------
//                       destroyTree (protected, recursive)
//------------------------------------------------------------
template<class ItemType>
void 
BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> 
subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // decrement reference count to node
   }  
} 

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), 
std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      // visit(treePtr->getItem());
      preorder(visit, treePtr->getLeftChildPtr());
      preorder(visit, treePtr->getRightChildPtr());
   }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), 
std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   } 
} 

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), 
std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      postorder(visit, treePtr->getLeftChildPtr());
      postorder(visit, treePtr->getRightChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
   }
}  

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

//------------------------------------------------------------
//               Default constructor
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{  } 

//------------------------------------------------------------
//               Second constructor
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
   :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, 
    nullptr))
{  }

//------------------------------------------------------------
//                 Third constructor
// Calls: copyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
      :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
       copyTree(leftTreePtr->rootPtr),
       copyTree(rightTreePtr->rootPtr)))
{   }

//------------------------------------------------------------
//                 Copy constructor
// Calls: copyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& 
treePtr)
{
   rootPtr = copyTree(treePtr.rootPtr);
}  

//------------------------------------------------------------   
//                   Destructor
// Calls: destroyTree (inherited)
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
   destroyTree(rootPtr);
}

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
//                    isEmpty
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
   return rootPtr == nullptr;
}

//------------------------------------------------------------
//                   getHeight   
// Calls: getHeightHelper (recursive)
//------------------------------------------------------------
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
   return getHeightHelper(rootPtr);
}

//------------------------------------------------------------
//                  getNumberOfNodes
// Calls: getNumberOfNodesHelper (recursive)
//------------------------------------------------------------
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
   return getNumberOfNodesHelper(rootPtr);
}

//------------------------------------------------------------
//                      clear
// Calls: destroyTree
//------------------------------------------------------------
template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
   destroyTree(rootPtr);
   rootPtr.reset();
}

//------------------------------------------------------------
//                    getRootData
//------------------------------------------------------------
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const 
throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("getRootData() called with empty tree."); 
      
   return rootPtr->getItem();
}

//------------------------------------------------------------
//                    setRootData
//------------------------------------------------------------
template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem)
{
   if (isEmpty())
      rootPtr = std::make_shared<BinaryNode<ItemType>>(newItem, nullptr, 
                nullptr);
   else
      rootPtr->setItem(newItem);
}

//------------------------------------------------------------ 
//                      add
// Calls: balancedAdd
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = balancedAdd(rootPtr, newNodePtr);
   return true;
} 

//------------------------------------------------------------
//                      remove
// Calls: removeValue
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}

//------------------------------------------------------------
//                   getEntry
//------------------------------------------------------------
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const 
throw(NotFoundException)
{
   bool isSuccessful = false;
   auto binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);
   
   if (isSuccessful)
      return binaryNodePtr->getItem(); 
   else 
      throw NotFoundException("Entry not found in tree!");
} 

//------------------------------------------------------------
//                  contains
// Calls: findNode
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>:: contains(const ItemType& anEntry) const
{
   bool isSuccessful = false;
   findNode(rootPtr, anEntry, isSuccessful);
   return isSuccessful;   
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   postorder(visit, rootPtr);
}

//////////////////////////////////////////////////////////////
//      Overloaded Operator= 
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(
                const BinaryNodeTree<ItemType>& rightHandSide)
{
   if (!isEmpty())
      clear();
   this = copyTree(&rightHandSide);
   return *this;
} 

/////////////////////////////////////////////////////////////
//       Display Algorithm
//	This function will display the Binary Node Tree
/////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::display(const ItemType& root, int blank)
{
	// You will enter this loop if the root pointer is not pointing to NULL
	if (rootPtr != NULL)
	{
		display(rightTreePtr, blank + 1);
		// Create the spaces
		for (int i = 0; i < blank; i++)
		{
			cout << " ";
		}
		cout << treePtr << endl;
		display(leftTreePtr, blank + 1);
	}
}

//////////////////////////////////////////////////////////////
//      Replacement Algorithm
//    This code will search to see if the node you are
//    looking for exists.  If so, it will find the node
//    and replace it with the item you want to replace. 
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinaryNodeTree<ItemType>::replace(const ItemType item, const ItemType itemReplace)
{
   bool isSuccessful = false;

   if(contains(item) == true)
   {
      isSuccessful = true;
      auto binaryNodePtr = findNode(rootPtr, item, isSuccessful);
      removeValue(binaryNodePtr, item, isSuccessful);
      add(itemReplace);
      return true;
   }
   else
   {
      cout << "Item does not exist" << endl;
      return false;
   }
}