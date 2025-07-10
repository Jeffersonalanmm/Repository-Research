import random

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def peek(self):
        if len(self.queue) < 1:
            return None
        return self.queue[0]

    def size(self):
        return len(self.queue)

    def is_empty(self):
        return len(self.queue) == 0

def test_queue():
    queue = Queue()
    for _ in range(1000):
        operation = random.randint(1, 5)
        if operation == 1:  # Enqueue
            value = random.randint(1, 1000)
            queue.enqueue(value)
        elif operation == 2:  # Dequeue
            queue.dequeue()
        elif operation == 3:  # Peek
            queue.peek()
        elif operation == 4:  # Size
            queue.size()
        elif operation == 5:  # IsEmpty
            queue.is_empty()

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
