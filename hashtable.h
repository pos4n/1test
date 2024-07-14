 /**************************
 * Name: Posan Gc
 * Assignment 7: Hash Tables
 * Purpose of the file: This file implements a hash table using separate chaining with linked lists.
 * It defines the HashTable class and its interface, including methods for adding, deleting, retrieving, and printing entries. 
 * The main file demonstrates the functionality and testing of the hash table implementation.
 ***************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include "linkedlist.h"

#define HASHTABLESIZE 15

class HashTable {
private:
    /**********************
    Private methods
    ***********************/
    LinkedList table[HASHTABLESIZE];
    int count;

    /**********************
    Private Methods
    ***********************/
    int hash(int id) {
    /*********************************************
     * This method computes the hash value for a given id
     * using the modulo operation.
     *
     * @param int id : the id to hash
     * @return int : the hash value
     * @exception none
     *********************************************/
        return id % HASHTABLESIZE;
    }

public:
    /**********************
    Constructors/Destructors
    ***********************/
    HashTable();

    /**********************
    Public Methods
    ***********************/
    bool insertEntry(int id, std::string* data);
    std::string getData(int id);
    bool removeEntry(int id);
    int getCount();
    void printTable();
};

#endif
