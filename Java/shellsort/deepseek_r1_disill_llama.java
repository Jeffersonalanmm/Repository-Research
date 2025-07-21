
import java.util.ArrayList;
import java.util.List;

public class deepseek_r1_disill_llama {

    public static void shellSort(int[] array) {
        int n = array.length;
        
        // Ciura's sequence: 1, 4, 9, 21, 55, 131, 301, ...
        int gap = 1;
        while (gap < n / 3) {
            gap = gap * 3 + 1;
        }
        
        // Start with the largest gap and reduce it
        while (gap >= 1) {
            for (int i = gap; i < n; i++) {
                int temp = array[i];
                int j = i;
                
                // Shift elements that are greater than the current element
                while (j >= gap && array[j - gap] > temp) {
                    array[j] = array[j - gap];
                    j -= gap;
                }
                
                array[j] = temp;
            }
            
            // Reduce the gap for the next iteration
            gap = gap == 1 ? 0 : (gap - 1) / 3;
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
        shellSort(arr);


    }

}
