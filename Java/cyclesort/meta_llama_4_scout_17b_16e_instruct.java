import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class meta_llama_4_scout_17b_16e_instruct {
    

    public static void cycleSort(int[] array) {
        int writes = 0;
        for (int cycleStart = 0; cycleStart < array.length - 1; cycleStart++) {
            int item = array[cycleStart];
            int pos = cycleStart;
            for (int i = cycleStart + 1; i < array.length; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }
            if (pos == cycleStart) {
                continue;
            }
            while (item == array[pos]) {
                pos++;
            }
            int temp = array[pos];
            array[pos] = item;
            item = temp;
            writes++;
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < array.length; i++) {
                    if (array[i] < item) {
                        pos++;
                    }
                }
                while (item == array[pos]) {
                    pos++;
                }
                temp = array[pos];
                array[pos] = item;
                item = temp;
                writes++;
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

