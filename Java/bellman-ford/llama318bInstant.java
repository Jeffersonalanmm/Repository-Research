import java.util.*;

public class llama318bInstant {
    private static class Edge {
        int source;
        int destination;
        int weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    public static void bellmanFord(List<Edge> edges, int source, int[] distance) {
        int V = edges.stream().mapToInt(e -> e.destination).max().getAsInt() + 1;
        distance[source] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (Edge edge : edges) {
                if (distance[edge.source] != Integer.MAX_VALUE && distance[edge.source] + edge.weight < distance[edge.destination]) {
                    distance[edge.destination] = distance[edge.source] + edge.weight;
                }
            }
        }

        for (Edge edge : edges) {
            if (distance[edge.source] != Integer.MAX_VALUE && distance[edge.source] + edge.weight < distance[edge.destination]) {
                throw new RuntimeException("Graph contains a negative-weight cycle");
            }
        }
    }

    public static void main(String[] args) {
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, -1));
        edges.add(new Edge(0, 2, 4));
        edges.add(new Edge(1, 2, 3));
        edges.add(new Edge(1, 3, 2));
        edges.add(new Edge(1, 4, 2));
        edges.add(new Edge(3, 2, 5));
        edges.add(new Edge(3, 1, 1));
        edges.add(new Edge(4, 3, -3));

        int V = edges.stream().mapToInt(e -> e.destination).max().getAsInt() + 1;
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);

        bellmanFord(edges, 0, distance);
    }
}
