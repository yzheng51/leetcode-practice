#include <stack>
#include <vector>

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
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> res;
        preorderTraversalHelper(res, root);

        return res;
    }

private:
    void preorderTraversalHelper(std::vector<int> &res, TreeNode *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        preorderTraversalHelper(res, root->left);
        preorderTraversalHelper(res, root->right);
    }
};

// iterative with stack
// class Solution {
// public:
//     std::vector<int> preorderTraversal(TreeNode* root) {
//         if (!root) {
//             return {};
//         }
//         std::vector<int> res;
//         std::stack<TreeNode*> stk;
//         stk.push(root);

//         while (!stk.empty()) {
//             TreeNode *curr = stk.top();
//             stk.pop();
//             res.push_back(curr->val);
//             if (curr->right) {
//                 stk.push(curr->right);
//             }
//             if (curr->left) {
//                 stk.push(curr->left);
//             }
//         }

//         return res;
//     }
// };