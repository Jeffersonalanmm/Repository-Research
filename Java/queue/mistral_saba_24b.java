
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
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
        mistral_saba_24b queue = new mistral_saba_24b();

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
