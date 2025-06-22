package Java.heapsort;

public class deepseek_r1_disill_llama {

    public static void heapSort(int[] array) {
        int n = array.length;
        
        // Build max heap
        buildMaxHeap(array, n);
        
        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            // Swap root max with last element
            swap(array, 0, i);
            
            // Call max heapify on the reduced heap
            heapify(array, 0, i);
        }
    }

    private static void buildMaxHeap(int[] array, int n) {
        // Start from the last non-leaf node and move backwards
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(array, i, n);
        }
    }

    private static void heapify(int[] array, int index, int heapSize) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Find the largest element
        if (left < heapSize && array[left] > array[largest]) {
            largest = left;
        }
        if (right < heapSize && array[right] > array[largest]) {
            largest = right;
        }

        // If root is not largest, swap and continue heapifying
        if (largest != index) {
            swap(array, index, largest);
            heapify(array, largest, heapSize);
        }
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        java.util.Random rand = new java.util.Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(1001);
        }
        heapSort(array);
        
        // Verify sorted order
        for (int i = 0; i < 999; i++) {
            if (array[i] > array[i + 1]) {
                throw new RuntimeException("Array not sorted correctly");
            }
        }
    }
}

