package Java.shellsort;

public class llama_3_1_8b {

    /**
     * Shell sort algorithm implementation.
     * 
     * @param arr The array to be sorted.
     */
    public static void shellSort(int[] arr) {
        int n = arr.length;
        int gap = n / 2;

        while (gap > 0) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j = i;

                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }

                arr[j] = temp;
            }

            gap /= 2;
        }
    }

    public static void main(String[] args) {
        // Test the implementation with 1000 random inputs
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = (int) (Math.random() * 1000);
        }

        shellSort(arr);
    }

}
