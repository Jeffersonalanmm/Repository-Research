package Java.quicksort;
import java.util.Random;
public class gemma2 {

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        Random random = new Random();
        int pivotIndex = low + random.nextInt(high - low + 1);
        swap(arr, pivotIndex, high);
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = random.nextInt(10000);
        }
        quickSort(arr, 0, arr.length - 1);
    }

}
