package Java.dijkstra;
import java.util.*;
    

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
        // Generate 1000 random inputs
        Random random = new Random();
        int numNodes = 1000;
        int[][] graph = new int[numNodes][numNodes];

        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (i == j) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = random.nextInt(2) == 0 ? random.nextInt(10) + 1 : 0;
                }
            }
        }

        // Run Dijkstra's algorithm
        int startNode = random.nextInt(numNodes);
        int[] distances = dijkstra(graph, startNode);
    }
}



