#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    TreeNode root1{1};
    TreeNode left1{2};
    TreeNode right1{3};

    root1.left = &left1;
    root1.right = &right1;

    TreeNode root2{1};
    TreeNode left2{2};
    TreeNode right2{3};

    root2.left = &left2;
    root2.right = &right2;

    Solution sln;
    auto res = sln.isSameTree(&root1, &root2);

    std::cout << res << std::endl;

    return 0;
}
