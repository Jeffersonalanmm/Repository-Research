
public class Llama318bInstant {

    /**
     * Searches for the target element in the sorted array using Binary Search algorithm.
     * 
     * @param arr   the sorted array to search in
     * @param target the element to search for
     * @return the index of the target element if found, -1 otherwise
     */
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = i;
        }

        // Test the binary search function
        for (int i = 0; i < 1000; i++) {
            int result = binarySearch(arr, i);
            // No print statement, just test the function
        }
    }
}
