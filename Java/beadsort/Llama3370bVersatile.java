
import java.util.Random;

public class Llama3370bVersatile{

    public static void beadSort(int[] array) {
        int max = getMax(array);
        int[] beads = new int[max + 1];

        for (int i = 0; i < array.length; i++) {
            beads[array[i]]++;
        }

        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (beads[i] > 0) {
                array[index++] = i;
                beads[i]--;
            }
        }
    }

    public static int getMax(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(1000);
        }
        beadSort(array);
    }
}