
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

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
        String filePath = "../../graph_input.txt";
        List<int[]> edges = new ArrayList<>();
        int maxNode = 0;

        // Leitura do arquivo
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] tokens = line.trim().split("\\s+");
                if (tokens.length != 3) continue;

                int from = Integer.parseInt(tokens[0]);
                int to = Integer.parseInt(tokens[1]);
                int weight = Integer.parseInt(tokens[2]);

                edges.add(new int[]{from, to, weight});
                maxNode = Math.max(maxNode, Math.max(from, to));
            }
        } catch (IOException e) {
            return;
        }

        int numNodes = maxNode + 1;
        // Convert edges to adjacency list representation
        List<List<int[]>> adjList = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adjList.get(from).add(new int[]{to, weight});
        }

        int source = 0; // Altere se necessário
        dijkstra(adjList, source);
    }


}
