/* *****************************************************************************
 *  Name: HeightWeightedQuickUnionUF.java
 *  Date: 2019-07-31
 *  Description: Algs4_chapter 1.5 question 1.5.14
 **************************************************************************** */

public class HeightWeightedQuickUnionUF {
    private int[] id;
    private int[] height;

    public HeightWeightedQuickUnionUF(int N) {
        id = new int[N];
        height = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            height[i] = 0;
        }
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

        if (height[pRoot] < height[qRoot]) {
            id[pRoot] = qRoot;
        } else if (height[pRoot] > height[qRoot]) {
            id[qRoot] = pRoot;
        } else {
            id[qRoot] = pRoot;
            height[pRoot]++;
        }
    }
}
