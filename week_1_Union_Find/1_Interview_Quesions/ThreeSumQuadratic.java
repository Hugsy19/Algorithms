/* *****************************************************************************
 *  Name: ThreeSumQuadratic.java
 *  Date: 2019-07-20
 *  Description: Algs4_week1 interview_question_4
 **************************************************************************** */

import edu.princeton.cs.algs4.BinarySearch;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;

import java.util.Arrays;
import java.util.HashMap;

public class ThreeSumQuadratic {

    public static int countQuadratic(int[] a) {
        Arrays.sort(a);
        int N = a.length;
        int cnt = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            map.put(a[i], i);
        }

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                Integer index = map.get(-a[i] - a[j]);
                if (index != null && index > j)
                    cnt++;
            }

        return cnt;
    }

    public static int countBinary(int[] a) { // 二分查找
        Arrays.sort(a); // 排序
        int N = a.length;
        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (BinarySearch.indexOf(a, -a[i]-a[j]) > j)
                    cnt++;
        return cnt;
    }

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int[] a = new int[N];
        for (int i = 0; i < N; i++)
            a[i] = StdRandom.uniform(-1000000, 1000000);
        Stopwatch timer = new Stopwatch();
        int cnt = ThreeSumQuadratic.countBinary(a);
        double time = timer.elapsedTime();
        StdOut.println("BinarySearch: " + cnt + " triples " + time + " seconds");

        Stopwatch timer_ = new Stopwatch();
        int cntq = ThreeSumQuadratic.countQuadratic(a);
        double time_ = timer_.elapsedTime();
        StdOut.println("HashMap: "+ cnt + " triples " + time_ + " seconds");
    }
}
