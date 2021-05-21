struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
