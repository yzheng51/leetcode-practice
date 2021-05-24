#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    TreeNode root1(9);

    TreeNode left2(15);
    TreeNode right2(7);
    TreeNode root2(20, &left2, &right2);

    TreeNode root(3, &root1, &root2);

    Solution sln;
    auto res = sln.maxDepth(&root);
    std::cout << res << std::endl;

    return 0;
}
