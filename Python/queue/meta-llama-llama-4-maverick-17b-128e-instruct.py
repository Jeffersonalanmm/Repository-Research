from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if self.is_empty():
            return None
        return self.queue.popleft()

    def is_empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)

    def peek(self):
        if self.is_empty():
            return None
        return self.queue[0]

def test_queue():
    queue = Queue()
    for i in range(1000):
        queue.enqueue(i)
    
    for _ in range(500):
        queue.dequeue()
    
    for i in range(500, 1000):
        assert queue.dequeue() == i

    assert queue.is_empty() == True
    assert queue.size() == 0
    assert queue.peek() == None
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
