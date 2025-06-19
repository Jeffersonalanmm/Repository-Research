package Java.dijkstra;
import java.util.*;
public class mistral_saba_24b {
    

    private static final int INF = Integer.MAX_VALUE;

    public static void dijkstra(int[][] graph, int src) {
        int n = graph.length;
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];

        Arrays.fill(dist, INF);
        dist[src] = 0;

        for (int count = 0; count < n - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        // Print the constructed distance array
        // for (int i = 0; i < n; i++) {
        //     System.out.println("Vertex " + i + " is at distance of " + dist[i] + " from Source");
        // }
    }

    private static int minDistance(int[] dist, boolean[] visited) {
        int min = INF;
        int minIndex = -1;

        for (int v = 0; v < dist.length; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    public static void main(String[] args) {
        int[][] graph = new int[1000][1000];
        Random rand = new Random();

        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                graph[i][j] = rand.nextInt(100);
            }
        }

        dijkstra(graph, 0);
    }
}
