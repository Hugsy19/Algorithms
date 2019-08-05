/* *****************************************************************************
 *  Name: RandomizedQueue.java
 *  Date: 19-03-22
 *  Description: A randomized queue
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] queue;
    private int n;

    public RandomizedQueue() { // 构造空的随机队列
        queue = (Item[]) new Object[2];
        n = 0;
    }

    public boolean isEmpty() { // 队列是否为空
        return n == 0;
    }

    public int size() { // 队列中元素数量
        return n;
    }

    public void enqueue(Item item) { // 入队
        if (item == null)
            throw new IllegalArgumentException("item is null!!");

        if (n == queue.length)
            resize(2 * queue.length); // 动态调整
        queue[n++] = item;
    }

    public Item dequeue() { // 随机出队
        if (isEmpty())
            throw new NoSuchElementException("RandomizedQuque is empty!!");

        int rd = StdRandom.uniform(n); // 生成随机数
        Item item = queue[rd];
        if (rd != n - 1)
            queue[rd] = queue[n - 1]; // 将队尾元素放入随机位置上
        queue[n - 1] = null;
        n--;

        if (n > 0 && n == queue.length / 4) // 动态调整
            resize(queue.length / 2);

        return item;
    }

    private void resize(int max) { // 动态调整数组大小
        Item[] temp = (Item[]) new Object[max];
        for (int i = 0; i < n; i++)
            temp[i] = queue[i];
        queue = temp;
    }

    public Item sample() { // 随机返回一项
        if (isEmpty())
            throw new NoSuchElementException("RandomizedQuque is empty!!");

        int rd = StdRandom.uniform(n); // 生成随机数

        return queue[rd];
    }

    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private Item[] rqueue;
        private int current;

        public RandomizedQueueIterator() {
            rqueue = (Item[]) new Object[n];
            current = 0;

            for (int k = 0; k < n; k++)
                rqueue[k] = queue[k];

            StdRandom.shuffle(rqueue); // 随机调整顺序
        }

        public boolean hasNext() {
            return current < n;
        }

        public void remove() {
            throw new UnsupportedOperationException("remove method is unsupported!!");
        }

        public Item next() {
            if (!hasNext())
                throw new NoSuchElementException("RandomizedQuque is empty!!");

            Item item = rqueue[current];
            current++;
            return item;
        }
    }

    public static void main(String[] args) {
        RandomizedQueue<String> rqueue = new RandomizedQueue<>();
        rqueue.enqueue("item1");
        rqueue.enqueue("item2");
        rqueue.enqueue("item3");
        rqueue.enqueue("item4");

        for (String s:rqueue)
            StdOut.println(s);

        StdOut.println(rqueue.dequeue());
        StdOut.println(rqueue.dequeue());
        StdOut.println(rqueue.dequeue());
        StdOut.println(rqueue.dequeue());
    }
}
