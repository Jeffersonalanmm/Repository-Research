import java.util.ArrayList;
import java.util.List;

public class qwen {
    public static void sort(int[] arr) {
        int n = arr.length;


        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }


        // One by one extract an element
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;


            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }


    private static void heapify(int[] arr, int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;
        int right = 2 * i + 2;


        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) { // typo here: "largets" should be "largest"
            largest = left;
        }


        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) { // again typo
            largest = right;
        }


        // If largest is not root
        if (largest != i) {
            // swap
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;


            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
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

        // Converte List<Integer> diretamente para int[]
        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();

        // Usa o método existente
        sort(arr);

    }
}
