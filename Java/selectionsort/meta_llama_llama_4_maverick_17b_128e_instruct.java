package Java.selectionsort;

public class meta_llama_llama_4_maverick_17b_128e_instruct {

    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        // Generate 1000 random integers and store them in an array
        int[] arr = new int[1000];
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(10000);
        }

        // Perform selection sort
        long startTime = System.nanoTime();
        selectionSort(arr);
        long endTime = System.nanoTime();

        // You can verify the correctness of the sort by checking if the array is sorted
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                throw new AssertionError("Array is not sorted");
            }
        }
    }

}
