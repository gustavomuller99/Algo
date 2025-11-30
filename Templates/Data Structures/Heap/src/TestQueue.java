import Queue.Queue;
import org.junit.Test;

public class TestQueue {

    @Test
    public void test() {

        Queue stack = new Queue();

        stack.enqueue(1);
        stack.enqueue(2);
        stack.enqueue(3);

        assert stack.peek() == 1;

        stack.dequeue();

        assert stack.peek() == 2;
        assert stack.dequeue() == 2;
        stack.dequeue();

        assert stack.isEmpty();
    }

}
