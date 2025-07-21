

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

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
        deepseek_r1_disill_llama<Integer> queue = new deepseek_r1_disill_llama<>();

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

