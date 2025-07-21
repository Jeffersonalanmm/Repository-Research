
import java.util.*;

public class DeepSeekR1DistillLlama {
    static class Edge {
        int src, dest, weight;
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    public static void bellmanFord(List<List<Edge>> graph, int V, int source, int[] dist) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] inQueue = new boolean[V];
        
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;
        queue.add(source);
        inQueue[source] = true;

        boolean relaxed;
        do {
            relaxed = false;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int u = queue.poll();
                inQueue[u] = false;

                for (Edge edge : graph.get(u)) {
                    int v = edge.dest;
                    if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + edge.weight) {
                        dist[v] = dist[u] + edge.weight;
                        if (!inQueue[v]) {
                            queue.add(v);
                            inQueue[v] = true;
                        }
                        relaxed = true;
                    }
                }
            }
        } while (relaxed);

        relaxed = false;
        for (List<Edge> edges : graph) {
            for (Edge edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + edge.weight) {
                    dist[v] = dist[u] + edge.weight;
                    relaxed = true;
                }
            }
        }
        if (relaxed) {
            throw new RuntimeException("Graph contains negative weight cycle");
        }
    }

    public static void main(String[] args) {
        final int V = 1000; // Número total de vértices
        List<List<Edge>> graph = new ArrayList<>(V);

        // Inicializa a lista de adjacência
        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }

        // Lê as arestas do arquivo
        try (java.io.BufferedReader br = new java.io.BufferedReader(new java.io.FileReader("../../graph_input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\s+");
                if (parts.length != 3) continue;

                int src = Integer.parseInt(parts[0]);
                int dest = Integer.parseInt(parts[1]);
                int weight = Integer.parseInt(parts[2]);

                graph.get(src).add(new Edge(src, dest, weight));
            }
        } catch (java.io.IOException e) {
            return;
        }

        int[] dist = new int[V];
        try {
            bellmanFord(graph, V, 0, dist);
        } catch (RuntimeException e) {
            return;
        }
    }

}
