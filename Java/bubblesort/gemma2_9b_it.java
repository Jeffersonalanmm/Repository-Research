
public class gemma2_9b_it {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[1000];
        // Generate 1000 random numbers
        for (int i = 0; i < 1000; i++) {
            arr[i] = (int) (Math.random() * 1000);
        }
        bubbleSort(arr);
    }
}
