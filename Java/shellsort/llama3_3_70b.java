
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class llama3_3_70b {


    /**
     * Sorts an array using the shell sort algorithm.
     * 
     * @param array the array to be sorted
     */
    public static void shellSort(int[] array) {
        int n = array.length;
        int gap = n / 2;

        while (gap > 0) {
            for (int i = gap; i < n; i++) {
                int temp = array[i];
                int j = i;

                while (j >= gap && array[j - gap] > temp) {
                    array[j] = array[j - gap];
                    j -= gap;
                }

                array[j] = temp;
            }

            gap /= 2;
        }
    }

    /**
     * Generates an array of 1000 random integers.
     * 
     * @return an array of 1000 random integers
     */
    public static int[] generateRandomArray() {
        Random random = new Random();
        int[] array = new int[1000];

        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(1001);
        }

        return array;
    }

    /**
     * Checks if an array is sorted.
     * 
     * @param array the array to be checked
     * @return true if the array is sorted, false otherwise
     */
    public static boolean isSorted(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1]) {
                return false;
            }
        }

        return true;
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
        shellSort(arr);

        // Imprime resultado (opcional)
        for (int num : arr) {
            System.out.println(num);
        }
    }

}
