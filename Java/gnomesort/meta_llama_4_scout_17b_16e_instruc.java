
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class meta_llama_4_scout_17b_16e_instruc {

    public static void gnomeSort(int[] arr) {
        int n = arr.length;
        int i = 1;
        while (i < n) {
            if (arr[i-1] <= arr[i]) {
                i++;
            } else {
                // Swap arr[i-1] and arr[i]
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                if (i > 1) {
                    i--;
                }
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

        // Converte List<Integer> diretamente para int[]
        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();

        // Usa o método existente
        gnomeSort(arr);

    }

}
