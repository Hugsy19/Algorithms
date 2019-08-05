/* *****************************************************************************
 *  Name: StackQueue.java
 *  Date: 2019-08-01
 *  Description: Algs4_week2 interview_question_1
 **************************************************************************** */

import java.util.LinkedList;

public class StackQueue<Item> {
    private LinkedList<Item> stackA;
    private LinkedList<Item> stackB;

    public StackQueue() {
        stackA = new LinkedList<>();
        stackB = new LinkedList<>();
    }

    public boolean isEmpty() {
        return stackA.isEmpty() && stackB.isEmpty();
    }

    public void enqueue(Item item) {
        stackA.push(item);
    }

    public int size() {
        return stackA.size() + stackB.size();
    }

    public Item dequeue() {
        if (stackB.isEmpty()) {
            if (stackA.isEmpty())
                throw new NullPointerException("Queue is Empty!!");
            else {
                while (!stackA.isEmpty())
                    stackB.push(stackA.pop());
            }
        }
        return stackB.pop();
    }
}
