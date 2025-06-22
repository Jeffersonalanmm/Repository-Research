package Java.patiencesort;

public class llama_3_1_8b {

    public static void main(String[] args) {
        int[] arr = new int[1000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int) (Math.random() * 1000);
        }
        int[] sortedArr = patienceSort(arr);
    }

    public static int[] patienceSort(int[] arr) {
        // Create a deck of piles
        int[] piles = new int[arr.length];
        int[] sortedPiles = new int[arr.length];

        // Initialize the piles
        for (int i = 0; i < arr.length; i++) {
            piles[i] = arr[i];
        }

        // Sort the piles
        for (int i = 0; i < arr.length; i++) {
            int max = Integer.MIN_VALUE;
            int maxIndex = -1;
            for (int j = 0; j < piles.length; j++) {
                if (piles[j] > max) {
                    max = piles[j];
                    maxIndex = j;
                }
            }
            sortedPiles[i] = max;
            piles[maxIndex] = Integer.MIN_VALUE;
        }

        return sortedPiles;
    }
}
