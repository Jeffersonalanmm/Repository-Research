package Java.quicksort;

public class llama_3_1_8b {

    /**
     * This method implements the quick sort algorithm.
     * It recursively sorts the array by selecting a pivot element, partitioning the array around the pivot, and then recursively sorting the sub-arrays.
     * 
     * @param arr The array to be sorted.
     * @param low The starting index of the array.
     * @param high The ending index of the array.
     */
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    /**
     * This method partitions the array around a pivot element.
     * It rearranges the array such that all elements less than the pivot are on the left of the pivot, and all elements greater than the pivot are on the right.
     * 
     * @param arr The array to be partitioned.
     * @param low The starting index of the array.
     * @param high The ending index of the array.
     * @return The index of the pivot element after partitioning.
     */
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    /**
     * This method swaps two elements in the array.
     * 
     * @param arr The array containing the elements to be swapped.
     * @param i The index of the first element.
     * @param j The index of the second element.
     */
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 7, 3, 6, 8, 4};
        int n = arr.length;
        quickSort(arr, 0, n - 1);
    }

}
