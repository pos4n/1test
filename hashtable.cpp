 /**************************
 * Name: Posan Gc
 * Assignment 7: Hash Tables
 * Purpose of the file: This file implements a hash table using separate chaining with linked lists.
 * It defines the HashTable class and its interface, including methods for adding, deleting, retrieving, and printing entries. 
 * The main file demonstrates the functionality and testing of the hash table implementation.
 ***************************/

#include "hashtable.h"

HashTable::HashTable() : count(0) { }
/* ******************************************
 * Constructor initializes the hash table
 * and sets the count to 0.
 *
 * @param none
 * @exception none
 * @return void
 ****************************************** */

bool HashTable::insertEntry(int id, std::string* data) {
/* ******************************************
 * This method inserts an entry into the hash table.
 * It dynamically allocates memory for the string inside the object
 * and returns true if successful and false otherwise.
 *
 * @param int id : the id for the entry
 * @param std::string* data : pointer to the data string
 * @return bool : true if insertion is successful, false otherwise
 * @exception none
 ****************************************** */
    bool result = false;
    if (id > 0 && !data->empty()) {
        int index = hash(id);
        if (table[index].addNode(id, data)) {
            count++;
            result = true;
        }
    }
    return result;
}

std::string HashTable::getData(int id) {
/* ******************************************
 * This method retrieves the data associated with the given id.
 * It returns the data string if the id exists, otherwise it returns
 * an empty string.
 *
 * @param int id : the id to look for
 * @return std::string : the data string associated with the id
 * @exception none
 ****************************************** */
    std::string result = "";
    int index = hash(id);
    Data nodeData;
    if (table[index].getNode(id, &nodeData)) {
        result = nodeData.data;
    }
    return result;
}

bool HashTable::removeEntry(int id) {
/* ******************************************
 * This method removes the entry with the given id from the hash table.
 * It returns true if the entry was successfully removed and false otherwise.
 *
 * @param int id : the id of the entry to remove
 * @return bool : true if the entry was successfully removed, false otherwise
 * @exception none
 ****************************************** */
    bool result = false;
    int index = hash(id);
    if (table[index].deleteNode(id)) {
        count--;
        result = true;
    }
    return result;
}

int HashTable::getCount() {
/* ******************************************
 * This method returns the total number of entries currently
 * in the hash table.
 *
 * @param none
 * @return int : the total number of entries in the hash table
 * @exception none
 ****************************************** */
    return count;
}

void HashTable::printTable() {
/* ******************************************
 * This method prints the contents of the hash table.
 * It traverses the table and prints each entry and its contents.
 *
 * @param none
 * @return void
 * @exception none
 ****************************************** */
    for (int i = 0; i < HASHTABLESIZE; ++i) {
        std::cout << "Entry " << i << ": ";
        table[i].printList();
    }
}
