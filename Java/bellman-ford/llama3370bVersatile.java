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
                throw new RuntimeException("Graph contains negative weight cycle");
            }
        }
    }
}

public class llama3370bVersatile {
    public static void main(String[] args) {
        Random random = new Random();
        for (int i = 0; i < 1000; i++) {
            int vertices = random.nextInt(10) + 1;
            int edges = random.nextInt(20) + 1;
            Graph graph = new Graph(vertices, edges);
            for (int j = 0; j < edges; j++) {
                int src = random.nextInt(vertices);
                int dest = random.nextInt(vertices);
                int weight = random.nextInt(10) - 5;
                graph.addEdge(src, dest, weight, j);
            }
            try {
                graph.bellmanFord(0);
            } catch (RuntimeException e) {
                // Handle negative weight cycle
            }
        }
    }
}