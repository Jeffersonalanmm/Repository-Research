
import java.util.Random;

public class MetalLlamaLlama4Maverick17b128eInstruct {

    public static void main(String[] args) {
        int numTests = 1000;
        int maxSize = 100;
        int maxVal = 1000;
        Random rand = new Random();

        for (int i = 0; i < numTests; i++) {
            int[] arr = new int[rand.nextInt(maxSize) + 1];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = rand.nextInt(maxVal);
            }
            beadSort(arr);
        }
    }

    public static void beadSort(int[] arr) {
        if (arr.length == 0) return;

        int max = findMax(arr);
        int[][] beads = new int[arr.length][max + 1];

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j <= max; j++) {
                if (j <= arr[i]) {
                    beads[i][j] = 1;
                }
            }
        }

        for (int j = 0; j <= max; j++) {
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += beads[i][j];
                beads[i][j] = 0;
            }

            for (int i = arr.length - sum; i < arr.length; i++) {
                beads[i][j] = 1;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            int count = 0;
            for (int j = 0; j <= max; j++) {
                if (beads[i][j] == 1) {
                    count++;
                }
            }
            arr[i] = count;
        }
    }

    public static int findMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}
