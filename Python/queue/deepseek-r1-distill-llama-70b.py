
from collections import deque

class Queue:
    def __init__(self):
        self.deque = deque()
    
    def enqueue(self, value):
        self.deque.append(value)
    
    def dequeue(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        return self.deque.popleft()
    
    def peek(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        return self.deque[0]
    
    def is_empty(self):
        return len(self.deque) == 0
    
    def size(self):
        return len(self.deque)

# Example usage
if __name__ == "__main__":
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    
    print(q.size())  # Output: 3
    print(q.peek())  # Output: 1
    print(q.dequeue())  # Output: 1
    print(q.size())  # Output: 2
    print(q.is_empty())  # Output: False
