/* *****************************************************************************
 *  Name: SocialNetworkUF.java
 *  Date: 2019-07-17
 *  Description: Algs4_week1 interview_question_1
 **************************************************************************** */

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class SocialNetworkUF {

    private In inputs; // 输入流
    private final WeightedQuickUnionUF networkUF; // 以加权Quick-Union为数据结构

    public SocialNetworkUF(int n, In inputs) {
        this.inputs = inputs;
        networkUF = new WeightedQuickUnionUF(n);
    }

    public String getEarliestConnectedTime() { // 确定网络全连接的最早时间点
        String earliestTime = null;
        while (!inputs.isEmpty()) {
            String line = inputs.readLine();
            if (line != null && !line.trim().equals("")) {
                String[] lineArray = line.split(" "); // 将读取到的一行日志进行切分
                if (lineArray.length == 3) {
                    String timeStamp = lineArray[0];
                    int p = Integer.parseInt(lineArray[1]);
                    int q = Integer.parseInt(lineArray[2]);

                    if (networkUF.connected(p, q))
                        continue;
                    networkUF.union(p, q);
                    if (networkUF.count() == 1) { // 只剩下一棵树
                        earliestTime = timeStamp;
                        break;
                    }
                }
            }
        }
        return earliestTime;
    }

    public static void main(String[] args) {
        In inputs = new In(args[0]); // logs.txt
        int n = inputs.readInt();
        SocialNetworkUF networkUF = new SocialNetworkUF(n, inputs);
        String earliestTime = networkUF.getEarliestConnectedTime();
        StdOut.println("The earliest connected time of the social network is:" + earliestTime);
    }
}
