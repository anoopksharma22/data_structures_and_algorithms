#include "doubly_linked_list.h"

int main()
{
    DoublyLinkedList dll = DoublyLinkedList(5);
    dll.append_last(10);
    dll.append_last(12);
    dll.append_last(15);
    dll.print_list();
    std::cout<< "Test append first" << std::endl;
    dll.append_first(22);
    dll.append_first(24);
    dll.append_first(26);
    dll.print_list();
    
    int index = 2;
    std::cout<< "Test get(" << index << ") " << ": " << dll.get(index) << std::endl;
    
    std::cout << "test";
    return 0;
    
}