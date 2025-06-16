
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
        final int V = 1000;
        final int E = 10000;
        List<List<Edge>> graph = new ArrayList<>(V);
        Random rand = new Random(12345L);

        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            int src = rand.nextInt(V);
            int dest = rand.nextInt(V);
            int weight = rand.nextInt(10000) - 5000; // Random weight between -5000 and 4999
            graph.get(src).add(new Edge(src, dest, weight));
        }

        int[] dist = new int[V];
        try {
            bellmanFord(graph, V, 0, dist);
        } catch (RuntimeException e) {
            System.err.println(e.getMessage());
        }
    }
}
