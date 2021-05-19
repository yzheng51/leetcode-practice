#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    TreeNode left1(1);
    TreeNode right1(3);
    TreeNode root1(2, &left1, &right1);

    TreeNode left2(6);
    TreeNode right2(9);
    TreeNode root2(7, &left2, &right2);

    TreeNode root(4, &root1, &root2);

    Solution sln;
    auto res = sln.invertTree(&root);

    std::cout << res << std::endl;

    return 0;
}
