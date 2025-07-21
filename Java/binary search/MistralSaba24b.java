import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class MistralSaba24b {

    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if target is present at mid
            if (array[mid] == target) {
                return mid;
            }

            // If target greater, ignore left half
            if (array[mid] < target) {
                left = mid + 1;
            }
            // If target is smaller, ignore right half
            else {
                right = mid - 1;
            }
        }

        // Target is not present in array
        return -1;
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