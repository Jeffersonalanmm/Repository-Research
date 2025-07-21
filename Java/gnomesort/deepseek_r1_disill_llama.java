

import java.util.ArrayList;
import java.util.List;

import javax.swing.text.Position;

public class deepseek_r1_disill_llama {

    public static <T extends Comparable<T>> void gnomeSort(T[] array) {
        int n = array.length;
        int position = 0;
        boolean swapped;

        while (position < n) {
            swapped = false;

            // Move forward as long as the current element is less than the next
            while (position < n && (position == 0 || array[position].compareTo(array[position - 1]) >= 0)) {
                position++;
            }

            // If we've reached the end, the array is sorted
            if (position >= n) {
                break;
            }

            // Swap the current element with the previous one
            T temp = array[position];
            array[position] = array[position - 1];
            array[position - 1] = temp;
            swapped = true;

            // Move back to check the previous elements
            position--;

            // If a swap occurred, continue checking from the new position
            if (swapped) {
                position = Math.max(position - 1, 0);
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> input = new ArrayList<>();

        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                input.add(Integer.parseInt(line.trim()));
            }
        } catch (java.io.IOException e) {
            return;
        }

        // Convert List<Integer> to Integer[]
        Integer[] arr = input.toArray(new Integer[0]);

        gnomeSort(arr);

        // Convert sorted Integer[] back to List<Integer> if needed
        List<Integer> sorted = new ArrayList<>();
        for (int num : arr) {
            sorted.add(num);
        }

    }
}
