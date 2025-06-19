package Java.cyclesort;
import java.util.Random;

public class meta_llama_4_scout_17b_16e_instruct {
    

    public static void cycleSort(int[] array) {
        int writes = 0;
        for (int cycleStart = 0; cycleStart < array.length - 1; cycleStart++) {
            int item = array[cycleStart];
            int pos = cycleStart;
            for (int i = cycleStart + 1; i < array.length; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }
            if (pos == cycleStart) {
                continue;
            }
            while (item == array[pos]) {
                pos++;
            }
            int temp = array[pos];
            array[pos] = item;
            item = temp;
            writes++;
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < array.length; i++) {
                    if (array[i] < item) {
                        pos++;
                    }
                }
                while (item == array[pos]) {
                    pos++;
                }
                temp = array[pos];
                array[pos] = item;
                item = temp;
                writes++;
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] array = new int[1000];
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(10000);
        }
        cycleSort(array);
    }
}

