import java.util.Random;

public class MetaLlamaLlama4Maverick17b128eInstruct {
    static class Edge {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static void bellmanFord(Edge[] edges, int V, int E) {
        int[] dist = new int[V];
        for (int i = 0; i < V; i++)
            dist[i] = Integer.MAX_VALUE;
        dist[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i < E; i++) {
            int u = edges[i].src;
            int v = edges[i].dest;
            int weight = edges[i].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                // Graph contains negative weight cycle
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

        // Convert adjacency matrix to Edge array
        java.util.List<Edge> edgeList = new java.util.ArrayList<>();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != 0) {
                    edgeList.add(new Edge(i, j, graph[i][j]));
                }
            }
        }
        Edge[] edges = edgeList.toArray(new Edge[0]);
        int E = edges.length;

        try {
            bellmanFord(edges, V, E);
        } catch (RuntimeException e) {
        }
    }

}
