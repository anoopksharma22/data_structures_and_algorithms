#include<iostream>
struct Node
{
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }

};

struct LinkedList
{
    Node* head;
    Node* tail;
    int length;

    LinkedList(int value)
    {
        Node* node = new Node(value);
        head = node;
        tail = node;
        length = 1;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        Node* temp = head;
        head = newNode;
        newNode->next = temp;        
        length += 1;        
    }

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