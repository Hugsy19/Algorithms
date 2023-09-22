// leetcode 2

#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers_1(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode();
  ListNode *cur = head;
  int carry = 0;
  while (l1 && l2) {
    cur->next = new ListNode((l1->val + l2->val + carry) % 10);
    carry = (l1->val + l2->val + carry) / 10;
    l1 = l1->next;
    l2 = l2->next;
    cur = cur->next;
  }
  while (l1) {
    cur->next = new ListNode((l1->val + carry) % 10);
    carry = (l1->val + carry) / 10;
    l1 = l1->next;
    cur = cur->next;
  }
  while (l2) {
    cur->next = new ListNode((l2->val + carry) % 10);
    carry = (l2->val + carry) / 10;
    l2 = l2->next;
    cur = cur->next;
  }
  if (carry) {
    cur->next = new ListNode(carry);
  }
  return head->next;
}

ListNode *addTwoNumbers_2(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode();
  ListNode *cur = head;
  int carry = 0, v1, v2;
  while (l1 || l2) {
    v1 = l1 ? l1->val : 0;
    v2 = l2 ? l2->val : 0;
    cur->next = new ListNode((v1 + v2 + carry) % 10);
    carry = (v1 + v2 + carry) / 10;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    cur = cur->next;
  }
  if (carry) {
    cur->next = new ListNode(carry);
  }
  return head->next;
}

int main(int argc, char *argv[]) {
  std::string input_str;
  ListNode *l1 = new ListNode();
  ListNode *l2 = new ListNode();
  ListNode *ret = nullptr;
  while (std::getline(cin, input_str)) {
    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    std::stringstream ss1(input_str);
    int num;

    while (ss1 >> num) {
      cur1->next = new ListNode(num);
      cur1 = cur1->next;
    }

    std::getline(cin, input_str);
    std::stringstream ss2(input_str);
    while (ss2 >> num) {
      cur2->next = new ListNode(num);
      cur2 = cur2->next;
    }

    ret = addTwoNumbers_1(l1->next, l2->next);

    while (ret) {
      cout << ret->val << " ";
      ret = ret->next;
    }
    cout << endl;

    ret = addTwoNumbers_2(l1->next, l2->next);

    while (ret) {
      cout << ret->val << " ";
      ret = ret->next;
    }
    cout << endl;
  }
  return 0;
}