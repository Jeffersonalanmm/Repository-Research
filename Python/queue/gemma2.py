
class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

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
