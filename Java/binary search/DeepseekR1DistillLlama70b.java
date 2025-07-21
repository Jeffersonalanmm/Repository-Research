import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DeepseekR1DistillLlama70b {

    /**
     * Searches for the specified target value in the given sorted array.
     * 
     * @param array  the sorted array to search in
     * @param target the value to search for
     * @return the index of the target value if found; otherwise, -1
     */
    public static int binarySearch(int[] array, int target) {
        return binarySearch(array, target, 0, array.length - 1);
    }

    /**
     * Helper method to perform the binary search within the specified range.
     * 
     * @param array  the sorted array to search in
     * @param target the value to search for
     * @param low    the starting index of the current search range
     * @param high   the ending index of the current search range
     * @return the index of the target value if found; otherwise, -1
     */
    private static int binarySearch(int[] array, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid integer overflow

            if (array[mid] == target) {
                return mid;
            } else if (array[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // Example usage:
    public static void main(String[] args) {
        List<Integer> inputList = new ArrayList<>();

        // Ler o array ordenado de ../../inputs.txt
        try (BufferedReader br = new BufferedReader(new FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                inputList.add(Integer.parseInt(line.trim()));
            }
        } catch (IOException e) {
            return;
        }

        int[] array = inputList.stream().mapToInt(Integer::intValue).toArray();

        int target = 15;
        Arrays.sort(array);
        int result = binarySearch(array, target);
    }
}
