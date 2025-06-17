import java.util.Arrays;
import java.util.Random;

public class MistralSaba24b {

    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if target is present at mid
            if (array[mid] == target) {
                return mid;
            }

            // If target greater, ignore left half
            if (array[mid] < target) {
                left = mid + 1;
            }
            // If target is smaller, ignore right half
            else {
                right = mid - 1;
            }
        }

        // Target is not present in array
        return -1;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(10000);
        }
        Arrays.sort(array);

        int target = random.nextInt(10000);
        int result = binarySearch(array, target);

        // The result can be used further as needed
    }
}