
import java.util.Random;

public class llama_3_3_70b_versatile {
    public static void bubbleSort(int[] array) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // Swap array[j] and array[j + 1]
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no two elements were swapped in inner loop, the array is sorted.
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(1000);
        }
        bubbleSort(array);
        // Test the sorted array
        for (int i = 0; i < 999; i++) {
            assert array[i] <= array[i + 1];
        }
    }
}