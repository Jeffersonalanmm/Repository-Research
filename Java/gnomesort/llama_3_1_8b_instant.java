package Java.gnomesort;

public class llama_3_1_8b_instant {

    /**
     * Gnome sort algorithm implementation.
     * 
     * @param arr The array to be sorted.
     */
    public static void gnomeSort(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            if (i == 0 || arr[i] >= arr[i - 1]) {
                i++;
            } else {
                swap(arr, i, i - 1);
                i--;
            }
        }
    }

    /**
     * Swap two elements in the array.
     * 
     * @param arr The array.
     * @param i   The index of the first element.
     * @param j   The index of the second element.
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        gnomeSort(arr);
    }
}
