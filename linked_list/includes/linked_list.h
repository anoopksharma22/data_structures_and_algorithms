#pragma once

#include "node.h"

struct LinkedList
{
    Node* head = nullptr; // track head
    Node* tail = nullptr; // track tail 
    int length = 0; // track length of the linked list

    LinkedList(int value)
    {
        Node* node = new Node(value);
        head = node;
        tail = node;
        length = 1;
    }    
    void push(int value);
    void append(int value);
    void pop();
    void prepend(int value);
    void shift();
    Node* get(int index);
    void set(int index, int value);
    void insert(int index, int value);  
    void delete_node(int index);
    void reverse();
    void printlist();
};