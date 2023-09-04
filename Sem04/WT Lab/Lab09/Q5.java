package GeneralProject.WTLab.Lab09;

class StackFullException extends Exception {
    public StackFullException(String message) {
        super(message);
    }
}

class StackEmptyException extends Exception {
    public StackEmptyException(String message) {
        super(message);
    }
}

class Stack {
    private final int[] arr;
    private int top;
    private final int size;

    public Stack(int n) {
        arr = new int[n];
        size = n;
        top = -1;
    }

    public void push(int x) throws StackFullException {
        if (isFull()) {
            throw new StackFullException("Stack is full.");
        }
        arr[++top] = x;
    }

    public int pop() throws StackEmptyException {
        if (isEmpty()) {
            throw new StackEmptyException("Stack is empty.");
        }
        return arr[top--];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == size - 1;
    }
}

class Main {
    public static void main(String[] args) {
        Stack stack = new Stack(5);

        try {
            stack.push(1);
            stack.push(2);
            stack.push(3);
            stack.push(4);
            stack.push(5);
            stack.push(6);
        } catch (StackFullException e) {
            System.out.println(e.getMessage());
        }

        try {
            while (!stack.isEmpty()) {
                System.out.println(stack.pop());
            }
            stack.pop();
        } catch (StackEmptyException e) {
            System.out.println(e.getMessage());
        }
    }
}