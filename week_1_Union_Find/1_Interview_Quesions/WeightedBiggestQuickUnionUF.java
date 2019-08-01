/* *****************************************************************************
 *  Name: WeightedBiggestQuickUnionUF.java
 *  Date: 2019-07-17
 *  Description: Algs4_week1 interview_question_2
 **************************************************************************** */


import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class WeightedBiggestQuickUnionUF {
    private int[] id;
    private int[] sz;
    private int count;

    public WeightedBiggestQuickUnionUF(int N) {
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;

        sz = new int[N];
        for (int i = 0; i < N; i++)
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

        if (sz[pRoot] < sz[qRoot]) {
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

    public static void main(String[] args) {
        In inputs = new In(args[0]); // uf.txt
        int n = inputs.readInt();
        WeightedBiggestQuickUnionUF uf = new WeightedBiggestQuickUnionUF(n);

        while(!inputs.isEmpty()) {
            int p = inputs.readInt();
            int q = inputs.readInt();
            if (uf.connected(p, q))
                continue;
            uf.union(p, q);
        }

        for (int i = 0; i < n; i++)
            StdOut.println("The root of the node " + i + " is " + uf.find(i));
    }
}
