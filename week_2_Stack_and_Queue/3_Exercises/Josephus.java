/* *****************************************************************************
 *  Name: Josephus.java
 *  Date: 2019-08-05
 *  Description: Algs4_chapter 1.3 question 1.3.37
 **************************************************************************** */

import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdOut;

public class Josephus {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int m = Integer.parseInt(args[1]);

        Queue<Integer> queue = new Queue<>();
        for (int i = 0; i < n; i++)
            queue.enqueue(i);

        while(!queue.isEmpty()) {
            for (int i = 0; i < m - 1; i++)
                queue.enqueue(queue.dequeue());
            StdOut.print(queue.dequeue() + " ");
        }
        StdOut.println();
    }
}
