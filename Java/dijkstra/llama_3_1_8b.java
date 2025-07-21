
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class PriorityQueueNode implements Comparable<PriorityQueueNode> {
    int vertex;
    int distance;

    public PriorityQueueNode(int vertex, int distance) {
        this.vertex = vertex;
        this.distance = distance;
    }

    @Override
    public int compareTo(PriorityQueueNode other) {
        return Integer.compare(this.distance, other.distance);
    }
}

public class llama_3_1_8b {
    private static final int INF = Integer.MAX_VALUE;

    public static void dijkstra(int[][] graph, int startVertex) {
        int numVertices = graph.length;
        int[] distances = new int[numVertices];
        boolean[] visited = new boolean[numVertices];

        Arrays.fill(distances, INF);
        distances[startVertex] = 0;

        PriorityQueue<PriorityQueueNode> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new PriorityQueueNode(startVertex, 0));

        while (!priorityQueue.isEmpty()) {
            PriorityQueueNode currentNode = priorityQueue.poll();
            int vertex = currentNode.vertex;
            int distance = currentNode.distance;

            if (visited[vertex]) {
                continue;
            }

            visited[vertex] = true;

            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                if (graph[vertex][neighbor] != 0 && !visited[neighbor]) {
                    int newDistance = distance + graph[vertex][neighbor];
                    if (newDistance < distances[neighbor]) {
                        distances[neighbor] = newDistance;
                        priorityQueue.add(new PriorityQueueNode(neighbor, newDistance));
                    }
                }
            }
        }

        //System.out.println(Arrays.toString(distances));
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
