package Java.queue;
    import java.util.Random;
public class meta_llama_4_scout_17b_16e_instruct {
    private int[] queue;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public meta_llama_4_scout_17b_16e_instruct(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = 0;
        this.rear = 0;
        this.size = 0;
    }

    // Add an element to the queue
    public void enqueue(int data) {
        if (isFull()) {
            resize();
        }
        queue[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Remove an element from the queue
    public int dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        int temp = queue[front];
        front = (front + 1) % capacity;
        size--;
        return temp;
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    public boolean isFull() {
        return size == capacity;
    }

    // Get the front element of the queue
    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return queue[front];
    }

    // Resize the queue when it's full
    private void resize() {
        int[] temp = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = queue[(front + i) % capacity];
        }
        front = 0;
        rear = size;
        capacity *= 2;
        queue = temp;
    }

    public static void main(String[] args) {
        Random random = new Random();
        meta_llama_4_scout_17b_16e_instruct queue = new meta_llama_4_scout_17b_16e_instruct(10);
        for (int i = 0; i < 1000; i++) {
            int operation = random.nextInt(3);
            int data = random.nextInt(1000);
            switch (operation) {
                case 0:
                    queue.enqueue(data);
                    break;
                case 1:
                    if (!queue.isEmpty()) {
                        queue.dequeue();
                    }
                    break;
                case 2:
                    if (!queue.isEmpty()) {
                        queue.peek();
                    }
                    break;
            }
        }
    }
}

