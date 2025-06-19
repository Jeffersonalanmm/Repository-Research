package Java.gnomesort;
import java.util.Random;
public class meta_llama_4_scout_17b_16e_instruc {

    public static void gnomeSort(int[] arr) {
        int n = arr.length;
        int i = 1;
        while (i < n) {
            if (arr[i-1] <= arr[i]) {
                i++;
            } else {
                // Swap arr[i-1] and arr[i]
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                if (i > 1) {
                    i--;
                }
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(10000);
        }
        gnomeSort(arr);
    }
}
