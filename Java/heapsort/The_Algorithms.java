import java.util.ArrayList;
import java.util.List;

public class The_Algorithms {

/**
 * Heap Sort Algorithm Implementation
 *
 * @see <a href="https://en.wikipedia.org/wiki/Heapsort">Heap Sort Algorithm</a>
 */

    /**
     * For simplicity, we are considering the heap root index as 1 instead of 0.
     * This approach simplifies future calculations. As a result, we decrease
     * the indexes by 1 when calling {@link SortUtils#less(Comparable, Comparable)}
     * and provide adjusted values to the {@link SortUtils#swap(Object[], int, int)} methods.
     */
    public <T extends Comparable<T>> T[] sort(T[] array) {
        int n = array.length;
        heapify(array, n);
        while (n > 1) {
            swap(array, 0, n - 1);
            n--;
            siftDown(array, 1, n);
        }
        return array;
    }

    private <T extends Comparable<T>> void heapify(final T[] array, final int n) {
        for (int k = n / 2; k >= 1; k--) {
            siftDown(array, k, n);
        }
    }

    private <T extends Comparable<T>> void siftDown(final T[] array, int k, final int n) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && less(array[j - 1], array[j])) {
                j++;
            }
            if (!less(array[k - 1], array[j - 1])) {
                break;
            }
            swap(array, k - 1, j - 1);
            k = j;
        }
    }

    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
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
        algo.sort(arr);

    }
}

