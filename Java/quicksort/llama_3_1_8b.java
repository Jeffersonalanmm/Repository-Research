import java.util.ArrayList;
import java.util.List;

public class llama_3_1_8b {

    /**
     * This method implements the quick sort algorithm.
     * It recursively sorts the array by selecting a pivot element, partitioning the array around the pivot, and then recursively sorting the sub-arrays.
     * 
     * @param arr The array to be sorted.
     * @param low The starting index of the array.
     * @param high The ending index of the array.
     */
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    /**
     * This method partitions the array around a pivot element.
     * It rearranges the array such that all elements less than the pivot are on the left of the pivot, and all elements greater than the pivot are on the right.
     * 
     * @param arr The array to be partitioned.
     * @param low The starting index of the array.
     * @param high The ending index of the array.
     * @return The index of the pivot element after partitioning.
     */
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    /**
     * This method swaps two elements in the array.
     * 
     * @param arr The array containing the elements to be swapped.
     * @param i The index of the first element.
     * @param j The index of the second element.
     */
    public static void swap(int[] arr, int i, int j) {
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

        // Converte List<Integer> diretamente para int[]
        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();

        // Usa o método existente
        quickSort(arr, 0, arr.length - 1);

    }

}
