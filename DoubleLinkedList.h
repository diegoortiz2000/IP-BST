//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#ifndef INC_1_3_DOUBLELINKEDLIST_H
#define INC_1_3_DOUBLELINKEDLIST_H

#include <iostream>
#include "RegisterEntry.h"

using namespace std;

// Structure of a node and construction of node MyNodoLL
struct MyNodoLL {
    RegisterEntry reg;
    MyNodoLL *next;
    MyNodoLL *prev;

    MyNodoLL(const string &regString, MyNodoLL *next, MyNodoLL *prev) : reg(regString) {
        this->next = next;
        this->prev = prev;
    }

    explicit MyNodoLL(const string &regString) : MyNodoLL(regString, nullptr, nullptr) {}
};

class DoubleLinkedList {
private:
    MyNodoLL *head;
    MyNodoLL *tail;
    int size;

    // Function to merge two linked lists
    // Complexity O (n * log (n))
    MyNodoLL *merge(MyNodoLL *first, MyNodoLL *second);

    // Split a doubly linked list (DLL) into 2 DLLs of half sizes
    // Complexity O (n * log (n))
    MyNodoLL *split(MyNodoLL *head);

    // Merge sort receives a reference to the header of the DLL to sort
    // Complexity O (n * log (n))
    MyNodoLL *mergeSort(MyNodoLL *head);

public:
    // Constructor
    // O(1)
    DoubleLinkedList();

    // Inerts reg in the first place of the list
    // O(1)
    void insertFirst(const string &regString);

    // Inerts reg in the last place of the list
    // O(1)
    void insertLast(const string &regString);

    // Stream output operator to display all the elements of the list in the terminal
    // O(n)
    friend ostream &operator<<(ostream &os, const DoubleLinkedList &list) {
        MyNodoLL *current = list.head;
        while (current->next != nullptr) {
            os << current->reg << endl;
            current = current->next;
        }
        os << endl;
        return os;
    }

    // Head getter
    // O(1)
    MyNodoLL *getHead() const;

    // Destructor
    // O(n)
    virtual ~DoubleLinkedList();

    // Calculates head when modified by merge sort
    // O(1)
    void calculateHead();

    // Merge sort receives a reference to the header of the DLL to sort
    // Complexity O (n * log (n))
    void mergeSort();

    // Save the registries of a list in a file
    // O(n)
    void bitacoraOrdenada(const DoubleLinkedList &list);
};

#endif //INC_1_3_DOUBLELINKEDLIST_H
