

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class qwen {


    public static int[] dijkstra(int[][][] adjList, int start, int n) {
        // n is the number of nodes
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
       
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[0]));
        pq.add(new int[]{0, start});
       
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int distance = current[0];
            int u = current[1];
           
            if (distance > dist[u]) {
                continue; // this is an old entry, skip
            }
           
            for (int[] edge : adjList[u]) {
                int v = edge[0];
                int weight = edge[1];
                int newDist = dist[u] + weight;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.add(new int[]{dist[v], v});
                }
            }
        }
        return dist;
    }

        public static void main(String[] args) {
        String filePath = "../../graph_input.txt";
        List<int[]> edges = new ArrayList<>();
        int maxNode = 0;

        // Leitura do arquivo
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] tokens = line.trim().split("\\s+");
                if (tokens.length != 3) continue;

                int from = Integer.parseInt(tokens[0]);
                int to = Integer.parseInt(tokens[1]);
                int weight = Integer.parseInt(tokens[2]);

                edges.add(new int[]{from, to, weight});
                maxNode = Math.max(maxNode, Math.max(from, to));
            }
        } catch (IOException e) {
            return;
        }

        int numNodes = maxNode + 1;
        int[][][] adjList = new int[numNodes][][];
        List<List<int[]>> tempList = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            tempList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            tempList.get(from).add(new int[]{to, weight});
        }
        for (int i = 0; i < numNodes; i++) {
            adjList[i] = tempList.get(i).toArray(new int[0][]);
        }

        int source = 0; // Altere se necessário
        dijkstra(adjList, source, numNodes);
    }

}

