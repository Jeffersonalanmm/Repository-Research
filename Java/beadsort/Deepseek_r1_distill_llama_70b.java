import java.util.ArrayList;
import java.util.List;

public class Deepseek_r1_distill_llama_70b {

    public static List<Integer> beadSort(List<Integer> inputList) {
        if (inputList.isEmpty()) {
            return new ArrayList<>();
        }

        int[] arr = new int[inputList.size()];
        for (int i = 0; i < inputList.size(); i++) {
            arr[i] = inputList.get(i);
        }

        int max = arr[0];
        for (int i : arr) {
            if (i > max) {
                max = i;
            }
        }

        int[] beads = new int[max + 1];
        for (int i : arr) {
            beads[i]++;
        }

        int[] result = new int[arr.length];
        int pointer = 0;

        for (int i = 0; i <= max; i++) {
            while (beads[i] > 0) {
                result[pointer] = i;
                pointer++;
                beads[i]--;
            }
        }

        List<Integer> sortedList = new ArrayList<>();
        for (int num : result) {
            sortedList.add(num);
        }

        return sortedList;
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

        List<Integer> sorted = beadSort(input);
    }

}
