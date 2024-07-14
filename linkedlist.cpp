/**************************
 * Name: Posan Gc
 * Assignment 7: Hash Tables
 * Purpose of the file: This project implements a hash table using separate chaining with linked lists.
 * It defines the HashTable class and its interface, including methods for adding, deleting, retrieving,
 * and printing entries. The project demonstrates the functionality and testing of the hash table implementation
 * through a main file that generates test data, creates a hash table, and performs various operations.
 ***************************/

#include "linkedlist.h"


LinkedList::LinkedList() : head(nullptr) {  }
/*********************************************
* This constructor initializes the linked list
* by setting the head to nullptr
*
* @param none
* @exception none
* @return void
*********************************************/


LinkedList::~LinkedList() {
    clearList();
}
/*********************************************
* This destructor calls clearList() to delete
* all nodes and free memory
*
* @param none
* @exception none
* @return void
*********************************************/


bool LinkedList::addNode(int id, std::string* info) {
/*********************************************
* This method adds a node with the given id and
* information to the list. Ensures the id is unique
* and the list is kept in ascending order
*
* @param int id : integer ID for the Data struct
* @param std::string* info : pointer to string information for the Data struct
* @exception none
* @return bool : true if the node was successfully added, false otherwise
*********************************************/    
    bool success = false;

    if (id > 0 && !info->empty()) {
        Node* current = head;
        Node* previous = nullptr;

        while (current && current->data.id < id) {
            previous = current;
            current = current->next;
        }

        if (!current || current->data.id != id) {
            Node* newNode = new Node{{id, *info}, current, previous};
            if (!previous) {
                head = newNode;
            } else {
                previous->next = newNode;
            }
            if (current) {
                current->prev = newNode;
            }
            success = true;
        }
    }

    return success;
}


bool LinkedList::deleteNode(int id) {
/*********************************************
* This method deletes the node with the given id
* from the list
*
* @param int id : integer ID of the node to delete
* @exception none
* @return bool : true if the node was successfully deleted, false otherwise
*********************************************/    
    bool success = false;
    Node* current = head;

    while (current && current->data.id != id) {
        current = current->next;
    }

    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }

        delete current;
        success = true;
    }

    return success;
}


bool LinkedList::getNode(int id, Data* data) {
/*********************************************
* This method retrieves the node with the given id.
* If the id is found, the data is returned in the 
* provided Data struct
*
* @param int id : integer ID of the node to retrieve
* @param Data* data : pointer to a Data struct to store the retrieved data
* @exception none
* @return bool : true if the node was found, false otherwise
*********************************************/
    bool found = false;
    Node* current = head;

    while (current && !found) {
        if (current->data.id == id) {
            *data = current->data;
            found = true;
        } else {
            current = current->next;
        }
    }

    if (!found) {
        data->id = -1;
        data->data.clear();
    }

    return found;
}


void LinkedList::printList(bool backward) {
/*********************************************
* This method prints the entire list in order,
* either forward or backward
*
* @param bool backward : bool to indicate whether to print backward or foward
* @exception none
* @return void
*********************************************/
    if (backward) {
        Node* current = head;
        while (current && current->next) {
            current = current->next;
        }
        while (current) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    } else {
        Node* current = head;
        while (current) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    }
}


int LinkedList::getCount() {
/*********************************************
* This method returns the number of nodes in
* the list
*
* @param none
* @exception none
* @return int : the count of nodes in the list
*********************************************/
    int count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}


void LinkedList::clearList() {
/*********************************************
* This method deletes all nodes in the list and 
* sets head to nullptr
*
* @param none
* @exception none
* @return void
*********************************************/
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}


bool LinkedList::exists(int id) {
/************************************************
* This method checks if a node with the given id
* exists in the list
*
* @param int id : integer ID to check for
* @exception none
* @return bool : true if a node with the given id exists, false otherwise
*********************************************/ 
    bool found = false;
    Node* current = head;
    
    while (current && !found) {
        if (current->data.id == id) {
            found = true;
        } else {
            current = current->next;
        }
    }
    return found;
}
