import java.util.ArrayList;
import java.util.List;
public class The_Algorithms {

    /**
     * Implements generic shell sort.
     *
     * @param array the array to be sorted.
     * @param <T> the type of elements in the array.
     * @return the sorted array.
     */

    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) {
            return array;
        }

        int gap = calculateInitialGap(array.length);

        while (gap > 0) {
            performGapInsertionSort(array, gap);
            gap = calculateNextGap(gap);
        }

        return array;
    }

    /**
     * Calculates the initial gap value using the Knuth sequence.
     *
     * @param length the length of the array.
     * @return the initial gap value.
     */
    private int calculateInitialGap(final int length) {
        int gap = 1;
        while (gap < length / 3) {
            gap = 3 * gap + 1;
        }
        return gap;
    }

    /**
     * Calculates the next gap value.
     *
     * @param currentGap the current gap value.
     * @return the next gap value.
     */
    private int calculateNextGap(final int currentGap) {
        return currentGap / 3;
    }

    /**
     * Performs an insertion sort for the specified gap value.
     *
     * @param array the array to be sorted.
     * @param gap the current gap value.
     * @param <T> the type of elements in the array.
     */
    private <T extends Comparable<T>> void performGapInsertionSort(final T[] array, final int gap) {
        for (int i = gap; i < array.length; i++) {
            T temp = array[i];
            int j;
            for (j = i; j >= gap && less(temp, array[j - gap]); j -= gap) {
                array[j] = array[j - gap];
            }
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

        // Converte List<Integer> para Integer[]
        Integer[] arr = input.toArray(new Integer[0]);

        // Usa o método existente
        new The_Algorithms().sort(arr);

    }

    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }
}

