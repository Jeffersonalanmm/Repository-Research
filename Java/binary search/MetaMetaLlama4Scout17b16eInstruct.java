import java.util.Random;

public class MetaMetaLlama4Scout17b16eInstruct {

    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(1000);
        }
        java.util.Arrays.sort(arr);

        int target = rand.nextInt(1000);

        int result = binarySearch(arr, target);
    }
}