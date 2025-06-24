package Java.queue;
import java.util.LinkedList;
public class gemma2_9b_it {
  

    private LinkedList<Integer> queue;

    public gemma2_9b_it() {
        queue = new LinkedList<>();
    }

    public void enqueue(int data) {
        queue.addLast(data);
    }

    public int dequeue() {
        return queue.removeFirst();
    }

    public int peek() {
        return queue.getFirst();
    }

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public int size() {
        return queue.size();
    }

}
