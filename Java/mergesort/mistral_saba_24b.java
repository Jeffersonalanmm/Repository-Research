package Java.mergesort;
import java.util.Arrays;
public class mistral_saba_24b {

    public static void mergeSort(int[] array) {
        if (array == null || array.length < 2) {
            return;
        }
        int[] tempArray = new int[array.length];
        mergeSort(array, tempArray, 0, array.length - 1);
    }

    private static void mergeSort(int[] array, int[] tempArray, int leftStart, int rightEnd) {
        if (leftStart >= rightEnd) {
            return;
        }
        int middle = (leftStart + rightEnd) / 2;
        mergeSort(array, tempArray, leftStart, middle);
        mergeSort(array, tempArray, middle + 1, rightEnd);
        mergeHalves(array, tempArray, leftStart, rightEnd);
    }

    private static void mergeHalves(int[] array, int[] tempArray, int leftStart, int rightEnd) {
        int leftEnd = (rightEnd + leftStart) / 2;
        int rightStart = leftEnd + 1;
        int size = rightEnd - leftStart + 1;

        int left = leftStart;
        int right = rightStart;
        int index = leftStart;

        while (left <= leftEnd && right <= rightEnd) {
            if (array[left] <= array[right]) {
                tempArray[index] = array[left];
                left++;
            } else {
                tempArray[index] = array[right];
                right++;
            }
            index++;
        }

        System.arraycopy(array, left, tempArray, index, leftEnd - left + 1);
        System.arraycopy(array, right, tempArray, index, rightEnd - right + 1);

        System.arraycopy(tempArray, leftStart, array, leftStart, size);
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = (int) (Math.random() * 10000);
        }
        mergeSort(array);
        // The sorted array is now stored in the 'array' variable.
    }

}
