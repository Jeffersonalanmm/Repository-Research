package Java.patiencesort;
import java.util.*;
public class llama3_3_70b {

    public static List<Integer> patienceSort(List<Integer> input) {
        // Initialize piles
        List<List<Integer>> piles = new ArrayList<>();

        // Iterate over input
        for (Integer num : input) {
            // Find the first pile where num can be added
            boolean added = false;
            for (List<Integer> pile : piles) {
                if (pile.isEmpty() || num <= pile.get(pile.size() - 1)) {
                    pile.add(num);
                    added = true;
                    break;
                }
            }

            // If num couldn't be added to any pile, create a new pile
            if (!added) {
                List<Integer> newPile = new ArrayList<>();
                newPile.add(num);
                piles.add(newPile);
            }
        }

        // Initialize result
        List<Integer> result = new ArrayList<>();

        // Merge piles
        while (!piles.isEmpty()) {
            // Find the pile with the smallest top card
            int minPileIndex = 0;
            for (int i = 1; i < piles.size(); i++) {
                if (piles.get(i).get(piles.get(i).size() - 1) < piles.get(minPileIndex).get(piles.get(minPileIndex).size() - 1)) {
                    minPileIndex = i;
                }
            }

            // Add top card of min pile to result
            result.add(piles.get(minPileIndex).remove(piles.get(minPileIndex).size() - 1));

            // Remove empty piles
            if (piles.get(minPileIndex).isEmpty()) {
                piles.remove(minPileIndex);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        // Generate 1000 random inputs
        Random rand = new Random();
        List<Integer> input = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            input.add(rand.nextInt(1000));
        }

        // Run patience sort
        List<Integer> sortedInput = patienceSort(input);
    }

}
