
public class llama318bInstant {

    public static int[] beadSort(int[] arr) {
        // Initialize the bead array with zeros
        int[] beads = new int[10];

        // Count the frequency of each number in the input array
        for (int num : arr) {
            if (num < 0 || num > 9) {
                throw new IllegalArgumentException("Input array should only contain numbers between 0 and 9");
            }
            beads[num]++;
        }

        // Create the sorted array
        int[] sortedArr = new int[arr.length];
        int index = 0;
        for (int i = 0; i < beads.length; i++) {
            for (int j = 0; j < beads[i]; j++) {
                sortedArr[index++] = i;
            }
        }

        return sortedArr;
    }

    public static void main(String[] args) {
        // Test the beadSort function with 1000 random inputs
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = (int) (Math.random() * 10);
        }
        int[] sortedArr = beadSort(arr);
    }
}
