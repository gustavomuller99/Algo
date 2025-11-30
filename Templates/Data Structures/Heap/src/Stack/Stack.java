package Stack;

import LinkedList.LinkedList;

public class Stack {

    LinkedList stack;

    public Stack() {
        stack = new LinkedList();
    }

    public void push(int data) {
        stack.insertFront(data);
    }

    public int pop() {
        int val = stack.getValue(1);
        stack.deleteFront();
        return val;
    }

    public int peek() {
        return stack.getValue(1);
    }

    public boolean isEmpty() {
        return stack.get(1) == null;
    }

}
