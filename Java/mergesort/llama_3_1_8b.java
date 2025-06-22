package Java.mergesort;

public class llama_3_1_8b {

    /**
     * Merge two sorted arrays into one sorted array.
     * 
     * @param left  The first sorted array.
     * @param right The second sorted array.
     * @return A new sorted array containing all elements from both input arrays.
     */
    public static int[] merge(int[] left, int[] right) {
        int[] merged = new int[left.length + right.length];
        int leftIndex = 0;
        int rightIndex = 0;
        int mergedIndex = 0;

        // Merge smaller elements first
        while (leftIndex < left.length && rightIndex < right.length) {
            if (left[leftIndex] <= right[rightIndex]) {
                merged[mergedIndex++] = left[leftIndex++];
            } else {
                merged[mergedIndex++] = right[rightIndex++];
            }
        }

        // If there are remaining elements in the left array, append them to the merged array
        while (leftIndex < left.length) {
            merged[mergedIndex++] = left[leftIndex++];
        }

        // If there are remaining elements in the right array, append them to the merged array
        while (rightIndex < right.length) {
            merged[mergedIndex++] = right[rightIndex++];
        }

        return merged;
    }

    /**
     * Recursively divide the input array into two halves until each subarray contains only one element.
     * Then, merge the subarrays back together in sorted order.
     * 
     * @param arr The input array to be sorted.
     * @return A new sorted array containing all elements from the input array.
     */
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr; // Base case: If the array has one or zero elements, it's already sorted.
        }

        int mid = arr.length / 2;
        int[] left = new int[mid];
        int[] right = new int[arr.length - mid];

        System.arraycopy(arr, 0, left, 0, mid);
        System.arraycopy(arr, mid, right, 0, arr.length - mid);

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 3, 1, 6, 4};
        int[] sortedArr = mergeSort(arr);
    }
}
