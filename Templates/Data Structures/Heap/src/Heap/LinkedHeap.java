package Heap;

import LinkedList.LinkedList;

public class LinkedHeap {

    private LinkedList heap;
    private int size = 0;

    public LinkedHeap() {
        heap = new LinkedList();
    }

    public int getSize() {
        return size;
    }

    public LinkedList getHeap() {
        return heap;
    }

    public void insert(int value) {
        size++;
        heap.insertBack(0);
        increase(size, value);
    }

    public void increase(int index, int value) {
        if (heap.getValue(index) > value) {
            return;
        }

        heap.setValue(index, value);

        while(index > 1 && heap.getValue(index) > heap.getValue(parent(index))) {
            int temp = heap.getValue(index);
            heap.setValue(index, heap.getValue(parent(index)));
            heap.setValue(parent(index), temp);
            index = parent(index);
        }
    }

    public int extract() {
        if (size == 0) {
            return -1;
        }

        int max = heap.getValue(1);

        heap.setValue(1, heap.getValue(size));
        heap.delete(size);
        size--;


        heapify(1);

        return max;
    }

    public int top() {
        return heap.getValue(1);
    }

    public LinkedList sorted() {
        LinkedList sorted = new LinkedList();
        int count = size;

        for (int i = 0; i < count; i++) {
            sorted.insertFront(heap.getValue(1));

            heap.setValue(1, heap.getValue(size));
            size--;

            heapify(1);
        }

        return sorted;
    }

    private void heapify(int i) { // n log n -> change for min heap
        int largest = 0, r = right(i), l = left(i);

        if (l <= size && heap.getValue(l) > heap.getValue(i)) {
            largest = l;
        } else largest = i;

        if (r <= size && heap.getValue(r) > heap.getValue(largest)) {
            largest = r;
        }

        if (largest != i) {
            int temp = heap.getValue(i);
            heap.setValue(i, heap.getValue(largest));
            heap.setValue(largest, temp);
            heapify(largest);
        }
    }

    private int right(int i) {
        return (i << 1) + 1;
    }

    private int left(int i) {
        return (i << 1);
    }

    private int parent(int i) {
        return i >> 1;
    }
}
