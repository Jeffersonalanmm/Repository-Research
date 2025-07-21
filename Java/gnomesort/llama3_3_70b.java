
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class llama3_3_70b {
      /**
     * Gnome sort algorithm implementation.
     * 
     * @param array the input array to be sorted
     */
    public static void gnomeSort(int[] array) {
        int position = 0;
        while (position < array.length - 1) {
            if (array[position] <= array[position + 1]) {
                position++;
            } else {
                // Swap elements
                int temp = array[position];
                array[position] = array[position + 1];
                array[position + 1] = temp;
                if (position > 0) {
                    position--;
                }
            }
        }
    }

    /**
     * Generate an array of 1000 random integers.
     * 
     * @return an array of 1000 random integers
     */
    public static int[] generateRandomArray() {
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(1001); // Generate random numbers between 0 and 1000
        }
        return array;
    }

    /**
     * Main function to test the gnome sort algorithm.
     * 
     * @param args command-line arguments (not used)
     */
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
        gnomeSort(arr);


    }

}
