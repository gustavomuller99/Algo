import Heap.ArrayHeap;

import java.util.Arrays;

public class TestArrayHeap {

    @org.junit.Test
    public void testInsert() {
        ArrayHeap heap = new ArrayHeap(100);
        heap.insert(10);
        heap.insert(20);
        heap.insert(30);

        assert heap.getSize() == 3;
        assert heap.getHeap()[0] == 30;
        assert heap.getHeap()[1] == 10;
        assert heap.getHeap()[2] == 20;
    }

    @org.junit.Test
    public void testArrayHeap() {
        ArrayHeap heap = new ArrayHeap(100);

        heap.insert(10);
        heap.insert(20);
        heap.insert(30);
        heap.insert(40);
        heap.insert(5);
        heap.insert(7);
        heap.insert(8);
        heap.insert(9);
        heap.insert(90);

        var sorted = heap.sorted();
        Arrays.stream(sorted).forEach(System.out::println);
        assert Arrays.equals(sorted, new int[]{5, 7, 8, 9, 10, 20, 30, 40, 90});
    }

    @org.junit.Test
    public void testExtract() {
        ArrayHeap heap = new ArrayHeap(100);
        heap.insert(10);
        heap.insert(20);
        heap.insert(30);
        heap.insert(40);
        heap.insert(5);
        heap.insert(7);

        int top = heap.extract();
        assert top == 40;

        top = heap.extract();
        assert top == 30;

        var sorted = heap.sorted();
        assert Arrays.equals(sorted, new int[]{5, 7, 10, 20});
    }
}
