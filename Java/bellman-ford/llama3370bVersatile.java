import java.util.*;

class Edge {
    int src, dest, weight;

    Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

class Graph {
    int V, E;
    Edge[] edges;

    Graph(int vertices, int edges) {
        this.V = vertices;
        this.E = edges;
        this.edges = new Edge[edges];
    }

    void addEdge(int src, int dest, int weight, int index) {
        this.edges[index] = new Edge(src, dest, weight);
    }

    void bellmanFord(int src) {
        int[] dist = new int[V];
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (int i = 0; i < E; i++) {
            int u = edges[i].src;
            int v = edges[i].dest;
            int weight = edges[i].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                //throw new RuntimeException("Graph contains negative weight cycle");
            }
        }
    }
}

public class llama3370bVersatile {
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
            // Count edges
            int edgeCount = 0;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (graph[i][j] != 0) edgeCount++;
                }
            }

            Graph g = new Graph(V, edgeCount);
            int idx = 0;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (graph[i][j] != 0) {
                        g.addEdge(i, j, graph[i][j], idx++);
                    }
                }
            }

            g.bellmanFord(0); // Usa o vértice 0 como origem
        } catch (RuntimeException e) {
            System.err.println(e.getMessage());
        }
    }

}