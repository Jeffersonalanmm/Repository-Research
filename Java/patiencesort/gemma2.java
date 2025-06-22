package Java.patiencesort;
import java.util.Arrays;
public class gemma2 {

    public static void patienceSort(int[] arr) {
        int[] temp = new int[arr.length];
        int index = 0;
        for (int i = 0; i < arr.length; i++) {
            while (index > 0 && arr[i] < temp[index - 1]) {
                index--;
            }
            if (index < arr.length) {
                temp[index++] = arr[i];
            }
        }
        System.arraycopy(temp, 0, arr, 0, arr.length);
    }

    public static void main(String[] args) {
        int[] arr = new int[1000];
        for (int i = 0; i < 1000; i++) {
            arr[i] = (int) (Math.random() * 1000);
        }
        patienceSort(arr);
        System.out.println(Arrays.toString(arr));
    }



}
