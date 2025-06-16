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
        Random rand = new Random();
        int V = 1000;
        int E = V * (V - 1);
        Edge[] edges = new Edge[E];
        int index = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j) {
                    edges[index] = new Edge(i, j, rand.nextInt(100));
                    index++;
                    if (index >= E) break;
                }
            }
            if (index >= E) break;
        }
        bellmanFord(edges, V, E);
    }
}
```