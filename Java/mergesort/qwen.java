
import java.util.ArrayList;
import java.util.List;

public class qwen {
    public static void mergeSort(int[] arr) {
        int[] temp = new int[arr.length];
        mergeSort(arr, 0, arr.length - 1, temp);
    }


    private static void mergeSort(int[] arr, int left, int right, int[] temp) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid, temp);
            mergeSort(arr, mid+1, right, temp);
            merge(arr, left, mid, right, temp);
        }
    }


    private static void merge(int[] arr, int left, int mid, int right, int[] temp) {
        // copy elements to temp, then merge back to arr
        // wait, no, better to copy the left and right halves into temp first, then merge back to arr.


        // copy the left part to temp
        for (int i = left; i <= right; i++) {
            temp[i] = arr[i];
        }


        int i = left;
        int j = mid + 1;
        int k = left;


        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                arr[k++] = temp[i++];
            } else {
                arr[k++] = temp[j++];
            }
        }


        while (i <= mid) {
            arr[k++] = temp[i++];
        }
    }


    public static void main(String[] args) {
        List<Integer> input = new ArrayList<>();

        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../inputs.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                input.add(Integer.parseInt(line.trim()));
            }
        } catch (java.io.IOException e) {
            return;
        }

        // Converte List<Integer> diretamente para int[]
        int[] arr = input.stream().mapToInt(Integer::intValue).toArray();

        // Usa o método existente
        mergeSort(arr);

        // Imprime resultado (opcional)
        for (int num : arr) {
            System.out.println(num);
        }
    }
}
