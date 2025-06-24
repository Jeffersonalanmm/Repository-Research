
import random
import string

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        else:
            raise IndexError("Dequeue from an empty queue")

    def is_empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)

    def front(self):
        if not self.is_empty():
            return self.queue[0]
        else:
            raise IndexError("Front from an empty queue")

# Generate 1000 random strings of length 10
random_strings = [''.join(random.choices(string.ascii_letters + string.digits, k=10)) for _ in range(1000)]

# Create a queue and perform operations
queue = Queue()

# Enqueue 1000 random strings
for s in random_strings:
    queue.enqueue(s)

# Dequeue 500 items
for _ in range(500):
    queue.dequeue()

# Enqueue 500 new random strings
for s in random_strings[:500]:
    queue.enqueue(s)

# Check the size of the queue
queue_size = queue.size()

# Get the front item
front_item = queue.front()
