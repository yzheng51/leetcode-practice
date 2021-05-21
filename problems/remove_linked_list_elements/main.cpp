#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    ListNode *t5 = new ListNode(5);
    ListNode *t6 = new ListNode(6);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;

    Solution sln;
    sln.removeElements(t1, 6);

    while (t1) {
        std::cout << t1->val << std::endl;
        t1 = t1->next;
    }

    return 0;
}
