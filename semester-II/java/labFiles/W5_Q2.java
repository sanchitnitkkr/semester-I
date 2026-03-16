// Program 2: Write a Java program that uses interface for the implementation of fixed-
// size and dynamic-size stacks (for dynamic stack size should be redefined as per the
// number of elements).
package labFiles;

interface Stack<T> {
    void push(T ele);

    T pop();
};

class Node<T> {
    private T data;
    private Node<T> next;

    Node(T data) {
        this.data = data;
    }

    Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public T getData() {
        return data;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setData(T data) {
        this.data = data;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}

class FixedStack<T> implements Stack<T> {
    private T[] arr;
    private int top = -1;
    private int size;

    FixedStack(int numberOfElements) {
        this.size = numberOfElements;
        this.arr = (T[]) new Object[numberOfElements];
    }

    private boolean isFull() {
        if (top == size - 1) {
            return true;
        }
        return false;
    }

    private boolean isEmpty() {
        if (top == -1)
            return true;
        return false;
    }

    @Override
    public void push(T ele) {
        if (isFull()) {
            System.out.println("Overflow: Stack is full");
            return;
        }
        ;

        this.arr[++(this.top)] = ele;
    }

    @Override
    public T pop() {
        if (isEmpty()) {
            System.out.println("Underflow: Stack is empty");
            return null;
        }
        ;

        return this.arr[top--];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is full!");
            return;
        }
        for (int i = 0; i <= top; i++) {
            System.out.println(arr[i]);
        }
    };
}

class DynamicStack<T> implements Stack<T> {
    Node<T> root;

    @Override
    public void push(T ele) {
        Node<T> newNode = new Node<>(ele, null);
        if (root == null) {
            root = newNode;
            return;
        } else {
            newNode.setNext(root);
            root = newNode;
        }
    };

    private boolean isEmpty() {
        if (root == null) {
            System.out.println("Stack is empty!");
            return true;
        }
        return false;
    }

    @Override
    public T pop() {
        if (isEmpty()) {
            return null;
        }
        ;

        Node<T> currNode = root;
        root = root.getNext();
        return currNode.getData();
    };

    public void display() {
        if (isEmpty()) {
            return;
        }
        Node<T> iter = root;

        while (iter != null) {
            System.out.println(iter.getData());
            iter = iter.getNext();
        }
        ;
    }
}

public class W5_Q2 {
    public static void main(String[] args) {
        FixedStack<Integer> s1 = new FixedStack<>(5);

        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.push(5);
        s1.pop();
        s1.display();
        s1.push(6);
        s1.display();

        DynamicStack<Integer> s2 = new DynamicStack<>();
        s2.push(1);
        s2.display();
        s2.pop();
        s2.display();
    }
}
