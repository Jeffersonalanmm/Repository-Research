
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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
        int[][] graph = new int[numNodes][numNodes];

        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from][to] = weight;
        }

        int source = 0; // Altere se necessário
        dijkstra(graph, source);
    }

}
