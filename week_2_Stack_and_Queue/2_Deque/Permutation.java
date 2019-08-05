/* *****************************************************************************
 *  Name: Permutation.java
 *  Date: 19-03-22
 *  Description: The client program of the Deque and RandomizedQueue
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
    public static void main(String[] args) {
        int k = Integer.parseInt(args[0]);
        RandomizedQueue<String> rqueue = new RandomizedQueue<>();

        while (!StdIn.isEmpty()) {
            rqueue.enqueue(StdIn.readString());
        }

        for (int i = 0; i < k; i++)
            StdOut.println(rqueue.dequeue());
    }
}
