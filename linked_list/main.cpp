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
    Node* head = nullptr; // track head
    Node* tail = nullptr; // track tail 
    int length = 0; // track length of the linked list

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
        tail = temp;
        length += 1;        
    }

    void append(int value)
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

    void pop()
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

    void prepend(int value)
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

    void shift()
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

    Node* get(int index)
    {
        if ( index < 0 || index >= length) throw std::range_error{"index out of range"};
        Node* temp = head;
        for( int i=0; i < index; i++ )
        {
            temp = temp->next;
        }
        return temp;
    }

    void set(int index, int value)
    {
        if ( index < 0 || index >= length) throw std::range_error{"index out of range"};
        Node* temp = head;
        for( int i=0; i < index; i++ )
        {
            temp = temp->next;
        }
        temp->value = value;
    }

    void insert(int index, int value)
    {
        if( index < 0 || index > length ) throw std::range_error{"index out of range"};
        if( index == 0 ) return this->prepend(value);
        if( index == length -1 ) return this->append(value);
        Node* temp = get(index-1);
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void delete_node(int index)
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

    void reverse()
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

    void printlist()
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
};


int main()
{
    LinkedList list(5);

    std::cout << "Testing append" << std::endl;
    list.append(2);
    list.printlist();
    list.append(3);
    list.printlist();
    list.append(1);
    list.printlist();
    list.append(21);
    list.printlist();
    list.append(9);
    list.printlist();
    list.append(10);
    list.printlist();
    list.append(22);
    list.printlist();
    
    std::cout << "Testing Pop" << std::endl;
    list.pop();
    list.printlist();

    std::cout << "Testing prepend" << std::endl;
    list.prepend(56);
    list.printlist();
    
    std::cout << "Testing shift" << std::endl;
    list.shift();
    list.printlist();

    std::cout << "Testing get" << std::endl;

    Node* fourth = list.get(4);
    std::cout << "Value to index(4) is " << fourth->value << std::endl;

    std::cout << "Testing set" << std::endl;

    list.set(4,10);
    list.printlist();
    
    std::cout << "Testing insert" << std::endl;
    list.insert(3,5);
    list.printlist();
    
    std::cout << "Testing delete_node" << std::endl;

    list.delete_node(4);
    list.printlist();

    std::cout << "Testing reverse" << std::endl;
    list.reverse();
    list.printlist();

    return 0;
}