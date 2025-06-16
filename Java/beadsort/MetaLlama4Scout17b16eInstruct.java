import java.util.Random;

public class MetaLlama4Scout17b16eInstruct {

    public static void beadsort(int[] arr) {
        if (arr.length == 0) return;

        int max = getMax(arr);
        int[] beads = new int[max + 1];

        for (int i : arr) {
            beads[i]++;
        }

        int j = 0;
        for (int i = 0; i < beads.length; i++) {
            while (beads[i] > 0) {
                arr[j] = i;
                j++;
                beads[i]--;
            }
        }
    }

    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(1000);
        }
        beadsort(arr);
    }
}

