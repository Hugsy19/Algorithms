/* *****************************************************************************
 *  Name: Successor.java
 *  Date: 2019-07-18
 *  Description: Algs4_week1 interview_question_3
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;

public class Successor{
    private int[] id;
    private int[] sz;
    private int count;

    private final int n;
    private boolean[] isRemove; // 记录移除情况

    public Successor(int n) {
        count = n;
        this.n = n;
        id = new int[n];
        isRemove = new boolean[n];
        for (int i = 0; i < n; i++)
            id[i] = i;

        sz = new int[n];
        for (int i = 0; i < n; i++)
            sz[i] = 1;
    }

    public int count() {
        return count;
    }

    public int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        if (sz[pRoot] < sz[qRoot]) { // 总是以值较大的作为根节点
            if (pRoot > qRoot) {
                int tmp = pRoot, tmpSize = sz[pRoot];
                pRoot = qRoot;
                sz[pRoot] = sz[qRoot];
                qRoot = tmp;
                sz[qRoot] = tmpSize;
            }
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            if (pRoot < qRoot) {
                int tmp = qRoot, tmpSize = sz[qRoot];
                qRoot = pRoot;
                sz[qRoot] = sz[pRoot];
                pRoot = tmp;
                sz[pRoot] = tmpSize;
            }
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        count--;
    }

    public void remove(int p) { // 删除元素
        if (isRemove[p]) // 还未被移除
            throw new IllegalArgumentException("The element has been removed!");

        if (p > n) // 防止越界
            throw new IllegalArgumentException("Array access out of bounds!");

        isRemove[p] = true;
        if (p + 1 < n)
            union(p, p+1);
    }

    public int getSuccessor(int p) { // 寻找继任者
        int successor = find(p);
        if (isRemove[successor]) // 继任者已被移除
            return -1;
        else
            return successor;
    }

    public static void main(String[] args) {
        Successor successor = new Successor(10);
        int[] a = {6, 5, 3, 4, 8, 9, 7, 2, 0};

        for (int i = 0; i < a.length; i++) {
            successor.remove(a[i]);
            StdOut.println("The successor of " + a[i] + " is " + successor.getSuccessor(a[i]));
        }
    }
}
