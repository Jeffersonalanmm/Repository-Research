package Java.patiencesort;
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
        Random random = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = random.nextInt(10000);
        }

        patienceSort(array);
    }

}
