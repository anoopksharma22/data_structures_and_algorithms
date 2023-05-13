#include<iostream>

// Struct to represent a node
struct Node
{
    int value;
    Node* next;

    // New node in instantiated with the value and it points to nullptr
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }

};

// Struct to represent a linked list
struct LinkedList
{
    Node* head; // track head
    Node* tail; // track tail 
    int length; // track length of the linked list

    // New node is created and both head and tail points to it.
    LinkedList(int value)
    {
        Node* node = new Node(value);
        head = node;
        tail = node;
        length = 1;
    }

    // head is copied to a temp variable so that we don't loose it
    // new node is create
    // head points to the new node
    // new node point to previous node which we kept in temp.
    void push(int value)
    {
        Node* newNode = new Node(value);
        Node* temp = head;
        head = newNode;
        newNode->next = temp;        
        length += 1;        
    }

    // Temp variable is needed since we are moving head forward else we will lose the list
    // head = head->next simply moves head to next node
    void printlist()
    {
        Node* temp;
        temp = head;
        while( head != nullptr )
        {
            std::cout << head->value << "->";
            head = head->next;
        }
        std::cout << std::endl;
        head = temp;
    }
};


int main()
{
    LinkedList list(5);
    list.push(6);
    list.push(7);
    list.push(8);
    list.push(9);

    list.printlist();
    std::cout << "list length: " <<  list.length << std::endl;
    std::cout << "head at: " <<  list.head << std::endl;
    std::cout << "tail at: " <<  list.tail << std::endl;
    return 0;

}