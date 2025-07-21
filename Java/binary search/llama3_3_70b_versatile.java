import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class llama3_3_70b_versatile {


    /**
     * Binary Search Algorithm implementation.
     * 
     * @param array The sorted array to search in.
     * @param target The target value to search for.
     * @return The index of the target value if found, -1 otherwise.
     */
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == target) {
                return mid;
            } else if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    /**
     * Generate a sorted array with 1000 random integers.
     * 
     * @return A sorted array with 1000 random integers.
     */
    public static int[] generateSortedArray() {
        int[] array = new int[1000];
        Random random = new Random();
        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(10000);
        }
        java.util.Arrays.sort(array);
        return array;
    }

    /**
     * Test the binary search algorithm with 1000 random inputs.
     */
    public static void testBinarySearch() {
        int[] array = generateSortedArray();
        Random random = new Random();
        for (int i = 0; i < 1000; i++) {
            int target = array[random.nextInt(1000)];
            int result = binarySearch(array, target);
            // No print statement, just the code
        }
    }

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
