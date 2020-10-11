# Add Two Numbers

## 描述

给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的每个节点只能存储**一位**数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 `0` 之外，这两个数都不会以 `0` 开头。
```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 解法

主要考点是链表的基本操作和加法进位的处理。进位的方法是用一个变量 `c` 来保存两链表中对应当前元素的和，将其个位数返回并保存其十位数，将其加到两链表下一组元素的和上。这里需要注意当链表最后的两个元素加起来超过 `10` 的话需要在结果链表的最后再加上多出来的十位部分，所以 `c` 的值是否为 `0` 也要加入循环条件中

## 代码

```cpp
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int c = 0;
        while (l1 || l2 || c) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int s = (a + b + c) % 10;
            c = (a + b + c) / 10;
            p->next = new ListNode(s);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
};
```
