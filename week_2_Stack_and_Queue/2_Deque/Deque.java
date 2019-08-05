/* *****************************************************************************
 *  Name: Deque.java
 *  Date: 19-03-22
 *  Description: A double-ended queue
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int n;

    private class Node {
        private Item item;
        private Node prev;
        private Node next;
    }

    public Deque() { // 构造空的双端队列
        first = null;
        last = null;
        n = 0;
    }

    public boolean isEmpty() { // 队列是否为空
        return n == 0;
    }

    public int size() { // 队列中元素数量
        return n;
    }

    public void addFirst(Item item) { // 从队首添加元素
        if (item == null)
          throw new java.lang.IllegalArgumentException("item is null!!");

        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.prev = null;

        if (oldfirst == null) { // 队列为空
            last = first;
            first.next = null;
        } else { // 队列非空
            first.next = oldfirst;
            oldfirst.prev = first;
        }
        n++;
    }

    public void addLast(Item item) { // 从队尾添加元素
        if (item == null)
            throw new java.lang.IllegalArgumentException("item is null!!");

        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;

        if (oldLast == null) { // 队列为空
            first = last;
            last.prev = null;
        } else {  // 队列非空
            last.prev = oldLast;
            oldLast.next = last;
        }
        n++;
    }

    public Item removeFirst() { // 从队首删除
        if (isEmpty())
            throw new java.util.NoSuchElementException("deque is empty!!");

        Item item = first.item;
        first = first.next;
        n--;

        if (isEmpty()) { // 删除后队列为空
           last = null;
        } else {
            first.prev = null;
        }

        return item;
    }

    public Item removeLast() { // 从队尾删除
        if (isEmpty())
            throw new java.util.NoSuchElementException("deque is empty!!");

        Item item = last.item;
        last = last.prev;
        n--;

        if (isEmpty()) { // 删除后队列为空
            first = null;
        } else {
            last.next = null;
        }

        return item;
    }

    public Iterator<Item> iterator() { // 迭代器
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException("remove method is unsupported!!");
        }

        public Item next() {
            if (!hasNext())
                throw new NoSuchElementException("deque is empty!!");

            Item item = current.item;
            current = current.next;

            return item;
        }
    }

    public static void main(String[] args) {
        Deque<String> deque = new Deque<String>();
        deque.addFirst("first1");
        deque.addLast("last1");
        deque.addFirst("first2");
        deque.addLast("last2");

        for (String s:deque)
            StdOut.println(s);

        deque.removeFirst();
        deque.removeLast();
        deque.removeFirst();
        deque.removeLast();
        deque.removeFirst();
        deque.removeLast();

        StdOut.println(deque.size());

    }
}
