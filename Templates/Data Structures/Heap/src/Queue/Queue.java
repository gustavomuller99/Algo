package Queue;

import LinkedList.LinkedList;

public class Queue {

    LinkedList queue;

    public Queue() {
        queue = new LinkedList();
    }

    public void enqueue(int value) {
        queue.insertBack(value);
    }

    public int dequeue() {
        int val = queue.getValue(1);
        queue.deleteFront();
        return val;
    }

    public int peek() {
        return queue.getValue(1);
    }

    public boolean isEmpty() {
        return queue.get(1) == null;
    }
}
