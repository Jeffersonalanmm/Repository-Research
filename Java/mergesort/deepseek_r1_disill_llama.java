package Java.mergesort;
import java.util.Arrays;
public class deepseek_r1_disill_llama {

    public static void mergeSort(int[] array) {
        int[] aux = new int[array.length];
        mergeSort(array, aux, 0, array.length - 1);
    }

    private static void mergeSort(int[] array, int[] aux, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(array, aux, low, mid);
        mergeSort(array, aux, mid + 1, high);
        merge(array, aux, low, mid, high);
    }

    private static void merge(int[] array, int[] aux, int low, int mid, int high) {
        // Copy left half into aux
        for (int i = low; i <= mid; i++) {
            aux[i] = array[i];
        }

        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (aux[i] <= array[j]) {
                array[k++] = aux[i++];
            } else {
                array[k++] = array[j++];
            }
        }

        // Copy remaining elements from aux (left half)
        while (i <= mid) {
            array[k++] = aux[i++];
        }
    }

    public static void main(String[] args) {
        int[] array = {5, 3, 8, 4, 2};
        mergeSort(array);
        System.out.println(Arrays.toString(array));
    }
}
