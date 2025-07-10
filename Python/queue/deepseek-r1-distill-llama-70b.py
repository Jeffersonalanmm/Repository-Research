
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

def main():
    input_path = "inputs.txt"
    
    q = Queue()
    
    try:
        with open(input_path, 'r') as f:
            for line in f:
                line = line.strip()
                if line:
                    value = int(line)
                    q.enqueue(value)
    except FileNotFoundError:
        return

if __name__ == "__main__":
    main()
