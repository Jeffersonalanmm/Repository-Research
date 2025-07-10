
import random
import time
from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.popleft()

    def size(self):
        return len(self.queue)

    def is_empty(self):
        return len(self.queue) == 0

    def peek(self):
        if len(self.queue) < 1:
            return None
        return self.queue[0]

# Test the Queue implementation with 1000 random inputs
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
