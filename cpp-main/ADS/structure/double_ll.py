class DoubleLinkedList:
    class Node:
        previous_node = None
        next_node = None
        element = None
        def __init__(
            self, 
            element, 
            next_node=None, 
            previous_node=None
        ) -> None:
            self.element=element
            self.next_node=next_node
            self.previous_node=previous_node
            
    head = None
    tail = None
    length = 0
    
    def add(self, element):
        self.length += 1
        if not self.head: 
            self.head = self.Node(element=element)
            return element
        elif not self.tail:
            self.tail = self.Node(
                element=element, 
                next_node=None, 
                previous_node=self.head
            )
            self.head.next_node = self.tail
            return element
        else:
            self.tail = self.Node(
                element=element, 
                next_node=None, 
                previous_node=self.tail
            )
            self.tail.previous_node.next_node = self.tail
            return element
        
    def __iter__(self):
        node = self.head
        
        while node:
            yield node.element
            node = node.next_node
    
    def _del(self, index, reverse):
        if index == 0:
            element = self.head.element
            if self.head.next_node:
                self.head = self.head.next_node
                self.head.previous_node=None
            else: 
                self.head = None
            self.length -= 1

            return element
        elif index == self.length - 1:
            element = self.tail.element
            self.tail = self.tail.previous_node
            self.tail.next_node = None
            self.length -= 1
            return element
        elif reverse:
            node = self.tail
            i = self.length - 1
            while i != index:
                node = node.previous_node
                i -= 1
            element = node.element
            node.previous_node.next_node, node.next_node.previous_node = node.next_node, node.previous_node
            self.length -= 1
            del node
            return element
        else:
            node = self.tail
            i = 0
            while i != index:
                node = node.previous_node
                i += 1
            element = node.element
            node.previous_node.next_node, node.next_node.previous_node = node.next_node, node.previous_node

            del node
            self.length -= 1

            return element
        
    def _assign(self, index, element, reverse):
        if index == 0:
            self.head.element = element
        elif index == self.length - 1:
            self.tail.element = element
        elif reverse:
            node = self.tail
            i = self.length - 1
            
            while i != index:
                node = node.previous_node
                i -= 1
            
            node.element = element
        else:
            node = self.head 
            i = 0
            while i != index:
                node = node.next_node  
                i += 1
            node.element = element
    
    def is_empty(self):
        return self.length == 0
    
    def delete(self, index):
        if self.head:
            if index > self.length // 2:
                el = self._del(index=index, reverse=True)
                return el
            elif index <= self.length // 2:
                el = self._del(index=index, reverse=False)
                
                return el
    def assign(self, index, element):
        if self.head:
            if index > self.length // 2:
                self._assign(index=index, reverse=True, element=element)
            elif index <= self.length // 2:
                self._assign(index=index, reverse=False, element=element)
    
def main():    
    dll = DoubleLinkedList()
    
    dll.add(element=6)
    dll.add(element=2)
    dll.delete(index=0)
    dll.delete(index=0)
    print(dll.is_empty())
    # dll.add(5)
    # dll.add(551)
    # dll.add(235)
    # dll.add(0)
    # dll.add(123)
    # dll.add(54)
    # dll.add(52)
    # dll.assign(index=4, element=200)
    # dll.delete(index=6)
    # for e in dll:
    #     print(e, end=' -> ')
        
    # print('None')
    # print(dll.length)
    
if __name__ == '__main__':
    main()