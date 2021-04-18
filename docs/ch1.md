# 第一章 基础

## 数据结构

**数据结构**（data structure）是指相互之间存在着一种或多种关系的数据元素的集合，它包括以下三方面的内容：

- **逻辑结构**：数据元素之间的逻辑关系，它独立于计算机，与数据的存储无关。数据的逻辑结构可分为：
  - 线性结构：结构中的数据元素间存在一一对应关系，典型的有**线性表**。
  - 非线性结构：结构中的数据元素间不存在或存在多种对应关系，典型的有**集合**、**树**、**图**。
- **存储结构**：数据结构在计算机中的表示方式，它依赖于计算机语言，包括数据元素的表示和关系的表示。数据的存储结构主要有：
  - 顺序存储：逻辑上相邻的元素存储的物理位置也相邻，元素间的关系用存储单元的邻接关系来体现，可实现**随机存取**。
  - 链式存储：逻辑上相邻的元素存储的物理位置不一定相邻，而借助元素的存储地址的指针来表示元素间逻辑关系，只能**顺序存取**。
  - 索引存储：存储元素信息的同时，另建立索引表，索引表中存放一般形式为（关键字，地址）的索引项。
  - 散列存储：根据元素的关键字计算出其存储地址。
- **数据的运算**：包括对运算的定义和实现：
  - 定义是针对逻辑结构而指出运算的功能；
  - 实现则是针对存储结构指出运算的具体步骤。

## 算法

**算法**（Algorithm）是对特定问题求解步骤的一种描述，在计算机科学中它由指令的有限序列组成。一个算法包含以下五个特性：
- 有穷性：算法执行有穷步后结束。
- 确定性：对于相同的输入只能得到相同的输出。
- 可行性：可通过以实现的基本运算、执行有限次来实现。
- 输入：有零个或多个输入。
- 输出：有一个或多个输出。

## 背包、队列和栈

### 栈

**线性表**（linear list）是由相同数据类型的多个数据元素组成的有限序列，可采用顺序或链式方式存储，且它的顺序存储又称为**顺序表**。

**下压栈**（stack）是一种**后进先出**（Last In First Out，LIFO）的线性表，将某个对象添加到该数据结构的过程称为**入栈（push）**，取出的过程则称为**出栈（pop）**。

<details>
  <summary>折叠代码块</summary>
  <pre><code> 

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item> {
    private Node first; // 栈顶
    private int n; // 元素数量

    private class Node {
        Item item;
        Node next;
    }

    public Stack() {
        first = null;
        n = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return n;
    }

    public void push(Item item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        n++;
    }

    public Item pop() {
        if (isEmpty()) 
            throw new NoSuchElementException("Stack underflow");

        Item item = first.item;
        first = first.next;
        n--;
        return item;
    }

    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current;

        public ListIterator() {
            current = first;
        }

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }
}
  </code></pre>
</details>