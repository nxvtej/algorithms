class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)
        print(f"Pushed {data} to stack.")

    def pop(self):
        if not self.stack:
            print("Stack is empty.")
        else:
            removed = self.stack.pop()
            print(f"Popped {removed} from stack.")

    def display(self):
        print("Stack contents:", self.stack)


class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, data):
        self.queue.append(data)
        print(f"Enqueued {data} to queue.")

    def dequeue(self):
        if not self.queue:
            print("Queue is empty.")
        else:
            removed = self.queue.pop(0)
            print(f"Dequeued {removed} from queue.")

    def display(self):
        print("Queue contents:", self.queue)


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        print(f"Inserted {data} to linked list.")

    def delete(self):
        if not self.head:
            print("Linked list is empty.")
        else:
            if self.head.next is None:
                print(f"Deleted {self.head.data} from linked list.")
                self.head = None
            else:
                current = self.head
                while current.next.next:
                    current = current.next
                print(f"Deleted {current.next.data} from linked list.")
                current.next = None

    def display(self):
        if not self.head:
            print("Linked list is empty.")
        else:
            current = self.head
            ll_elements = []
            while current:
                ll_elements.append(current.data)
                current = current.next
            print("Linked list contents:", ll_elements)


def stack_operations():
    stack = Stack()
    while True:
        print("\nStack Operations Menu:")
        print("1. Push")
        print("2. Pop")
        print("3. Display")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            data = input("Enter data to push: ")
            stack.push(data)
        elif choice == '2':
            stack.pop()
        elif choice == '3':
            stack.display()
        elif choice == '4':
            break
        else:
            print("Invalid choice. Please try again.")


def queue_operations():
    queue = Queue()
    while True:
        print("\nQueue Operations Menu:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            data = input("Enter data to enqueue: ")
            queue.enqueue(data)
        elif choice == '2':
            queue.dequeue()
        elif choice == '3':
            queue.display()
        elif choice == '4':
            break
        else:
            print("Invalid choice. Please try again.")


def linked_list_operations():
    linked_list = LinkedList()
    while True:
        print("\nLinked List Operations Menu:")
        print("1. Insert")
        print("2. Delete")
        print("3. Display")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            data = input("Enter data to insert: ")
            linked_list.insert(data)
        elif choice == '2':
            linked_list.delete()
        elif choice == '3':
            linked_list.display()
        elif choice == '4':
            break
        else:
            print("Invalid choice. Please try again.")


def main():
    operations = {
        '1': stack_operations,
        '2': queue_operations,
        '3': linked_list_operations
    }

    while True:
        print("\nMain Menu:")
        print("1. Stack Operations")
        print("2. Queue Operations")
        print("3. Linked List Operations")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice in operations:
            operations[choice]()
        elif choice == '4':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
