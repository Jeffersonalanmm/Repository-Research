
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
public class Gemma2_9b_it {
  

    private LinkedList<Integer> queue;

    public Gemma2_9b_it() {
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

    public static void main(String[] args) {
        Gemma2_9b_it queue = new Gemma2_9b_it();

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
