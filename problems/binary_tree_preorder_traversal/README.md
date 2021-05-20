# Binary Tree Preorder Traversal

## 描述

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

```
输入：root = [1,null,2,3]
输出：[1,2,3]
```
```
输入：root = []
输出：[]
```
```
输入：root = [1]
输出：[1]
```
```
输入：root = [1,2]
输出：[1,2]
```
```
输入：root = [1,null,2]
输出：[1,2]
```

提示：

- 树中节点数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

## 解法 (递归)

递归思路解法

## 代码 (递归)

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversalHelper(res, root);

        return res;
    }

private:
    void preorderTraversalHelper(vector<int> &res, TreeNode *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        preorderTraversalHelper(res, root->left);
        preorderTraversalHelper(res, root->right);
    }
};
```

## 解法 (栈迭代)

栈迭代需要注意由于是后进先出，所以先入栈的得是右子树

## 代码 (栈迭代)

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            if (curr->right) {
                stk.push(curr->right);
            }
            if (curr->left) {
                stk.push(curr->left);
            }
        }

        return res;
    }
};
```
