package Java.heapsort;

public class llama_3_1_8b_instant {

    /**
     * Heapify the array at the given index.
     * 
     * @param arr The array to heapify.
     * @param n   The size of the array.
     * @param i   The index to start heapifying from.
     */
    private static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    /**
     * Build a max heap from the given array.
     * 
     * @param arr The array to build the heap from.
     * @param n   The size of the array.
     */
    private static void buildMaxHeap(int[] arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    /**
     * Heap sort the given array.
     * 
     * @param arr The array to sort.
     */
    public static void heapSort(int[] arr) {
        int n = arr.length;

        buildMaxHeap(arr, n);

        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 12, 11, 13, 5, 6, 7 };
        int n = arr.length;

        heapSort(arr);

        // The sorted array is stored in arr[]
    }
}
