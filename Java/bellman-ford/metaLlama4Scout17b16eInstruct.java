import java.util.Random;

public class MetaLlama4Scout17b16eInstruct {
    static class Edge {
        int src, dest, weight;
    }

    static class Graph {
        int V;
        Edge[] edge;
        int E;

        public Graph(int vertices) {
            V = vertices;
            edge = new Edge[vertices * (vertices - 1)];
            E = 0;
        }

        public void addEdge(int src, int dest, int weight) {
            edge[E] = new Edge();
            edge[E].src = src;
            edge[E].dest = dest;
            edge[E].weight = weight;
            E++;
        }

        public boolean bellmanFord(int src) {
            int[] dist = new int[V];
            for (int i = 0; i < V; i++)
                dist[i] = Integer.MAX_VALUE;
            dist[src] = 0;

            for (int i = 0; i < V - 1; i++) {
                for (int j = 0; j < E; j++) {
                    int u = edge[j].src;
                    int v = edge[j].dest;
                    int w = edge[j].weight;
                    if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }
            }

            for (int i = 0; i < E; i++) {
                int u = edge[i].src;
                int v = edge[i].dest;
                int w = edge[i].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v])
                    return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int vertices = rand.nextInt(100) + 2;
        Graph graph = new Graph(vertices);
        for (int i = 0; i < vertices * 2; i++) {
            int src = rand.nextInt(vertices);
            int dest = rand.nextInt(vertices);
            int weight = rand.nextInt(100) - 50;
            graph.addEdge(src, dest, weight);
        }
        int srcVertex = rand.nextInt(vertices);
        boolean result = graph.bellmanFord(srcVertex);
    }
}