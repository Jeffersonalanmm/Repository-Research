

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class deepseek_r1_disill_llama {
      private static class Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    public static int[] shortestPath(List<List<Edge>> graph, int source, int numNodes) {
        int[] distances = new int[numNodes];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        priorityQueue.add(new int[]{source, 0});

        while (!priorityQueue.isEmpty()) {
            int[] current = priorityQueue.poll();
            int u = current[0];
            int currentDistance = current[1];

            if (currentDistance > distances[u]) {
                continue;
            }

            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                int weight = edge.weight;
                if (distances[v] > distances[u] + weight) {
                    distances[v] = distances[u] + weight;
                    priorityQueue.add(new int[]{v, distances[v]});
                }
            }
        }

        return distances;
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
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph.get(from).add(new Edge(to, weight));
        }

        int source = 0; // Pode mudar conforme necessário
        int[] distances = shortestPath(graph, source, numNodes);

    }

}
