/* *****************************************************************************
 *  Name: StackQueue.java
 *  Date: 2019-08-01
 *  Description: Algs4_week2 interview_question_2
 **************************************************************************** */

import java.util.LinkedList;

public class MaxStack {
    private LinkedList<Integer> stackA;
    private LinkedList<Integer> stackB;

    public MaxStack() {
        LinkedList<Integer> stackA = new LinkedList<>();
        LinkedList<Integer> stackB = new LinkedList<>();
    }

    public boolean isEmpty() {
        return stackA.isEmpty() && stackB.isEmpty();
    }

    public int size() {
        return stackA.size() + stackB.size();
    }

    public void push(Integer i) {
        if (stackB.isEmpty() || i >= stackB.peek())
            stackB.push(i);

        stackA.push(i);
    }

    public Integer pop() {
        if (stackB.isEmpty())
            throw new NullPointerException("Stack is Empty!!");

        int max = stackB.peek();
        if (stackA.peek() == max)
            stackB.pop();

        return stackA.pop();
    }

    public Integer max() {
        return stackB.peek();
    }
}
