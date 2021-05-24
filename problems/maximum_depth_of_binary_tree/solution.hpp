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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        maxDepthHelper(res, 0, root);

        return res;
    }

private:
    void maxDepthHelper(int &res, int curr, TreeNode *root) {
        if (!root) {
            return;
        }
        res = std::max(res, curr + 1);
        maxDepthHelper(res, curr + 1, root->left);
        maxDepthHelper(res, curr + 1, root->right);
    }
};
