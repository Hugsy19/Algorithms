/* *****************************************************************************
 *  Name: CompleteParentheses.java
 *  Date: 2019-08-04
 *  Description: Algs4_chapter 1.3 question 1.3.9
 **************************************************************************** */

import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class CompleteParentheses {
    public static void main(String[] args) {
        Stack<String> ops = new Stack<>();
        Stack<String> vals = new Stack<> ();

        while(!StdIn.isEmpty()) {
            String tmp = StdIn.readString();
            if (tmp.equals(")")) {
                String v2 = vals.pop();
                String v1 = vals.pop();
                vals.push('(' + v1 + ops.pop() + v2 + ')');
            } else if (tmp.equals("+") || tmp.equals("-") || tmp.equals("*") || tmp.equals("/"))
                ops.push(tmp);
            else
                vals.push(tmp);
        }

        while (ops.size() > 0) {
            String v2 = vals.pop();
            String v1 = vals.pop();
            vals.push('(' + v1 + ops.pop() + v2 + ')');
        }

        StdOut.println(vals.pop());
    }
}
