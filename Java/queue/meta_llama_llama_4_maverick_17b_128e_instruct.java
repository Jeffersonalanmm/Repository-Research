package Java.queue;
    import java.util.Random;
public class meta_llama_llama_4_maverick_17b_128e_instruct {
    public class Main {
        static class Queue {
            private int[] queue;
            private int front;
            private int rear;
            private int size;

            public Queue(int capacity) {
                queue = new int[capacity];
                front = 0;
                rear = 0;
                size = 0;
            }

            // Add an element
            public void enqueue(int item) {
                if (size == queue.length) {
                    // Handle queue overflow
                    return;
                }
                queue[rear] = item;
                rear = (rear + 1) % queue.length;
                size++;
            }

            // Remove an element
            public int dequeue() {
                if (size == 0) {
                    // Handle queue underflow
                    return -1;
                }
                int item = queue[front];
                front = (front + 1) % queue.length;
                size--;
                return item;
            }

            // Get the front element
            public int peek() {
                if (size == 0) {
                    // Handle queue underflow
                    return -1;
                }
                return queue[front];
            }

            // Check if the queue is empty
            public boolean isEmpty() {
                return size == 0;
            }

            // Check if the queue is full
            public boolean isFull() {
                return size == queue.length;
            }
        }

        public static void main(String[] args) {
            Queue queue = new Queue(1000);
            Random random = new Random();

            for (int i = 0; i < 1000; i++) {
                int num = random.nextInt(1000);
                queue.enqueue(num);
            }

            for (int i = 0; i < 1000; i++) {
                queue.dequeue();
            }
        }
    }
}
