package Java.patiencesort;
import java.util.*;
public class meta_llama_4_scout_17b_16e_instruc {

    public static int[] patienceSort(int[] arr) {
        List<Integer> piles = new ArrayList<>();
        piles.add(arr[0]);

        for (int i = 1; i < arr.length; i++) {
            int idx = binarySearch(piles, arr[i]);
            if (idx == piles.size()) {
                piles.add(arr[i]);
            } else {
                piles.set(idx, arr[i]);
            }
        }

        int[] result = new int[piles.size()];
        for (int i = 0; i < piles.size(); i++) {
            result[i] = piles.get(i);
        }
        return result;
    }

    private static int binarySearch(List<Integer> list, int target) {
        int left = 0;
        int right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(10000);
        }
        int[] sortedArr = patienceSort(arr);
    }

}