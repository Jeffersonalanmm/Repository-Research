package Java.dijkstra;
import java.util.*;

public class meta_llama_llama_4_maverick_17b_128e_instruct {
 
    static class Node implements Comparable<Node> {
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

    public static int[] dijkstra(List<List<int[]>> graph, int start) {
        int n = graph.size();
        int[] distances = new int[n];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int nodeId = node.id;
            int distance = node.distance;

            if (distance > distances[nodeId]) {
                continue;
            }

            for (int[] neighbor : graph.get(nodeId)) {
                int neighborId = neighbor[0];
                int weight = neighbor[1];
                int newDistance = distance + weight;

                if (newDistance < distances[neighborId]) {
                    distances[neighborId] = newDistance;
                    pq.offer(new Node(neighborId, newDistance));
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int n = 1000;
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && rand.nextDouble() < 0.1) {
                    int weight = rand.nextInt(100);
                    graph.get(i).add(new int[]{j, weight});
                }
            }
        }
        int start = rand.nextInt(n);
        int[] distances = dijkstra(graph, start);
        // Use the distances array as needed
    }

}
