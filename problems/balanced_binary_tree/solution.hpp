#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        if (std::abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
