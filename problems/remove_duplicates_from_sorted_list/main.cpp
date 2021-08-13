#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    ListNode *third = new ListNode(2);
    ListNode *second = new ListNode(1, third);
    ListNode *first = new ListNode(1, second);

    Solution sln;
    auto res = sln.deleteDuplicates(first);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
