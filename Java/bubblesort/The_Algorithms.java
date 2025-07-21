import java.util.ArrayList;
import java.util.List;

public class The_Algorithms {

    public <T extends Comparable<T>> T[] sort(T[] array) {
        for (int i = 1, size = array.length; i < size; ++i) {
            boolean swapped = false;
            for (int j = 0; j < size - i; ++j) {
                if (greater(array[j], array[j + 1])) {
                    swap(array, j, j + 1);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        return array;
    }

    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

        public static <T extends Comparable<T>> boolean greater(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) > 0;
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

        // Use the generic sort method
        The_Algorithms algo = new The_Algorithms();
        algo.sort(arr);

        // Convert sorted Integer[] back to List<Integer> if needed
        List<Integer> sorted = new ArrayList<>();
        for (int num : arr) {
            sorted.add(num);
        }
    }
}

