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
                //System.out.println("Graph contains negative weight cycle");
                return;
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                //System.out.println("Vertex " + i + " is unreachable");
            } else {
                //System.out.println("Vertex " + i + " is reachable from source with distance " + dist[i]);
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

        // Convert adjacency matrix to edge list
        List<int[]> edgeList = new ArrayList<>();
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0) {
                    edgeList.add(new int[]{u, v, graph[u][v]});
                }
            }
        }
        int E = edgeList.size();
        int[][] edges = edgeList.toArray(new int[E][3]);

        try {
            bellmanFord(V, E, 0, edges); 
        } catch (RuntimeException e) {
        }
    }

}