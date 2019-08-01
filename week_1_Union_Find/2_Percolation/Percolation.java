/* *****************************************************************************
 *  Name: Percolations.java
 *  Date: 2019-07-18
 *  Description:  Programming Assignment 1:Percolation
 **************************************************************************** */

import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private static final boolean BLOCK = false;
    private static final boolean OPEN = true;

    private final int n; // 容器大小
    private boolean[][] grid; // 容器
    private int openedNum; // 记录已开放数量
    private final WeightedQuickUnionUF gridUF; // 加权Quick-Union
    private final WeightedQuickUnionUF gridUFBacklash; // 解决backlash问题

    public Percolation(int n) { // 初始化
        if (n <= 0)
            throw new IllegalArgumentException("The Value of n is illegal!");

        this.n = n;
        grid = new boolean[n][n];
        openedNum = 0;
        gridUF = new WeightedQuickUnionUF(n * n + 2); // 加上两个虚节点
        gridUFBacklash = new WeightedQuickUnionUF((n * n + 1)); // 只包含上虚节点

        for (int i = 0; i < n; i++) // 初始化
            for (int j = 0; j < n; j++)
                grid[i][j] = BLOCK;
    }

    private void validate(int row, int col) { // 验证索引值
        if (row < 1 || col < 1 || col > n || row > n)
            throw new IllegalArgumentException("The index of row/column is illegal!");
    }

    private int map2Dto1D(int row, int col) { // 坐标转换
        return (row - 1) * n + col;
    }

    public void open(int row, int col) { // 打开某节点

        validate(row, col);

        if (!grid[row - 1][col - 1]) {
            grid[row - 1][col - 1] = OPEN; // 开启并计数
            openedNum++;

            int position = map2Dto1D(row, col);
            if (row == 1) {
                gridUF.union(0, position); // 如果是第一行的节点，与上方虚节点0相连
                gridUFBacklash.union(0, position);
            }

            if (row > 1 && grid[row - 2][col - 1]) { // 判断节点上方是否开放
                gridUF.union(position - n, position);
                gridUFBacklash.union(position - n, position);
            }

            if (row < n && grid[row][col - 1]) { // 判断节点下方是否开放
                gridUF.union(position + n, position);
                gridUFBacklash.union(position + n, position);
            }

            if (col > 1 && grid[row - 1][col - 2]) { // 判断节点左方是否开放
                gridUF.union(position - 1, position);
                gridUFBacklash.union(position - 1, position);
            }

            if (col < n && grid[row - 1][col] == OPEN) { // 判断节点右方是否开放
                gridUF.union(position + 1, position);
                gridUFBacklash.union(position + 1, position);
            }

            if (row == n) // 如果是最后一行的节点，与下方的虚节点（n×n + 1）相连
                gridUF.union(position, n*n + 1);
            }
    }

    public boolean isOpen(int row, int col) { // 判断某个节点是否打开
        validate(row, col);
        return grid[row - 1][col - 1];
    }

    public boolean isFull(int row, int col) { // 判断某个节点是否渗透
        validate(row, col);
        int position = map2Dto1D(row, col);
        return gridUFBacklash.connected(0, position);
    }

    public int numberOfOpenSites() { // 开放节点值
        return openedNum;
    }

    public boolean percolates() { // 系统是否渗透
        return gridUF.connected(0, n * n + 1);
    }
}

