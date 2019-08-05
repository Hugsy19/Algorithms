/* *****************************************************************************
 *  Name: Parentheses.java
 *  Date: 2019-08-03
 *  Description: Algs4_chapter 1.3 question 1.3.4
 **************************************************************************** */

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

public class Parentheses {
    private static final char L_PAREN = '(';
    private static final char R_PAREN = ')';
    private static final char L_BRACE = '{';
    private static final char R_BRACE = '}';
    private static final char L_BRACKET = '[';
    private static final char R_BRACKET = ']';

    public static boolean isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == L_PAREN || s.charAt(i) == L_BRACE || s.charAt(i) == L_BRACKET)
                stack.push(s.charAt(i));

            if (s.charAt(i) == R_PAREN) {
                if (stack.isEmpty())
                    return false;
                if (stack.pop() != L_PAREN)
                    return false;
            } else if (s.charAt(i) == R_BRACE) {
                if (stack.isEmpty())
                    return false;
                if (stack.pop() != L_BRACE)
                    return false;
            } else if (s.charAt(i) == R_BRACKET) {
                if (stack.isEmpty())
                    return false;
                if (stack.pop() != L_BRACKET)
                    return false;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        In in = new In();
        String s = in.readAll().trim();
        StdOut.println(isBalanced(s));
    }
}
