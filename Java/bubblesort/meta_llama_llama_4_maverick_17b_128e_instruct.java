package Java.bubblesort;
import java.util.Random;
public class meta_llama_llama_4_maverick_17b_128e_instruct {
        public static void main(String[] args) {
        int[] arr = new int[1000];
        Random rand = new Random();
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(1000);
        }
        bubbleSort(arr);
    }

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
}
