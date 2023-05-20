from linked_list.node import Node

class LinkedList:
    def __init__(self,value):
        node = Node(value)
        self.head = node
        self.tail = node
        node.next = None
        self.length = 1

    def append(self,value):
        newNode = Node(value)    
        self.tail.next = newNode
        self.tail = newNode
        self.length += 1
    
    def prepend(self,value):
        newNode = Node(value)    
        newNode.next = self.head
        self.head = newNode

    def printlist(self):
        temp = self.head
        while(temp != None):
            print(temp.value, end="")
            print("->", end="")
            temp = temp.next
        print("")
