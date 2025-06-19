package Java.dijkstra;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class gemma2_9b_it {
     public static void dijkstra(int[][] graph, int source) {
        int numVertices = graph.length;
        int[] distances = new int[numVertices];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(n -> n.distance));
        priorityQueue.offer(new Node(source, 0));

        while (!priorityQueue.isEmpty()) {
            Node current = priorityQueue.poll();
            int u = current.vertex;

            for (int v = 0; v < numVertices; v++) {
                if (graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                    priorityQueue.offer(new Node(v, distances[v]));
                }
            }
        }
    }

    static class Node {
        int vertex;
        int distance;

        Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }

    public static void main(String[] args) {
        // Example usage:
        int[][] graph = {
                {0, 4, 0, 0, 0, 0, 0, 8, 0},
                {4, 0, 8, 0, 0, 0, 0, 11, 0},
                {0, 8, 0, 7, 0, 4, 0, 0, 2},
                {0, 0, 7, 0, 9, 14, 0, 0, 0},
                {0, 0, 0, 9, 0, 10, 0, 0, 0},
                {0, 0, 4, 14, 10, 0, 2, 0, 0},
                {0, 0, 0, 0, 0, 2, 0, 1, 6},
                {8, 11, 0, 0, 0, 0, 1, 0, 7},
                {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        int source = 0;
        dijkstra(graph, source);
    }
}
