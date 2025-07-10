import random
from collections import deque

class Queue:
    def __init__(self):
        self.container = deque()

    def enqueue(self, item):
        self.container.append(item)

    def dequeue(self):
        return self.container.popleft() if not self.is_empty() else None

    def is_empty(self):
        return len(self.container) == 0

    def size(self):
        return len(self.container)

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

    while not q.is_empty():
        print(q.dequeue())

if __name__ == "__main__":
    main()
