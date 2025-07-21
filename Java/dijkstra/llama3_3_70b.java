
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
    

class Node implements Comparable<Node> {
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

public class llama3_3_70b {
    private static final int INF = Integer.MAX_VALUE;

    public static int[] dijkstra(int[][] graph, int start) {
        int numNodes = graph.length;
        int[] distances = new int[numNodes];
        boolean[] visited = new boolean[numNodes];

        Arrays.fill(distances, INF);
        distances[start] = 0;

        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
        priorityQueue.offer(new Node(start, 0));

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();
            int currentNodeId = currentNode.id;

            if (visited[currentNodeId]) {
                continue;
            }

            visited[currentNodeId] = true;

            for (int neighbor = 0; neighbor < numNodes; neighbor++) {
                int weight = graph[currentNodeId][neighbor];

                if (weight > 0 && !visited[neighbor]) {
                    int newDistance = distances[currentNodeId] + weight;

                    if (newDistance < distances[neighbor]) {
                        distances[neighbor] = newDistance;
                        priorityQueue.offer(new Node(neighbor, newDistance));
                    }
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
        int[][] graph = new int[numNodes][numNodes];

        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from][to] = weight;
        }

        int source = 0; // Altere se necessário
        dijkstra(graph, source);
    }

}



