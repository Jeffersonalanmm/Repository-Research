
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
public class mistral_saba_24b {

    public static void patienceSort(int[] array) {
        List<List<Integer>> piles = new ArrayList<>();
        for (int i = 0; i < array.length; i++) {
            int value = array[i];
            boolean placed = false;
            for (List<Integer> pile : piles) {
                if (pile.isEmpty() || pile.get(pile.size() - 1) >= value) {
                    pile.add(value);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                List<Integer> newPile = new ArrayList<>();
                newPile.add(value);
                piles.add(newPile);
            }
        }

        int index = 0;
        for (List<Integer> pile : piles) {
            Collections.reverse(pile);
            for (int value : pile) {
                array[index++] = value;
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
        patienceSort(arr);

        // Imprime resultado (opcional)
        for (int num : arr) {
            System.out.println(num);
        }
    }



}
