package Java.gnomesort;
import java.util.Random;
public class gemma2_9b_it {

    public static void gnomeSort(int[] arr) {
        int index = 1;
        while (index < arr.length) {
            if (arr[index] >= arr[index - 1]) {
                index++;
            } else {
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                index--;
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(1000);
        }
        gnomeSort(arr);
    }
}
