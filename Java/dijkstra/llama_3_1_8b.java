package Java.dijkstra;
import java.util.*;

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

        System.out.println(Arrays.toString(distances));
    }

    public static void main(String[] args) {
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

        dijkstra(graph, 0);
    }
}
