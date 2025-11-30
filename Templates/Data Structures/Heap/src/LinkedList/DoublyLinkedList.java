package LinkedList;

public class DoublyLinkedList {

    Node head;
    Node tail;

    public DoublyLinkedList() {
        head = null;
        tail = null;
    }

    public Node first() {
        return head;
    }

    public Node last() {
        return tail;
    }

    public void insertBack(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail.next = newNode;
        newNode.prev = tail;

        tail = newNode;
    }

    public void insertFront(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode.next = head;
        head.prev = newNode;

        head = newNode;
    }

    public Node get(int index) {
        int current = 1;
        Node temp = head;

        while(current != index && temp != null) {
            current++;
            temp = temp.next;
        }

        return temp;
    }

    public int getValue(int index) {
        return get(index).data;
    }

    public void setValue(int index, int data) {
        Node update = get(index);
        update.data = data;
    }

    public void delete(int index) {
        Node delete = get(index);
        Node prev = delete.prev;
        Node next = delete.next;

        if (prev != null) {
            prev.next = next;
        }

        if (next != null) {
            next.prev = prev;
        }

        if (delete == head) {
            head = next;
        }

        if (delete == tail) {
            tail = prev;
        }
    }

    public void deleteFront() {
        head = head.next;
        head.prev = null;
    }

    public void deleteBack() {
        tail = tail.prev;
        tail.next = null;
    }

    public Node search(int data) {
        Node current = head;
        while (current != null && current.data != data) {
            current = current.next;
        }
        return current;
    }

    public String inOrder() {
        Node current = head;
        StringBuilder result = new StringBuilder();
        while (current != null) {
            result.append(current.data).append(" ");
            current = current.next;
        }
        return result.toString();
    }
}
