import Stack.Stack;
import org.junit.Test;


public class TestStack {

    @Test
    public void test() {

        Stack stack = new Stack();

        stack.push(1);
        stack.push(2);
        stack.push(3);

        assert stack.peek() == 3;

        stack.pop();

        assert stack.peek() == 2;
        assert stack.pop() == 2;
        stack.pop();

        assert stack.isEmpty();
    }
}
