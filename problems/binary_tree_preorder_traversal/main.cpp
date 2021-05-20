#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    TreeNode left2(3);
    TreeNode root2(2, &left2, nullptr);

    TreeNode root(1, nullptr, &root2);

    Solution sln;
    auto res = sln.preorderTraversal(&root);

    for (auto element: res) {
        std::cout << element << std::endl;
    }

    return 0;
}