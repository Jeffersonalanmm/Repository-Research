import java.util.Arrays;
import java.util.List;


public class qwen {
    static class Edge {
        int from, to, weight;
        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }


    public static int[] bellmanFord(List<Edge> edges, int V, int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;


        for (int i = 0; i < V - 1; i++) {
            boolean updated = false;
            for (Edge e : edges) {
                int u = e.from;
                int v = e.to;
                int w = e.weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) break;
        }


        for (Edge e : edges) {
            int u = e.from;
            int v = e.to;
            int w = e.weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                //throw new RuntimeException("Negative cycle");
            }
        }
        return dist;
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
        List<Edge> edges = new java.util.ArrayList<>();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != 0) {
                    edges.add(new Edge(i, j, graph[i][j]));
                }
            }
        }

        try {
            int[] dist = bellmanFord(edges, V, 0);
            // Optionally print distances
            // for (int i = 0; i < dist.length; i++) {
            //     System.out.println("Distance from 0 to " + i + ": " + dist[i]);
            // }
        } catch (RuntimeException e) {
        }
    }
}