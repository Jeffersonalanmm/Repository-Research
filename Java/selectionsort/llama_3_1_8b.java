package Java.selectionsort;

public class llama_3_1_8b {

    /**
     * Sorts an array of integers using the selection sort algorithm.
     * 
     * @param arr the array to be sorted
     */
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        
        // Traverse through all array elements
        for (int i = 0; i < n; i++) {
            // Find the minimum element in remaining unsorted array
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            
            // Swap the found minimum element with the first element of unsorted array
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    public static void main(String[] args) {
        // Test the implementation with 1000 random inputs
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = (int) (Math.random() * 1000);
        }
        
        selectionSort(arr);
    }

}
