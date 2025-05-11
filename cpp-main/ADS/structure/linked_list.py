from typing import Any


class LinkedList:
    head = None
    
    class Node:
        element = None
        next_node = None
        def __init__(
            self, 
            element, 
            next_node=None
        ) -> None:
            self.element = element
            self.next_node = next_node
    
    def append(
        self,
        element 
    ):
    
        if not self.head:
            self.head = self.Node(
                element=element, 
                next_node=None
            )
            return element
        node = self.head
        
        while node.next_node:
            node = node.next_node
        
        node.next_node = self.Node(
            element=element, 
            next_node=None
        )
        
        return element
        
        
    def out(self):
        node = self.head
        while node.next_node:
            print(node.element, end=' -> ')
            node = node.next_node
        print(node.element, end=' -> ')
        print('None')
        
    def insert(self, element, index):
        i = 0
        node = self.head
        prev_node = self.head
        
        while i < index:
            prev_node = node
            node = node.next_node
            i += 1
        
        prev_node.next_node = self.Node(element=element, next_node=node)
        
        return element
    def get(self, index):
        i = 0
        node = self.head
        while i < index: 
            node = node.next_node
            i += 1
        return node.element 
    
    def delete(self, index):
        node = self.head
        i = 0
        prev_node = node 
        
        while i < index:
            prev_node = node
            node = node.next_node
            i += 1
        
        prev_node.next_node = node.next_node
        element = node.element
        
        del node
        
        
        return element
    def get_length(self):
        if not self.head:
            return 0
        i = 1
        node = self.head
        while node.next_node:
            i += 1
            node = node.next_node
        
        return i
    
    def assign(self, element, index):
        node = self.head
        i = 0
        while i < index:
            node = node.next_node
            i += 1
        
        node.element = element
        
    
def main() -> None:
    linked_list = LinkedList()
    
    linked_list.append(element=10)
    linked_list.append(element=15)
    linked_list.assign(element=200, index=0)
    linked_list.insert(element=50, index=2)
    linked_list.append(element=14)
    linked_list.append(element=12)
    linked_list.delete(index=4)
    linked_list.append(element=10)
    
    linked_list.out()
    
    print(linked_list.get(index=3))
    print(linked_list.get_length())
    
if __name__ == '__main__':
    main()