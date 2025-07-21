
import java.util.ArrayList;
import java.util.List;

public class llama_3_1_8b {
       public static void cycleSort(int[] arr) {
        int n = arr.length;

        // Loop through the array to find cycles to rotate.
        for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
            // Find where to put the element at arr[cycleStart].
            int item = arr[cycleStart];

            int pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // If the item is already there, this is not a cycle.
            if (pos == cycleStart) {
                continue;
            }

            // Otherwise, put the item there or right after any duplicates.
            while (item == arr[pos]) {
                pos++;
            }
            swap(arr, pos, cycleStart);
            // Rotate the rest of the cycle the other way.
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < n; i++) {
                    if (arr[i] < item) {
                        pos++;
                    }
                }
                while (item == arr[pos]) {
                    pos++;
                }
                swap(arr, pos, cycleStart);
            }
        }
    }

    /**
     * Helper function to swap two elements in the array.
     * 
     * @param arr The input array.
     * @param i   The index of the first element.
     * @param j   The index of the second element.
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
