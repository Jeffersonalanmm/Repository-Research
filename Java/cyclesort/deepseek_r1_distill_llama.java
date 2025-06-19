package Java.cyclesort;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class deepseek_r1_distill_llama {

    public static void cycleSort(int[] array) {
        int n = array.length;
        int start = 0;
        while (start < n) {
            if (array[start] == start + 1) {
                start++;
                continue;
            }


            int current = start;
            int cycleSize = 0;
            while (true) {
                int next = array[current] - 1;
                if (next == start) {
                    break;
                }
                current = next;
                cycleSize++;
            }
            cycleSize++; // Include the starting point


            // Collect cycle elements
            List<Integer> cycleElements = new ArrayList<>();
            current = start;
            do {
                cycleElements.add(array[current]);
                current = array[current] - 1;
            } while (current != start);


            // Reverse the cycle elements to get the correct order
            Collections.reverse(cycleElements);


            // Assign back
            int index = start;
            for (int i = 0; i < cycleElements.size(); i++) {
                array[index++] = cycleElements.get(i);
            }


            start += cycleSize;
        }
    }


    public static void main(String[] args) {
        // Example usage:
        int[] array = {3, 1, 2, 4};
        cycleSort(array);
        // The sorted array should be [1,2,3,4]
    }
}
