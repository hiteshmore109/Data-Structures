class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next
class SingleLinkedList:
    def __init__(self):
        self.head = None
    def AddLast(self, data):
        if(self.head == None):
            self.head = Node(data)
            return
        itr = self.head
        while itr.next != None:
            itr = itr.next
        itr .next = Node(data)
    def AddFirst(self, data):
        if(self.head == None):
            self.head = Node(data)
            return
        itr = self.head
        self.head = Node(data)
        self.head.next = itr
    def AddAt(self, index, data):
        count = self.length()
        if index >= count:
            raise Exception("Node Index Out of Bounds")
        if index == 0:
            self.AddFirst(data)
            return
        itr = self.head
        for i in range(index-1):
            itr = itr.next
        newNode = Node(data)
        newNode.next = itr.next
        itr.next = newNode
    def RemoveAt(self, index):
        count = self.length()
        if index >= count:
            raise Exception("Node Index Out of Bounds")
        itr = self.head
        for i in range(index-1):
            itr = itr.next
        itr.next = itr.next.next
    def length(self):
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next
        return count
    def Display(self):
        if self.head == None:
            print("Empty linked list!")
            return
        itr = self.head
        lstr = ''
        while itr:
            lstr += str(itr.data) + " "
            itr = itr.next
        print(lstr)
list = SingleLinkedList()
list.AddFirst(5)
list.AddFirst(4)
list.AddFirst(3)
list.AddFirst(1)
list.AddFirst(0)
list.AddLast(6)
list.AddAt(2, 2)
list.AddAt(0, -1)
list.Display()
list.RemoveAt(2)
list.Display()