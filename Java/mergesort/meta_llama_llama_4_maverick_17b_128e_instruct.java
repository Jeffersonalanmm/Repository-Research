package Java.mergesort;

public class meta_llama_llama_4_maverick_17b_128e_instruct {

    public static void mergeSort(int[] arr) {
        mergeSort(arr, 0, arr.length - 1);
    }

    private static void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    private static void merge(int[] arr, int low, int mid, int high) {
        int[] left = new int[mid - low + 1];
        int[] right = new int[high - mid];

        System.arraycopy(arr, low, left, 0, mid - low + 1);
        System.arraycopy(arr, mid + 1, right, 0, high - mid);

        int i = 0, j = 0, k = low;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.length) {
            arr[k++] = left[i++];
        }

        while (j < right.length) {
            arr[k++] = right[j++];
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[1000];
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand.nextInt(1000);
        }
        mergeSort(arr);
    }
}
