# Merge Two Sorted Lists

## 描述

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

## 解法

此题为归并排序的链表版本。比起用数组存储，链表的数据结构可以在比较循环结束后直接将还没遍历完的链表接在结果链表的后面，省去了一个一个数拼接的步骤，不仅节约了空间也加快了计算

## 代码

```cpp
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
};
```
