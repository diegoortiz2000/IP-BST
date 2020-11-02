//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#include "DoubleLinkedList.h"

#include <utility>
#include <fstream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

void DoubleLinkedList::insertFirst(const string &regString) {
    this->head = new MyNodoLL(regString, this->head, nullptr);
    if (this->size == 0) {
        this->tail = this->head;
    } else {
        this->head->next->prev = this->head;
    }
    this->size++;
}

void DoubleLinkedList::insertLast(const string &regString) {
    if (size == 0) {
        insertFirst(regString);
    }
    auto *nvo = new MyNodoLL(regString, nullptr, this->tail);
    this->tail->next = nvo;
    this->tail = nvo;
    this->size++;
}

MyNodoLL *DoubleLinkedList::getHead() const {
    return head;
}

DoubleLinkedList::~DoubleLinkedList() {
    MyNodoLL *next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
}

void DoubleLinkedList::calculateHead() {
    while (this->head->prev != nullptr) {
        head = head->prev;
    }
}

MyNodoLL *DoubleLinkedList::merge(MyNodoLL *first, MyNodoLL *second) {
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->reg.getIp() < second->reg.getIp()) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

MyNodoLL *DoubleLinkedList::split(MyNodoLL *head) {
    MyNodoLL *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    MyNodoLL *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

MyNodoLL *DoubleLinkedList::mergeSort(MyNodoLL *head) {
    if (!head || !head->next)
        return head;
    MyNodoLL *second = split(head);

    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

void DoubleLinkedList::mergeSort() {
    mergeSort(this->head);
    calculateHead();
}

void DoubleLinkedList::bitacoraOrdenada(const DoubleLinkedList &list) {
    ofstream archivoBitacoraOrdenada;
    archivoBitacoraOrdenada.open("bitacoraOrdenada.txt", ios::out);
    archivoBitacoraOrdenada << list;
    archivoBitacoraOrdenada.close();
}


