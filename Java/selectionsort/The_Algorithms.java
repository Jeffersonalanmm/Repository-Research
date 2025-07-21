import java.util.ArrayList;
import java.util.List;

public class The_Algorithms {
    /**
     * Sorts an array of comparable elements in increasing order using the selection sort algorithm.
     *
     * @param array the array to be sorted
     * @param <T> the class of array elements
     * @return the sorted array
     */
    public <T extends Comparable<T>> T[] sort(T[] array) {

        for (int i = 0; i < array.length - 1; i++) {
            final int minIndex = findIndexOfMin(array, i);
            swap(array, i, minIndex);
        }
        return array;
    }

    private static <T extends Comparable<T>> int findIndexOfMin(T[] array, final int startIndex) {
        int minIndex = startIndex;
        for (int i = startIndex + 1; i < array.length; i++) {
            if (array[i].compareTo(array[minIndex]) < 0) {
                minIndex = i;
            }
        }
        return minIndex;
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

        // Converte List<Integer> diretamente para Integer[]
        Integer[] arr = input.toArray(new Integer[0]);

        // Usa o método existente
        The_Algorithms algo = new The_Algorithms();
        arr = algo.sort(arr);

    }
}

