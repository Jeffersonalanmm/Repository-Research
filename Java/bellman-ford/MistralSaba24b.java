import java.util.*;

public class MistralSaba24b {
    private static final int INF = Integer.MAX_VALUE;

    public static void bellmanFord(int V, int E, int src, int[][] edges) {
        int[] dist = new int[V];
        Arrays.fill(dist, INF);
        dist[src] = 0;

        for (int i = 1; i < V; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                System.out.println("Graph contains negative weight cycle");
                return;
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                System.out.println("Vertex " + i + " is unreachable");
            } else {
                System.out.println("Vertex " + i + " is reachable from source with distance " + dist[i]);
            }
        }
    }

    public static void main(String[] args) {
        int V = 1000; // Number of vertices
        int E = 2000; // Number of edges
        int src = 0; // Source vertex

        Random rand = new Random();
        int[][] edges = new int[E][3];

        for (int i = 0; i < E; i++) {
            edges[i][0] = rand.nextInt(V);
            edges[i][1] = rand.nextInt(V);
            edges[i][2] = rand.nextInt(100) - 50; // Random weights between -50 and 50
        }

        bellmanFord(V, E, src, edges);
    }
}