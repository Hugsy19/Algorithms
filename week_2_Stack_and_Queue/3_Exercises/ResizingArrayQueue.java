/* *****************************************************************************
 *  Name: ResizingArrayQueue.java
 *  Date: 2019-08-04
 *  Description: Algs4_chapter 1.3 question 1.3.14
 **************************************************************************** */

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayQueue<Item> implements Iterable<Item> {
    private Item[] q;
    private int n;
    private int first;
    private int last;

    public ResizingArrayQueue() {
        q = (Item[]) new Object[2];
        n = 0;
        first = 0;
        last = 0;
    }

    private void resize(int cap) {
        Item[] temp = (Item[]) new Object[cap];
        for (int i = 0; i < n; i ++)
            temp[i] = q[(first + i) % q.length];
        q = temp;
        first = 0;
        last = n;
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    public void enqueue(Item item) {
        if (n == q.length)
            resize(2*q.length);
        q[last++] = item;

        if (last == q.length) // 循环利用空间
            last = 0;
        n++;
    }

    public Item dequeue() {
        if (isEmpty())
            throw new NoSuchElementException("Queue underflow");

        Item item = q[first];
        q[first] = null;
        n--;
        first++;

        if (first == q.length)
            first = 0;

        if (n > 0 && n == q.length/4)
            resize(q.length/2);

        return item;
    }

    public Iterator<Item> iterator() {
        return new ArrayIterator();
    }


    private class ArrayIterator implements Iterator<Item> {
        private int i;

        public ArrayIterator() {
            i = 0;
        }

        public boolean hasNext()  {
            return i < n;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = q[(i + first) % q.length];
            i++;
            return item;
        }
    }

}
