/* *****************************************************************************
 *  Name: BitonicArraySearch.java
 *  Date: 2019-07-25
 *  Description: Algs4_week1 interview_question_5
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;

public class BitonicArraySearch {
    private static int leftSearch(int[] a, int key, int lo, int hi) { // 在升序序列上进行二分查找
        int mid = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (key < a[mid])
                hi = mid - 1;
            else if (key > a[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    private static int rightSearch(int[] a, int key, int lo, int hi) { // 在降序序列上进行二分查找
        int mid = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (key > a[mid])
                hi = mid - 1;
            else if (key < a[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    public static int normalSearch(int[] a, int key) { // 上界为3log N的查找算法
        int lo = 0;
        int hi = a.length - 1;
        int mid = 0;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (a[mid] < a[mid + 1])
                lo = mid + 1;
            else
                hi = mid;
        }

        if (key > a[mid]) // key大于数组中的最大值，则key不存在
            return -1;

        int result = leftSearch(a, key, 0, mid - 1);
        if (result == -1)
            result = rightSearch(a, key, mid + 1, a.length - 1);

        return result;
    }

    public static int fastSearch(int[] a, int key) {
        int lo = 0;
        int hi = a.length - 1;
        int mid = 0;
        int result = -1;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (key < a[mid]) {
                result = leftSearch(a, key, lo, mid - 1);
                if (result == -1)
                    result = rightSearch(a, key, mid + 1, hi);
            } else {
                if (a[mid] < a[mid + 1])
                    lo = mid + 1;
                else
                    hi = mid;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] a = {1, 3, 4, 6, 7, 9, 8, 5, 2};
        StdOut.print(normalSearch(a, 2));
        StdOut.print(fastSearch(a, 2));
    }
}
