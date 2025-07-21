import java.util.ArrayList;
import java.util.List;

public class The_Algorithms {

/**
 * Implementation of gnome sort
 *
 * @author Podshivalov Nikita (https://github.com/nikitap492)
 * @since 2018-04-10
 */

    public <T extends Comparable<T>> T[] sort(final T[] array) {
        int i = 1;
        int j = 2;
        while (i < array.length) {
            if (less(array[i - 1], array[i])) {
                i = j++;
            } else {
                swap(array, i - 1, i);
                if (--i == 0) {
                    i = j++;
                }
            }
        }

        return array;
    }
        public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }

    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
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

        new The_Algorithms().sort(arr);

        // Convert sorted Integer[] back to List<Integer> if needed
        List<Integer> sorted = new ArrayList<>();
        for (int num : arr) {
            sorted.add(num);
        }

    }
}

