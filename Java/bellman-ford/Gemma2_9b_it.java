
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Gemma2_9b_it {

    public static void bellmanFord(int[][] graph, int source) {
        int V = graph.length;
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                    throw new RuntimeException("Graph contains negative-weight cycles");
                }
            }
        }
    }

    public static void main(String[] args) {
        final int V = 1000; // Número de vértices
        int[][] graph = new int[V][V]; // Matriz de adjacência

        // Lê as arestas do arquivo
        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../graph_input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length != 3) continue;

                int src = Integer.parseInt(parts[0]);
                int dest = Integer.parseInt(parts[1]);
                int weight = Integer.parseInt(parts[2]);

                graph[src][dest] = weight;
            }
        } catch (java.io.IOException e) {
            return;
        }

        try {
            bellmanFord(graph, 0); 
        } catch (RuntimeException e) {
        }
    }


}
