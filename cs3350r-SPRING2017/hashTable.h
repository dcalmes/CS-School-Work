#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class ItemType>
class hashTable
{
    private:
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        static const int DEFAULT_CAPACITY = 53;
       
        ItemType items[DEFAULT_CAPACITY];
        int itemCount;

        int hash(int key) const;
		int new_hash(int key) const;
        int next_index(int index, int key) const;
        void find_index(int key, bool& found, int& index) const;
        bool never_used(int index) const;
        bool is_vacant(int index) const;

   public:
        hashTable();  // Constructor
        
        int add(const ItemType& entry);
        void remove(int key);
        
        bool is_present(int key) const;
        void getItem(int key, bool& found, ItemType& result) const;
        int size( ) const { return itemCount; }
	void displayTable(int loops);
        
};
#include "hashTable.cpp"        // Include the implementation.
#endif

