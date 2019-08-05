/* *****************************************************************************
 *  Name: InfixToPostfix .java
 *  Date: 2019-08-04
 *  Description: Algs4_chapter 1.3 question 1.3.10
 **************************************************************************** */

import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class InfixToPostfix {

    public void evaluetePostfix() { // question 1.3.11
        Stack<Double> vals = new Stack<>();

        while (!StdIn.isEmpty()) {
            String tmp = StdIn.readString();
            if (tmp.equals("+") || tmp.equals("-") || tmp.equals("*") || tmp.equals("/")) {
                double v = vals.pop();
                if (tmp.equals("+"))
                    v = vals.pop() + v;
                else if (tmp.equals("-"))
                    v = vals.pop() - v;
                else if (tmp.equals("*"))
                    v = vals.pop() * v;
                else if (tmp.equals("/"))
                    v = vals.pop() / v;
                vals.push(v);
            } else
                vals.push(Double.parseDouble(tmp));
        }

        StdOut.println(vals.pop());
    }

    public static void main(String[] args) {
        Stack<String> ops = new Stack<>();

        while (!StdIn.isEmpty()) {
            String str = StdIn.readString();
            if (str.equals("("))
                ops.push(str);
            else if (str.equals("+") || str.equals("-") || str.equals("*") || str.equals("/")) {
                boolean isEmpty = ops.isEmpty();
                boolean isLeftParen = false;
                boolean isLowerOperator = false;

                if (!isEmpty) {
                    String stackTop = ops.peek();
                    isLeftParen = ops.peek().equals("(");
                    if ((stackTop.equals("+") || stackTop.equals("-")) && (str.equals("*") || str.equals("/")))
                        isLowerOperator = true;
                }

                if (!(isEmpty || isLeftParen || isLowerOperator)) {
                    while (!ops.isEmpty())
                        StdOut.print(ops.pop());
                }
                ops.push(str);
            } else if (str.equals(")")) {
                while (!ops.isEmpty()) {
                    String tmp = ops.pop();
                    if (!tmp.equals("("))
                        StdOut.print(tmp);
                }
            } else {
                StdOut.print(str);
            }
        }
        StdOut.println();
    }
}
