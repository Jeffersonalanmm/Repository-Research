
public class llama_3_3_70b_versatile { //class name replaced by author
    /**
     * Optimized implementation of the Bubblesort algorithm.
     * 
     * @param array the input array to be sorted
     * @return the sorted array
     */
    public static int[] bubbleSort(int[] array) {
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
            // If no two elements were swapped in the inner loop, the array is sorted
            if (!swapped) {
                break;
            }
        }
        return array;
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        // Initialize the array with random values
        for (int i = 0; i < 1000; i++) {
            array[i] = (int) (Math.random() * 1000);
        }
        int[] sortedArray = bubbleSort(array);
    }
}