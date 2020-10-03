#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    ListNode l1(2), l1_n(4), l1_nn(3);
    ListNode l2(5), l2_n(6), l2_nn(4);
    Solution sln;
    l1_n.next = &l1_nn;
    l1.next = &l1_n;
    l2_n.next = &l2_nn;
    l2.next = &l2_n;
    auto res = sln.addTwoNumbers(&l1, &l2);
    std::cout << res << std::endl;
    return 0;
}