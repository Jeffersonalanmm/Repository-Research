
import java.util.ArrayList;
import java.util.List;
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
        List<Integer> input = new ArrayList<>();

        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                input.add(Integer.parseInt(line.trim()));
            }
        } catch (java.io.IOException e) {
            return;
        }

        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();
        beadSort(arr);
    }
}