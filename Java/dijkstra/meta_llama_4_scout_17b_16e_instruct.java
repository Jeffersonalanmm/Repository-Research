package Java.dijkstra;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;

public class meta_llama_4_scout_17b_16e_instruct {
     private static class Node implements Comparable<Node> {
        int id;
        int distance;

        public Node(int id, int distance) {
            this.id = id;
            this.distance = distance;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    public static int[] dijkstra(int[][] graph, int source) {
        int n = graph.length;
        int[] distances = new int[n];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(source, 0));

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int u = node.id;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] > 0 && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                    pq.offer(new Node(v, distances[v]));
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int n = 1000;
        int[][] graph = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    graph[i][j] = 0;
                } else if (rand.nextDouble() < 0.1) {
                    graph[i][j] = rand.nextInt(100) + 1;
                    graph[j][i] = graph[i][j];
                } else {
                    graph[i][j] = 0;
                }
            }
        }

        int source = rand.nextInt(n);
        int[] distances = dijkstra(graph, source);
    }
}
