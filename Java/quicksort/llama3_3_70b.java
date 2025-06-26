package Java.quicksort;
import java.util.Random;

public class llama3_3_70b {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void testQuickSort() {
        Random random = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = random.nextInt(1000);
        }
        quickSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        testQuickSort();
    }
}
