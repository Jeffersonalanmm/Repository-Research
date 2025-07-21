
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
public class llama3_3_70b {

    private int[] queue;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public llama3_3_70b(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = 0;
        this.rear = 0;
        this.size = 0;
    }

    // Add an element to the queue
    public void enqueue(int value) {
        if (isFull()) {
            // Handle queue full scenario
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Remove an element from the queue
    public int dequeue() {
        if (isEmpty()) {
            // Handle queue empty scenario
            return -1;
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

    // Get the size of the queue
    public int size() {
        return size;
    }

    // Get the front element of the queue
    public int front() {
        if (isEmpty()) {
            // Handle queue empty scenario
            return -1;
        }
        return queue[front];
    }

    // Get the rear element of the queue
    public int rear() {
        if (isEmpty()) {
            // Handle queue empty scenario
            return -1;
        }
        return queue[(rear - 1 + capacity) % capacity];
    }

    public static void main(String[] args) {
        llama3_3_70b queue = new llama3_3_70b(100); // Set capacity as needed

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim());
                queue.enqueue(value);
            }
        } catch (IOException e) {
            return;
        }

        // Desenfileirar e imprimir todos os elementos
        while (!queue.isEmpty()) {
            queue.dequeue();
        }
    }
}

