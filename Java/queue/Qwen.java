import java.util.NoSuchElementException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Qwen<E> {
    private static class Node<E> {
        E data;
        Node<E> next;


        Node(E data) {
            this.data = data;
            this.next = null;
        }
    }


    private Node<E> head;
    private Node<E> tail;
    private int size;


    public Qwen() {
        head = null;
        tail = null;
        size = 0;
    }


    public void enqueue(E element) {
        Node<E> newNode = new Node<>(element);
        if (tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }


    public E dequeue() {
        if (head == null) {
            throw new NoSuchElementException("Dequeue from empty queue");
        }
        E data = head.data;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return data;
    }


    public E peek() {
        if (head == null) {
            throw new NoSuchElementException("Peek on empty queue");
        }
        return head.data;
    }


    public int size() {
        return size;
    }

    public static void main(String[] args) {
        Qwen<Integer> queue = new Qwen<>();

        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim());
                queue.enqueue(value);
            }
        } catch (IOException e) {
            return;
        }

        // Desenfileirar todos os elementos
        while (queue.size() > 0) {
            queue.dequeue();
        }
    }
}
