
import java.util.Random;

public class gemma29bit {

    public static void beadSort(int[] arr) {
        int max = getMax(arr);
        int[] beads = new int[max + 1];

        for (int i = 0; i < arr.length; i++) {
            beads[arr[i]]++;
        }

        int index = 0;
        for (int i = 0; i < beads.length; i++) {
            while (beads[i] > 0) {
                arr[index++] = i;
                beads[i]--;
            }
        }
    }

    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(1000);
        }
        beadSort(arr);
    }
}
