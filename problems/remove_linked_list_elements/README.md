# Remove Linked List Elements

## 描述

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```
```
输入：head = [], val = 1
输出：[]
```
```
输入：head = [7,7,7,7], val = 7
输出：[]
```

提示：

- 列表中的节点在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= k <= 50`

## 解法

构造伪链表头来遍历，这里每次判断 `curr->next->val` 的时候需要注意 `curr` 和 `curr->next` 同时存在

## 代码

```cpp
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *curr = new ListNode;
        ListNode *newHead = new ListNode;
        curr->next = head;
        newHead = curr;

        while (curr && curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }

        return newHead->next;
    }
};
```
