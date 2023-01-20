class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        curr_node = self.head
        while curr_node.next is not None:
            curr_node = curr_node.next
        curr_node.next = new_node

    def insert_after_node(self, prev_node, data):
        if prev_node is None:
            print("Previous node is not present in the list")
            return
        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next = new_node

    def delete_node(self, key):
        curr_node = self.head
        if curr_node is not None and curr_node.data == key:
            self.head = curr_node.next
            curr_node = None
            return
        prev_node = None
        while curr_node is not None and curr_node.data != key:
            prev_node = curr_node
            curr_node = curr_node.next
        if curr_node is None:
            return
        prev_node.next = curr_node.next
        curr_node = None

    def print_list(self):
        curr_node = self.head
        while curr_node is not None:
            print(curr_node.data, end=" -> ")
            curr_node = curr_node.next
        print("None")

# Create a new linked list
my_list = LinkedList()

# Insert some nodes
my_list.insert_at_beginning(5)
my_list.insert_at_end(10)
my_list.insert_after_node(my_list.head, 7)

# Print the list
my_list.print_list()  # Output: 5 -> 7 -> 10 -> None

# Delete a node
my_list.delete_node(7)

# Print the list again
my_list.print_list()  # Output: 5 -> 10 -> None