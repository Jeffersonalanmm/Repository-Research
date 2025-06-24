package Java.queue;

import org.w3c.dom.Node;

public class deepseek_r1_disill_llama<T> {
    private Node<T> front;
    private Node<T> rear;
    
    private class Node<T> {
        T data;
        Node<T> next;
        
        public Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    public void enqueue(T data) {
        Node<T> newNode = new Node<>(data);
        if (rear == null) {
            front = newNode;
            rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }
    }

    public T dequeue() {
        if (front == null) {
            return null;
        }
        T data = front.data;
        front = front.next;
        if (front == null) {
            rear = null;
        }
        return data;
    }

    public T peek() {
        return front != null ? front.data : null;
    }

    public boolean isEmpty() {
        return front == null;
    }

    public static void main(String[] args) {
        deepseek_r1_disill_llama<Integer> queue = new deepseek_r1_disill_llama<>(); // Create a queue 10 random integers
        for (int i = 0; i < 10; i++) {
            queue.enqueue((int) (Math.random() * 100));
        }
        
        // Dequeue and print all elements
        while (!queue.isEmpty()) {
            System.out.println(queue.dequeue());
        }
        
        // Test empty queue
        System.out.println(queue.dequeue()); // Should print null
        System.out.println(queue.peek());    // Should print null
        System.out.println(queue.isEmpty()); // Should print true
    }
}

