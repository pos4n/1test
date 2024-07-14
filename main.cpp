 /**************************
 * Name: Posan Gc
 * Assignment 7: Hash Tables
 * Purpose of the file: This file implements a hash table using separate chaining with linked lists.
 * It defines the HashTable class and its interface, including methods for adding, deleting, retrieving, and printing entries. 
 * The main file demonstrates the functionality and testing of the hash table implementation.
 ***************************/

#include "main.h"


int main() {
/* *********************************************
 * This function serves as the main entry point
 * for testing the HashTable class. It generates
 * test data, creates a hash table, and performs
 * various operations to demonstrate functionality.
 *
 * @param na : na
 * @return (int) : application exit code
 * @exception na : na
 * *********************************************/
   
    // Seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non-unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    std::string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; ++i) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; ++j) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize - 2] = ids[testdatasize - 3];
    strs[testdatasize - 2] = "known duplicate";
    ids[testdatasize - 1] = -1;
    strs[testdatasize - 1] = "known bad";

    /*
     * Show test data
     */
    std::cout << "Showing Test Data (" << testdatasize << " entries)..." << std::endl;
    for (int i = 0; i < testdatasize; ++i) {
        std::cout << ids[i] << " : " << strs[i] << std::endl;
    }
    std::cout << std::endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // Create your hash table object here
    HashTable hashTable;

    // Show it is empty by calling getCount and printTable
    std::cout << "Hash Table initially:" << std::endl;
    std::cout << "Total entries: " << hashTable.getCount() << std::endl;
    hashTable.printTable();
    std::cout << std::endl;

    // Try and put ALL the test data into the table and show what happens
    for (int i = 0; i < testdatasize; ++i) {
        bool success = hashTable.insertEntry(ids[i], new std::string(strs[i]));
        std::cout << "Inserting (" << ids[i] << ", " << strs[i] << "): " << (success ? "Success" : "Failure") << std::endl;
    }
    std::cout << std::endl;

    // Show the table after insertions
    std::cout << "Hash Table after insertions:" << std::endl;
    std::cout << "Total entries: " << hashTable.getCount() << std::endl;
    hashTable.printTable();
    std::cout << std::endl;

    // Further testing: getData, removeEntry, etc.
    for (int i = 0; i < testdatasize; ++i) {
        std::cout << "Data for ID " << ids[i] << ": " << hashTable.getData(ids[i]) << std::endl;
    }
    std::cout << std::endl;

    // Remove some entries
    for (int i = 0; i < testdatasize; ++i) {
        bool success = hashTable.removeEntry(ids[i]);
        std::cout << "Removing ID " << ids[i] << ": " << (success ? "Success" : "Failure") << std::endl;
    }
    std::cout << std::endl;

    // Show the table after deletions
    std::cout << "Hash Table after deletions:" << std::endl;
    std::cout << "Total entries: " << hashTable.getCount() << std::endl;
    hashTable.printTable();
    std::cout << std::endl;

    return 0;
}