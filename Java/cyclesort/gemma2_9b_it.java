package Java.cyclesort;

import java.util.Random;

public class gemma2_9b_it {
     public static void cycleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            // Find the correct position of the current element
            int pos = arr[i];
            if (arr[pos] == i) {
                continue; // Element is already in its correct position
            }

            // Perform cycle sort
            while (arr[pos] != i) {
                // Swap elements
                int temp = arr[pos];
                arr[pos] = arr[i];
                arr[i] = temp;

                // Update position
                pos = arr[pos];
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = random.nextInt(1000);
        }

        cycleSort(arr);
    }
}
