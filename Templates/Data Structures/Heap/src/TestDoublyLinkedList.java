import LinkedList.DoublyLinkedList;
import org.junit.Test;

public class TestDoublyLinkedList {

    @Test
    public void test() {
        DoublyLinkedList list = new DoublyLinkedList();

        list.insertBack(10);
        list.insertBack(20);
        list.insertBack(30);
        list.insertFront(40);
        list.insertFront(50);

        assert list.inOrder().equals("50 40 10 20 30 ");

        assert list.search(40).data == 40;
        assert list.search(30).data == 30;

        assert list.first().data == 50;
        assert list.last().data == 30;

        list.delete(1);
        list.delete(2);

        assert list.inOrder().equals("40 20 30 ");

        list.setValue(1, 50);
        list.setValue(2, 60);

        assert list.inOrder().equals("50 60 30 ");

        assert list.getValue(3) == 30;

        assert list.get(100) == null;

        list.delete(3);
        list.insertBack(20);

        assert list.inOrder().equals("50 60 20 ");

        list.deleteFront();
        list.insertFront(40);

        assert list.inOrder().equals("40 60 20 ");

        list.deleteBack();
        list.insertBack(50);

        assert list.inOrder().equals("40 60 50 ");

        list.delete(2);
        list.insertFront(30);

        assert list.inOrder().equals("30 40 50 ");
    }
}
