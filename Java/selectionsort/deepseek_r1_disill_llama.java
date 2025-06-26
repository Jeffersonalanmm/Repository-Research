package Java.selectionsort;

public class deepseek_r1_disill_llama {
public class SelectionSortOptimized {
    public static void selectionSort(int[] array) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            boolean swapped = false;
            
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            
            if (minIndex != i) {
                // Swap the found minimum element with the first element of the unsorted portion
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
                swapped = true;
            }
            
            if (!swapped) {
                break;
            }
        }
    }
}
public class Main {
    public static void main(String[] args) {
        int[] array = {64, 25, 12, 22, 11};
        SelectionSortOptimized.selectionSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }
}
