package Java.bubblesort;

import java.util.Random;

public class mistral_saba_24b {
    public static void bubbleSort(int[] array) {
        int n = array.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    // Swap array[j] and array[j + 1]
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no two elements were swapped by inner loop, then break
            if (!swapped) break;
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(10000); // Random integers between 0 and 9999
        }
        bubbleSort(array);
    }
}
