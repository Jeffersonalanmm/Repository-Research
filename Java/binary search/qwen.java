import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class qwen {

     public static int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
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
