# Remove Duplicates from Sorted List

## 描述

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

```
输入: 1->1->2
输出: 1->2
```
```
输入: 1->1->2->3->3
输出: 1->2->3
```

## 解法

此题考点为链表的基础，以及边界条件的判断。需要新建一个指向头节点的指针，遍历时需记得判断下一个节点的状态。注意条件为排序链表，只需对邻近位置的元素进行判断即可

## 代码

```cpp
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
```
