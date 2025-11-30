import Heap.LinkedHeap;

public class TestLinkedHeap {
    @org.junit.Test
    public void testInsert() {
        LinkedHeap heap = new LinkedHeap();
        heap.insert(10);
        heap.insert(20);
        heap.insert(30);

        assert heap.getSize() == 3;
        assert heap.getHeap().getValue(1) == 30;
        assert heap.getHeap().getValue(2) == 10;
        assert heap.getHeap().getValue(3) == 20;
    }

    @org.junit.Test
    public void testArrayHeap() {
        LinkedHeap heap = new LinkedHeap();

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
        assert sorted.inOrder().equals("5 7 8 9 10 20 30 40 90 ");
    }

    @org.junit.Test
    public void testExtract() {
        LinkedHeap heap = new LinkedHeap();
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

        heap.insert(90);
        heap.insert(3);

        top = heap.extract();
        assert top == 90;

        top = heap.extract();
        assert top == 20;

        heap.insert(40);
        heap.insert(5);

        var sorted = heap.sorted();
        assert sorted.inOrder().equals("3 5 5 7 10 40 ");
    }
}
