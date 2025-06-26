package Java.selectionsort;
import java.util.Random;

public class llama3_3_70b {

    /**
     * Selection sort algorithm implementation.
     * 
     * @param array the input array to be sorted
     */
    public static void selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted portion
            swap(array, i, minIndex);
        }
    }

    /**
     * Helper method to swap two elements in the array.
     * 
     * @param array the input array
     * @param i     the index of the first element
     * @param j     the index of the second element
     */
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Generate an array of 1000 random integers and sort it using selection sort.
     */
    public static void main() {
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(1001); // Generate random integers between 0 and 1000
        }
        selectionSort(array);
    }

}
