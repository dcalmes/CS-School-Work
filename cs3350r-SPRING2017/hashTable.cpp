// INVARIANT for the table ADT:
// 1. The number of records in the table is in the member variable 
//    itemCount.
// 2. The actual records of the table are stored in the array items, with
//    a maximum of DEFAULT_CAPACITY entries. Each used spot in the array 
//    has a non-negative key. Any unused record in the array has a key 
//    field of NEVER_USED (if it has never been used) or PREVIOUSLY_USED
//    (if it once was used, but is  now vacant).

    #include <cassert>  // Provides assert
	#include<iostream>
	#include<string>
    #include "hashTable.h"
using namespace std;
    // --------------------------------------------------
    //                constructor
    // --------------------------------------------------
    template <class ItemType>
    hashTable<ItemType>::hashTable( )
    {
        int i;

        itemCount= 0;
        for (i = 0; i < DEFAULT_CAPACITY; ++i)
            items[i].key = NEVER_USED;  // Indicates a spot never used.
    }

    // --------------------------------------------------
    //                   add
    // --------------------------------------------------
    template <class ItemType>
    int hashTable<ItemType>::add(const ItemType& entry)
    {
        bool already_present;   // True if entry.key is already in the table
        int index;              // items[index] is location for the new entry
	    int collisions = 0;
        assert(entry.key >= 0);

        // Set index so that items[index] is the spot to place the new entry.
        find_index(entry.key, already_present, index);

        // If key wasn't already there, find location for the new entry.
        if (!already_present)
        {
            assert(size( ) < DEFAULT_CAPACITY);
            index = new_hash(entry.key);
			while (!is_vacant(index)) {
				index = next_index(index, entry.key);
				collisions += 1;
			}
            ++itemCount;
        }

        items[index] = entry;
		return collisions;
    }

    // --------------------------------------------------
    //                  remove
    // --------------------------------------------------
    template <class ItemType>
    void hashTable<ItemType>::remove(int key)
    {
        bool found;        // True if key occurs somewhere in the table
        int index;   // Spot where items[index].key == key

        assert(key >= 0);

        find_index(key, found, index);
        if (found)
        {   // Key found, so remove this record and decrement itemCount
            items[index].key = PREVIOUSLY_USED; // Spot no longer in use.
            --itemCount;
        }
    }

    // --------------------------------------------------
    //                is_present
    // --------------------------------------------------
    template <class ItemType>
    bool hashTable<ItemType>::is_present(int key) const
    {
        bool found;
        int index;

        assert(key >= 0);

        find_index(key, found, index);
        return found;
    }

    // --------------------------------------------------
    //                   getItem
    // --------------------------------------------------
    template <class ItemType>
    void hashTable<ItemType>::getItem(int key, bool& found, ItemType& result) 
        const
    {
        int index;

        assert(key >= 0);

        find_index(key, found, index);
        if (found)
            result = items[index];
    }

    // --------------------------------------------------
    //                    find_index
    // --------------------------------------------------
    template <class ItemType>
    void hashTable<ItemType>::find_index(int key, bool& found, int& i) const
    {
        int count; // Number of entries that have been examined

        count = 0;
        i = hash(key);
        while((count < DEFAULT_CAPACITY) && (items[i].key != NEVER_USED) 
               && (items[i].key != key))
        {
            ++count;
            i = next_index(i, items[i].key);
        }
        found = (items[i].key == key);
    }

    // --------------------------------------------------
    //                      hash
    // --------------------------------------------------
    template <class ItemType>
    inline int hashTable<ItemType>::hash(int key) const
    {
        return (key % DEFAULT_CAPACITY);
    }

	// --------------------------------------------------
	//                     new_hash
	// --------------------------------------------------
	template <class ItemType>
	inline int hashTable<ItemType>::new_hash(int key) const
	{
		return (key * 2654435761) % (2 ^ 32);
	}

    // --------------------------------------------------
    //                   next_index
    // --------------------------------------------------
    template <class ItemType>
    inline int hashTable<ItemType>::next_index(int index, int key) const
    // Library facilities used: cstdlib
    {
		int doubleHash = 7 - (key % 7);
		return ((index + doubleHash) % DEFAULT_CAPACITY);
        //return ((index+1) % DEFAULT_CAPACITY);
    }

    // --------------------------------------------------
    //                never_used
    // --------------------------------------------------
    template <class ItemType>
    inline bool hashTable<ItemType>::never_used(int index) const
    {
        return (items[index].key == NEVER_USED);
    }
        
    // --------------------------------------------------
    //                is_vacant
    // --------------------------------------------------
    template <class ItemType>
    inline bool hashTable<ItemType>::is_vacant(int index) const
    {
        return (items[index].key == NEVER_USED) || 
               (items[index].key == PREVIOUSLY_USED);
    }

	// --------------------------------------------------
	//                displayTable
	// --------------------------------------------------
	template <class ItemType>
	void hashTable<ItemType>::displayTable(int loops) {

		cout << "Original Hash Report" << endl;
		cout << "Student Records" << endl;
		cout << "Index      Key      Discription" << endl;

		// Loop to print out hash table
		for (int i = 0; i < DEFAULT_CAPACITY; i++) {
			cout << i << "        " << items[i].key << "        " << items[i].description << endl;
		}

	}
