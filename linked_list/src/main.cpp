#include<iostream>
#include "../includes/linked_list.h"

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