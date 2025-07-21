

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class mistral_saba_24b {
    public static void cycleSort(int[] array) {
        int n = array.length;
        for (int cycleStart = 0; cycleStart <= n - 1; cycleStart++) {
            int item = array[cycleStart];
            int pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }
            while (item == array[pos]) {
                pos += 1;
            }
            if (pos != cycleStart) {
                int temp = item;
                item = array[pos];
                array[pos] = temp;
            }
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < n; i++) {
                    if (array[i] < item) {
                        pos += 1;
                    }
                }
                while (item == array[pos]) {
                    pos += 1;
                }
                if (item != array[pos]) {
                    int temp = item;
                    item = array[pos];
                    array[pos] = temp;
                }
            }
        }
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

        cycleSort(arr);

        // Convert sorted int[] back to List<Integer> if needed
        List<Integer> sorted = new ArrayList<>();
        for (int num : arr) {
            sorted.add(num);
        }

    }
}
