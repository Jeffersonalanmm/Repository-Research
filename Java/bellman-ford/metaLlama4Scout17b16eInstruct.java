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
        final int V = 1000; // Número de vértices
        Graph g = new Graph(V);

        // Lê as arestas do arquivo
        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../graph_input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length != 3) continue;

                int src = Integer.parseInt(parts[0]);
                int dest = Integer.parseInt(parts[1]);
                int weight = Integer.parseInt(parts[2]);

                g.addEdge(src, dest, weight);
            }
        } catch (java.io.IOException e) {
            return;
        }

        boolean hasNoNegativeCycle = g.bellmanFord(0);
    }

}