
import java.util.Arrays;
import java.util.Random;

public class MistralSaba24b{

    public static void beadsort(int[] array) {
        int n = array.length;
        int max = Arrays.stream(array).max().getAsInt();

        // Create a 2D array to represent the beads
        boolean[][] beads = new boolean[max + 1][n];

        // Initialize the beads array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < array[i]; j++) {
                beads[j][i] = true;
            }
        }

        // Perform the beadsort
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < n; j++) {
                if (beads[i][j]) {
                    int k = j;
                    while (k > 0 && beads[i][k - 1]) {
                        // Swap beads
                        beads[i][k] = false;
                        beads[i][k - 1] = true;
                        k--;
                    }
                }
            }
        }

        // Extract the sorted array from the beads array
        for (int i = 0; i < n; i++) {
            for (int j = max; j >= 0; j--) {
                if (beads[j][i]) {
                    array[i] = j;
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(1000);
        }

        beadsort(array);
    }
}