#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    ListNode l1_nn(4), l2_nn(4);
    ListNode l1_n(2, &l1_nn), l2_n(3, &l2_nn);
    ListNode l1(1, &l1_n), l2(1, &l2_n);
    Solution sln;
    auto res = sln.mergeTwoLists(&l1, &l2);
    while (res) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}