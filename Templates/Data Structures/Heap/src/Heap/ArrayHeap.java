package Heap;

public class ArrayHeap {

    private int[] heap;
    private int size = -1;

    public ArrayHeap(int size) {
        heap = new int[size];
    }

    public int getSize() {
        return size + 1;
    }

    public int[] getHeap() {
        return heap;
    }

    public void insert(int value) {
        size++;
        heap[size] = -1;
        increase(size, value);
    }

    public void increase(int index, int value) { // change for min heap
        if (heap[index] > value) {
            return;
        }

        heap[index] = value;

        while (index > 0 && heap[index] > heap[parent(index)]) {
            int temp = heap[index];
            heap[index] = heap[parent(index)];
            heap[parent(index)] = temp;
            index = parent(index);
        }
    }

    public int extract() { // log n
        if (size == -1) {
            return -1;
        }

        int max = heap[0];

        heap[0] = heap[size];
        size--;

        heapify(0);
        return max;
    }

    public int top() {
        return heap[0];
    }

    public int[] sorted() { // n log n
        int[] sorted = new int[size + 1];
        int count = size;

        for (int i = 0; i <= count; i++) {
            sorted[size] = heap[0];

            heap[0] = heap[size];
            size--;

            heapify(0);
        }

        return sorted;
    }

    private void heapify(int i) { // log n -> change for min heap
        int largest = 0, r = right(i), l = left(i);

        if (l <= size && heap[l] > heap[i]) {
            largest = l;
        } else largest = i;

        if (r <= size && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapify(largest);
        }
    }

    private int right(int i) {
        return (i << 1) + 2;
    }

    private int left(int i) {
        return (i << 1) + 1;
    }

    private int parent(int i) {
        return (i >> 1) - (i % 2 == 0 ? 1 : 0);
    }
}
