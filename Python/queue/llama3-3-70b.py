
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
queue = Queue()
inputs = [random.randint(1, 100) for _ in range(1000)]

start_time = time.time()
for input_value in inputs:
    queue.enqueue(input_value)

for _ in range(len(inputs)):
    queue.dequeue()

end_time = time.time()
execution_time = end_time - start_time

# Verify the correctness of the Queue implementation
queue_correctness_test = Queue()
test_inputs = [random.randint(1, 100) for _ in range(1000)]

for test_input in test_inputs:
    queue_correctness_test.enqueue(test_input)

for _ in range(len(test_inputs)):
    assert queue_correctness_test.dequeue() is not None

assert queue_correctness_test.is_empty() == True
assert queue_correctness_test.peek() is None
