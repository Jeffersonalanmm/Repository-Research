package Java.dijkstra;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class deepseek_r1_disill_llama {
      private static class Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    public static int[] shortestPath(List<List<Edge>> graph, int source, int numNodes) {
        int[] distances = new int[numNodes];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        priorityQueue.add(new int[]{source, 0});

        while (!priorityQueue.isEmpty()) {
            int[] current = priorityQueue.poll();
            int u = current[0];
            int currentDistance = current[1];

            if (currentDistance > distances[u]) {
                continue;
            }

            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                int weight = edge.weight;
                if (distances[v] > distances[u] + weight) {
                    distances[v] = distances[u] + weight;
                    priorityQueue.add(new int[]{v, distances[v]});
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        // Example usage:
        int numNodes = 5;
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            graph.add(new ArrayList<>());
        }

        graph.get(0).add(new Edge(1, 4));
        graph.get(0).add(new Edge(2, 1));
        graph.get(1).add(new Edge(3, 1));
        graph.get(2).add(new Edge(1, 5));
        graph.get(2).add(new Edge(3, 8));
        graph.get(2).add(new Edge(4, 2));
        graph.get(3).add(new Edge(4, 10));

        int source = 0;
        int[] distances = shortestPath(graph, source, numNodes);

        for (int i = 0; i < numNodes; i++) {
            System.out.println("Shortest distance from " + source + " to " + i + ": " + distances[i]);
        }
    }
}
