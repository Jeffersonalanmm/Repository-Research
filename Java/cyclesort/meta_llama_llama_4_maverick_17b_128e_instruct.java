package Java.cyclesort;

import java.util.Random;

public class meta_llama_llama_4_maverick_17b_128e_instruct {
    public static void cycleSort(int[] arr) {
        int writes = 0;

        for (int cycleStart = 0; cycleStart < arr.length - 1; cycleStart++) {
            int item = arr[cycleStart];

            int pos = cycleStart;
            for (int i = cycleStart + 1; i < arr.length; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            if (pos == cycleStart) {
                continue;
            }

            while (item == arr[pos]) {
                pos++;
            }

            int temp = arr[pos];
            arr[pos] = item;
            item = temp;
            writes++;

            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < arr.length; i++) {
                    if (arr[i] < item) {
                        pos++;
                    }
                }

                while (item == arr[pos]) {
                    pos++;
                }

                temp = arr[pos];
                arr[pos] = item;
                item = temp;
                writes++;
            }
        }
    }

    public static void main(String[] args) {
        int n = 1000;
        int[] arr = new int[n];
        Random rand = new java.util.Random();

        for (int i = 0; i < n; i++) {
            arr[i] = rand.nextInt(10000);
        }

        cycleSort(arr);
    }
}
