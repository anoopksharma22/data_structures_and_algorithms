from linked_list.linked_list import LinkedList

def test_length():
    ll = LinkedList(5)
    for i in range(10):
        ll.append(i)
    
    assert ll.length == 11
    