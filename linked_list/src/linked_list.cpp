#include "../includes/linked_list.h"
#include<iostream>

void LinkedList::push(int value)
    {
        Node* newNode = new Node(value);
        Node* temp = head;
        head = newNode;
        newNode->next = temp;
        tail = temp;
        length += 1;        
    }

void LinkedList::append(int value)
{
    Node* newNode = new Node(value);
    if ( head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length +=1;
}
// Temp variable is needed since we are moving head forward else we will lose the list
// head = head->next simply moves head to next node

void LinkedList::pop()
{
    Node* pre;
    Node* temp;

    pre = head;
    temp = head;
    if ( length == 0 ) return;
    if ( length == 1 )
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        while(temp->next != nullptr)
        {
            pre = temp;
            temp = temp->next;            
        }
        tail = pre;
        tail->next = nullptr;        
        
    }
    length -= 1;
    delete(temp);
}

void LinkedList::prepend(int value)
{
    Node* newNode = new Node(value);
    if ( length == 0 ){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    length += 1;
}

void LinkedList::shift()
{
    if( length == 0 ) return;
    Node* temp;
    temp = head;
    if( length == 1 )
    {
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
    }
    delete temp;
}

Node* LinkedList::get(int index)
{
    if ( index < 0 || index >= length) throw std::range_error{"index out of range"};
    Node* temp = head;
    for( int i=0; i < index; i++ )
    {
        temp = temp->next;
    }
    return temp;
}

void LinkedList::set(int index, int value)
{
    if ( index < 0 || index >= length) throw std::range_error{"index out of range"};
    Node* temp = head;
    for( int i=0; i < index; i++ )
    {
        temp = temp->next;
    }
    temp->value = value;
}

void LinkedList::insert(int index, int value)
{
    if( index < 0 || index > length ) throw std::range_error{"index out of range"};
    if( index == 0 ) return this->prepend(value);
    if( index == length -1 ) return this->append(value);
    Node* temp = get(index-1);
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::delete_node(int index)
{
    if( index < 0 || index >= length ) throw std::range_error{"index out of range"};
    if( index == 0) return this->shift();
    if(index == length-1) return this->pop();
    Node* pre = this->get(index - 1);
    Node* temp = pre->next;
    pre->next = temp->next;
    delete temp;
    length--;        
}

void LinkedList::reverse()
{
    Node* temp;
    // switch head and tail
    temp = head;
    head = tail;
    tail = temp;

    Node* before = nullptr;
    Node* after = temp->next;       
    for( int i=0 ; i< this->length; i++)
    {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

void LinkedList::printlist()
{
    Node* temp;
    temp = head;
    while( temp != nullptr )
    {
        std::cout << temp->value << "->";
        temp = temp->next;
    }
    std::cout << std::endl;
}