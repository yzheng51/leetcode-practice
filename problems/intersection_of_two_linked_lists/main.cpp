#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    ListNode *a1 = new ListNode(4);
    ListNode *a2 = new ListNode(1);
    ListNode *a3 = new ListNode(8);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);

    a1->next = a2; a2->next = a3; a3->next = a4; a4->next = a5;

    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(1);
    ListNode *b4 = new ListNode(8);
    ListNode *b5 = new ListNode(4);
    ListNode *b6 = new ListNode(5);

    b1->next = b2; b2->next = b3; b3->next = b4; b4->next = b5; b5->next = b6;

    Solution sln;
    auto res = sln.getIntersectionNode(a1, b1);
    // test method is not correct in this problem.
    // std::cout << res->val << std::endl;

    return 0;
}
