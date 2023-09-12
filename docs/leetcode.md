## 1. 两数之和

[两数之和](https://leetcode.cn/problems/two-sum/)

### 描述

给定一个整数数组`nums`和一个整数目标值`target`，请你在该数组中找出和为目标值`target`的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例：输入：`nums = [2,7,11,15], target = 9`，输出：`[0,1]`

提示：`2 <= nums.length <= 104`、`-109 <= nums[i] <= 109`、`-109 <= target <= 109`

### 解答

1. 暴力破解:

直接用双层`for`循环解决：

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (target == nums[i] + nums[j]) return {i, j};
    }
  }
  return {};
}
```

时间复杂度$O(N^2)$，空间复杂度$O(1)$。

Python实现如下：

```python
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    nums_len = len(nums)
    for i in range(nums_len):
        for j in range(i+1, nums_len):
            if target == nums[i] + nums[j]:
                return i, j
    return []
```

2. 使用哈希表:

使用C++中的哈希表`unordered_map`，以空间换时间：

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
  std::unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = map.find(target - nums[i]);
    if (it != map.end()) {
      return {it->second, i};
    }
    map[nums[i]] = i;
  }
  return {};
}
```

每个元素查找对应元素的复杂度为$O(1)$，总体时间复杂度$O(N)$，空间复杂度$O(N)$。

Python中则可直接用内置的字典：

```python
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    nums_hash_dict = {}
    for index, first_num in enumerate(nums):
        second_num = target - first_num
        if second_num in nums_hash_dict:
            return [index, nums_hash_dict[second_num]]
        nums_hash_dict[first_num] = index
    return []
```

## 2. 两数相加

[两数相加](https://leetcode.cn/problems/add-two-numbers/)

### 描述

给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：输入：`l1 = [2,4,3], l2 = [5,6,4]`，输出：`[7,0,8]`

提示：每个链表中的节点数在范围`[1, 100]`内，`0 <= Node.val <= 9`

### 解答

单链表的定义如下：

```cpp
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
}
```

其实就是大数加法：

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* ret = new ListNode(0);
  ListNode* tmp = ret;
  int carry = 0;
  while (l1 && l2) {
    tmp->next = new ListNode((l1->val + l2->val + carry) % 10);
    carry = (l1->val + l2->val + carry) / 10;
    l1 = l1->next;
    l2 = l2->next;
    tmp = tmp->next;
  }
  while (l1) {
    tmp->next = new ListNode((l1->val + carry) % 10);
    carry = (l1->val + carry) / 10;
    l1 = l1->next;
    tmp = tmp->next;
  }
  while (l2) {
    tmp->next = new ListNode((l2->val + carry) % 10);
    carry = (l2->val + carry) / 10;
    l2 = l2->next;
    tmp = tmp->next;
  }
  if (carry) {
    tmp->next = new ListNode(carry);
  }
  return ret->next;
}
```

简洁一点的实现：

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* head = new ListNode();
  ListNode* curr = head;
  int carry = 0;
  while (l1 || l2) {
    int v1 = l1 ? l1->val : 0;
    int v2 = l2 ? l2->val : 0;
    curr->next = new ListNode((v1 + v2 + carry) % 10);
    carry = (v1 + v2 + carry) / 10;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    curr = curr->next;
  }
  if (carry) {
    curr->next = new ListNode(carry);
  }
  return head->next;
}
```

时间复杂度取决于两个链表中最长的那个，因此为$O(max(m,n))$，空间复杂度则为$O(1)$。

Python实现如下：

```python
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    head_node = ListNode()
    curr_node = head_node
    carry = 0
    while l1 != None or l2 != None:
        v1 = l1.val if l1 != None else 0
        v2 = l2.val if l2 != None else 0
        node_sum = v1 + v2 + carry
        curr_node.next = ListNode(node_sum % 10)
        carry = node_sum / 10
        l1 = l1.next if l1 != None else None
        l2 = l2.next if l2 != None else None
        curr_node = curr_node.next
    if carry:
        curr_node.next = ListNode(carry)
    return head_node.next
```

