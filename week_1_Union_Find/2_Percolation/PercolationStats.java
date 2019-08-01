/* *****************************************************************************
 *  Name: PercolationStates.java
 *  Date: 2019-07-18
 *  Description:  Programming Assignment 1:Percolation
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private final int trials; // 实验次数
    private final double[] fractions; // 分值记录

    private double mean; // 平均值
    private double stddev; // 标准差

    public PercolationStats(int n, int trials) { // 初始化
        if (n <= 0 || trials <= 0)
            throw new IllegalArgumentException("Some of the argument is illegal!");

        this.trials = trials;
        fractions = new double[trials];

        for (int i = 0; i < trials; i++) {
            Percolation p = new Percolation(n);

            while (true) {
                int row, col;
                row = StdRandom.uniform(n) + 1; // 随机列
                col = StdRandom.uniform(n) + 1; // 随机行
                p.open(row, col);

                if (p.numberOfOpenSites() >= n && p.percolates()) {
                    fractions[i] = (double) p.numberOfOpenSites() / (n * n);
                    break;
                }
            }
        }
    }

    public double mean() { // 平均值
        mean = StdStats.mean(fractions);
        return mean;
    }

    public double stddev() { // 标准差
        stddev = StdStats.stddev(fractions);
        return stddev;
    }

    public double confidenceLo() { // 置信区间
        return mean - 1.96 * stddev / Math.sqrt(trials);
    }

    public double confidenceHi() {
        return mean + 1.96 * stddev / Math.sqrt(trials);
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);

        PercolationStats ps = new PercolationStats(n, trials);
        StdOut.print("mean = " + ps.mean() + "\n");
        StdOut.print("stddev = " + ps.stddev() + "\n");
        StdOut.print("95% confidence interval = [" + ps.confidenceLo() + ", " + ps.confidenceHi() + "]\n");
    }
}