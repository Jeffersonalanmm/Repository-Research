import java.util.ArrayList;
import java.util.List;
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
        List<Integer> input = new ArrayList<>();

        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                input.add(Integer.parseInt(line.trim()));
            }
        } catch (java.io.IOException e) {
            return;
        }

        // Convert List<Integer> to int[]
        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();

        beadsort(arr);

        // Convert sorted int[] back to List<Integer> if needed
        List<Integer> sorted = new ArrayList<>();
        for (int num : arr) {
            sorted.add(num);
        }

    }
}

