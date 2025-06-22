package Java.patiencesort;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class deepseek_r1_disill_llama {


    public static void patienceSort(int[] array) {
        List<List<Integer>> piles = new ArrayList<>();
        List<Integer> tops = new ArrayList<>();

        for (int number : array) {
            int index = binarySearch(tops, number);
            if (index != -1) {
                piles.get(index).add(number);
                tops.set(index, number);
            } else {
                List<Integer> newPile = new ArrayList<>();
                newPile.add(number);
                piles.add(newPile);
                tops.add(number);
            }
        }
    }

    private static int binarySearch(List<Integer> tops, int target) {
        int low = 0;
        int high = tops.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tops.get(mid) > target) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(1001);
        }
        patienceSort(array);
    }

}
