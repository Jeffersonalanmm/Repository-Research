package Java.patiencesort;
import java.util.*;
public class meta_llama_llama_4_maverick_17b_128e_instruct {

    public static List<Integer> patienceSort(List<Integer> nums) {
        List<List<Integer>> piles = new ArrayList<>();

        for (int num : nums) {
            int index = binarySearch(piles, num);
            if (index == piles.size()) {
                List<Integer> pile = new ArrayList<>();
                pile.add(num);
                piles.add(pile);
            } else {
                piles.get(index).add(num);
            }
        }

        List<Integer> sorted = new ArrayList<>();
        PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> a.value - b.value);

        for (int i = 0; i < piles.size(); i++) {
            queue.offer(new Pair(i, 0, piles.get(i).get(0)));
        }

        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            sorted.add(pair.value);

            int pileIndex = pair.pileIndex;
            int elementIndex = pair.elementIndex + 1;

            if (elementIndex < piles.get(pileIndex).size()) {
                queue.offer(new Pair(pileIndex, elementIndex, piles.get(pileIndex).get(elementIndex)));
            }
        }

        return sorted;
    }

    private static int binarySearch(List<List<Integer>> piles, int target) {
        int left = 0;
        int right = piles.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (piles.get(mid).get(piles.get(mid).size() - 1) > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private static class Pair {
        int pileIndex;
        int elementIndex;
        int value;

        public Pair(int pileIndex, int elementIndex, int value) {
            this.pileIndex = pileIndex;
            this.elementIndex = elementIndex;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            nums.add(random.nextInt(10000));
        }
        List<Integer> sorted = patienceSort(nums);
        // No print statement
    }
}