#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL) {}
};

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