## 3. 无重复字符的最长子串

[无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

### 描述

给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

- 示例：

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是"abc"，所以其长度为3。

- 提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

### 解答

- 1. 使用集合

遍历字符串，过程中用集合保存当前无重复字符的子串，取集合元素数量的最大值即为结果：

```cpp
int lengthOfLongestSubstring(string s) {
  int ret = 0;
  int beg = 0;
  std::unordered_set<char> st;
  for (int i = 0; i < s.size(); ++i) {
    while (st.find(s[i]) != st.end()) {
      st.erase(s[beg++]); // 从集合里删除重复及其之前的字符
    }
    st.insert(s[i]);
    if (st.size() > ret) {
      ret = st.size();
    }
  }
  return ret;
}
```

Python实现如下：

```python
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    max_len = 0
    char_set = set()
    head_index = 0
    for char in s:
        while char in char_set:
            char_set.remove(s[head_index])
            head_index += 1
        char_set.add(char)
        max_len = len(char_set) if len(char_set) > max_len else max_len
    return max_len
```

- 2. 滑窗法

遍历字符串，用一个数组来记录某个字符重复出现时，需要调整到的窗口的新的起始位置，其实就是当前字符的后面的那个位置，由此：

```cpp
int lengthOfLongestSubstring(string s) {
  vector<int> vec(128, 0);
  int ret = 0;
  int i = 0;
  for (int j = 0; j < s.size(); ++j) {
    i = vec[s[j]] > i ? vec[s[j]] : i; // 取当前位置和新起始位置中的较大值作为新起始位置
    vec[s[j]] = j + 1;
    ret = j - i + 1 > ret ? j - i + 1 : ret;
  }
  return ret;
}
```

仅需遍历字符串一次，时间复杂度为$O(n)$，空间复杂度则为$O(|Σ|)$，其中$|Σ| = 128$。

Python实现如下：

```python
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    max_len = 0
    index_list = [0]*128
    beg_index = 0
    for curr_index in range(len(s)):
        beg_index = index_list[ord(s[curr_index])] if index_list[ord(s[curr_index])] > beg_index else beg_index
        index_list[ord(s[curr_index])] = curr_index + 1
        max_len = curr_index - beg_index + 1 if curr_index - beg_index + 1 > max_len else max_len
    return max_len
```

## 4. 寻找两个正序数组的中位数

[寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

### 描述

给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数 。

算法的时间复杂度应该为O(log(m+n))。

- 示例：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3]，中位数2

- 提示：
  - nums1.length == m
  - nums2.length == n
  - 0 <= m <= 1000
  - 0 <= n <= 1000
  - 1 <= m + n <= 2000
  - -10^6 <= nums1[i], nums2[i] <= 10^6

### 解答

合并数组，直到新数组的大小等于两数组大小之和的一半，之后计算中位数：

```cpp
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  double ret;
  int total = nums1.size() + nums2.size();
  int mid = total > 1 ? (total + 1) / 2 : 0;

  vector<double> vec;
  int i = 0, j = 0;
  while (vec.size() < mid + 1) {
    if (i >= nums1.size()) {
      vec.push_back(nums2[j++]);
    } else if (j >= nums2.size()) {
      vec.push_back(nums1[i++]);
    } else if (nums1[i] < nums2[j]) {
      vec.push_back(nums1[i++]);
    } else {
      vec.push_back(nums2[j++]);
    }
  }
  if (total == 1) {
    ret = vec[0];
  } else if (total % 2) {
    ret = vec[mid - 1];
  } else {
    ret = (vec[mid] + vec[mid - 1]) / 2;
  }
  return ret;
}
```

这样时间复杂度和空间复杂度都会是$O(m+n)$，不满足题目的要求。

## 5. 最长回文子串

[最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)

### 描述

给你一个字符串s，找到s中最长的回文子串。

- 示例：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

- 提示：
  - 1 <= s.length <= 1000
  - s仅由数字和英文字母组成

### 解答