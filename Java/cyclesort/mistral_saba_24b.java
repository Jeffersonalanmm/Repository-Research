package Java.cyclesort;

import java.util.Arrays;

public class mistral_saba_24b {
    public static void cycleSort(int[] array) {
        int n = array.length;
        for (int cycleStart = 0; cycleStart <= n - 1; cycleStart++) {
            int item = array[cycleStart];
            int pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }
            while (item == array[pos]) {
                pos += 1;
            }
            if (pos != cycleStart) {
                int temp = item;
                item = array[pos];
                array[pos] = temp;
            }
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < n; i++) {
                    if (array[i] < item) {
                        pos += 1;
                    }
                }
                while (item == array[pos]) {
                    pos += 1;
                }
                if (item != array[pos]) {
                    int temp = item;
                    item = array[pos];
                    array[pos] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = (int) (Math.random() * 10000);
        }
        cycleSort(array);
        System.out.println(Arrays.toString(array));
    }
}
