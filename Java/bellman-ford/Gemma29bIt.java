
import java.util.Arrays;

public class Gemma29bIt {

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
        // Example usage:
        int[][] graph = {
                {0, -1, 4, 0, 0},
                {0, 0, 0, 3, 0},
                {0, 0, 0, 0, 2},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
        };
        int source = 0;
        bellmanFord(graph, source);
    }
}
