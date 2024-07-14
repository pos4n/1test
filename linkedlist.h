/**************************
 * Name: Posan Gc
 * Assignment 7: Hash Tables
 * Purpose of the file: This project implements a hash table using separate chaining with linked lists.
 * It defines the HashTable class and its interface, including methods for adding, deleting, retrieving,
 * and printing entries. The project demonstrates the functionality and testing of the hash table implementation
 * through a main file that generates test data, creates a hash table, and performs various operations.
 ***************************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>


class LinkedList {
/*********************************************
This class defines a LinkedList. It allows for
the creation and management of a doubly linked list.
The list can have nodes added, deleted, and retrieved
while maintaining unique ids for each node.

@attrib head : the pointer to the head node of the list
*********************************************/

private: 
    struct Node {
        Data data;
        Node* next;
        Node* prev;
    };

    Node* head;

public:
    /**********************
    Constructors/Destructor
    ***********************/
    LinkedList();
    ~LinkedList();

    /**********************
    Getters/Accessors
    ***********************/
    bool getNode(int id, Data* data);
    void printList(bool backward = false);
    int getCount();
    bool exists(int id);

    /**********************
    Setters/Mutators
    ***********************/
    bool addNode(int id, std::string* info);
    bool deleteNode(int id);
    void clearList();
};

#endif // LINKEDLIST_H
