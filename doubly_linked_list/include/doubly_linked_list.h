#include<iostream>
#include "node.h"

class DoublyLinkedList
{
    Node* head;
    Node* tail;
    int length = 0;

public:
    DoublyLinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length++;
    }

    ~DoublyLinkedList()
    {       
        
        Node* temp = head;        
        while( head != nullptr )
        {            
            temp = head->next;
            delete(head);
            head = temp;  
        }
        std::cout << "Memory freed" << std::endl;
    }

    void append_last(int value)
    {
        Node* newNode = new Node(value);
        if( length == 0 )
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void append_first(int value)
    {
        Node* newNode = new Node(value);
        if( length == 0 )
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;

    }

    int get(int index)
    {
        Node* temp;
        if (index > length) 
            throw -1;
        if(index < length/2)
        {
            temp = head;
            for(int i=0; i<index; i++)
            {
                temp = temp->next;
            }
        }
        else{
            temp = tail;
            for(int i=0; i<length-index; i++)
            {
                temp = temp->prev;
            }
        }        
        return temp->value;
    }

    void print_list()
    {
        Node* temp = head;
        while( temp != nullptr )
        {
            std::cout << temp->value << "->";
            temp = temp->next;            
        }
        std::cout << std::endl;
    }
};
