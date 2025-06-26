package Java.shellsort;

public class meta_llama_llama_4_maverick_17b_128e_instruct {

    public static void shellSort(int[] array) {
        int n = array.length;
        int gap = n / 2;

        while (gap > 0) {
            for (int i = gap; i < n; i++) {
                int temp = array[i];
                int j = i;
                while (j >= gap && array[j - gap] > temp) {
                    array[j] = array[j - gap];
                    j -= gap;
                }
                array[j] = temp;
            }
            gap /= 2;
        }
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < 1000; i++) {
            array[i] = rand.nextInt(1000);
        }
        shellSort(array);
    }
}
