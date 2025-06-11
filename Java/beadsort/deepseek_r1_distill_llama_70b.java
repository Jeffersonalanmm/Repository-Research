package Java.beadsort;//by author 

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class deepseek_r1_distill_llama_70b {

    public static void sort(int[] array) {
        if (array == null || array.length == 0) {
            return;
        }

        List<Queue<Integer>> pegs = new ArrayList<>();
        for (int i = 0; i < array.length; i++) {
            pegs.add(new LinkedList<>());
        }

        // Place beads on the first peg
        Queue<Integer> firstPeg = pegs.get(0);
        for (int num : array) {
            firstPeg.add(num);
        }

        // Simulate beads falling through pegs
        boolean moved;
        do {
            moved = false;
            for (int i = 0; i < pegs.size() - 1; i++) {
                Queue<Integer> currentPeg = pegs.get(i);
                Queue<Integer> nextPeg = pegs.get(i + 1);

                if (!currentPeg.isEmpty()) {
                    int bead = currentPeg.peek();
                    if (nextPeg.isEmpty() || bead < nextPeg.peek()) {
                        currentPeg.poll();
                        nextPeg.add(bead);
                        moved = true;
                    }
                }
            }
        } while (moved);

        // Collect sorted beads
        int index = 0;
        for (Queue<Integer> peg : pegs) {
            while (!peg.isEmpty()) {
                array[index++] = peg.poll();
            }
        }
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = (int) (Math.random() * 1000);
        }
        deepseek_r1_distill_llama_70b.sort(array);
    }
}