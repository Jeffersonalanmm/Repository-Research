package Java.queue;
import java.util.LinkedList;
import java.util.Queue;

public class mistral_saba_24b {

    private Queue<Integer> queue;

    public mistral_saba_24b() {
        queue = new LinkedList<>();
    }

    public void enqueue(int value) {
        queue.add(value);
    }

    public int dequeue() {
        if (queue.isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return queue.poll();
    }

    public int size() {
        return queue.size();
    }

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public static void main(String[] args) {
        mistral_saba_24b optimizedQueue = new mistral_saba_24b();

        // 1000 random inputs
        for (int i = 0; i < 1000; i++) {
            optimizedQueue.enqueue((int) (Math.random() * 10000));
        }

        // Dequeue all elements
        while (!optimizedQueue.isEmpty()) {
            optimizedQueue.dequeue();
        }
    }
}
