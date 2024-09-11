import java.util.*;

class Queue {
    private static final int Max = 15;
    private int front = -1;
    private int rear = -1;
    private int[] arr = new int[Max];

    // Check if the queue is empty
    public boolean isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    public boolean isFull() {
        return rear == Max - 1;
    }

    // Enqueue an element to the queue
    public void enqueue(int val) {
        if (isEmpty()) {
            front = 0;
        }
        if (isFull()) {
            System.out.println("The queue is full. Cannot enqueue.");
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    // Dequeue an element from the queue
    public void dequeue() {
        if (isEmpty()) {
            System.out.println("The queue is empty. Cannot dequeue.");
            return;
        }
        System.out.println("The dequeued element is: " + arr[front]);
        if (rear == front) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    // Display the elements of the queue
    public void display() {
        System.out.print("Max number of sliding windows: ");
        if (isEmpty()) {
            System.out.println("EMPTY QUEUE");
            return;
        } else {
            for (int i = front; i != rear; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println(arr[rear]);
        }
    }
}

public class SlidingWindow {
    public static void slidingWindow(int[] arr, int size) {
        Queue Q = new Queue();
        int k = 3;
        int m = arr[0];

        // Find the maximum of the first sliding window
        for (int i = 0; i < k; i++) {
            if (arr[i] > m) {
                m = arr[i];
            }
        }
        Q.enqueue(m);

        // Process the remaining elements
        for (int i = 3; i < size; i++) {
            if (arr[i] >= m) {
                m = arr[i];
                Q.enqueue(m);
            } else {
                Q.enqueue(m);
            }
        }
        Q.display();
    }

    // Main method
    public static void main(String[] args) {
        int[] arr = {1, 2, 5, 4, -2, -1, 7, 8, 9, 10};
        slidingWindow(arr, arr.length);
    }
}
